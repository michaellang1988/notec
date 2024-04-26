from multiprocessing import Process, Pool
from concurrent.futures import ProcessPoolExecutor
import zmq
import json
import time
base_dict = {
    "t2" : 10000
}

def calculator(data):
    res = ((data["t1"] + base_dict["t2"])/ 989) ** 2
    # print(res)
    return res


class CalPro(Process):
    def __init__(
        self,
        link_addr: str,
        worker_id: bytes,
    ) -> None:
        super().__init__(daemon=True)
        self.worker_id: bytes = worker_id
        self.link_addr = link_addr
        self._ctx = None
        self.sock = None

    def _init_sock(
        self,
    ):
        """
        init calculator socket.
        """
        self._ctx = zmq.Context.instance()
        self.sock: zmq.Socket = self._ctx.socket(zmq.DEALER)
        self.sock.setsockopt(zmq.IDENTITY, self.worker_id)
        self.sock.connect(self.link_addr)

    
    def run(self):
        self._init_sock()
        while True:
            res = self.sock.recv()
            data = json.loads(res)
            calculator(data)
            # print(data["t1"] + base_dict["t2"])


def create_cal_pro(link_addr, num = 5) ->list[str]:
    work_id_list = []
    for x in range(num):
        work_id = f"w_{x}".encode(encoding="utf-8")
        CalPro(link_addr, work_id).start()
        work_id_list.append(work_id)
    
    return work_id_list

def time_warpper(name):
    def name_warpper(func):
        def warpper(*args, **kwargs):
            t1 = time.time_ns()
            res = func(*args, **kwargs)
            t2 = time.time_ns()
            print(f"{name:^10} use time:", t2 -t1)
            return res
        
        return warpper
    return name_warpper

@time_warpper(name="zmq")
def test():
    link_addr = "ipc://test_123"
    work_id_list = create_cal_pro(link_addr=link_addr)
    ctx = zmq.Context.instance()
    sock = ctx.socket(zmq.ROUTER)
    sock.bind(link_addr)
    for i in range(10):
        base_dict["t2"] = i * 10000
        for x in range(1000):

            data = {
                "t1": x
            }
            sock.send_multipart([work_id_list[x % 5], json.dumps(data).encode()])
@time_warpper(name="conpro_1")
def test2():
    with ProcessPoolExecutor(5) as f:
        for i in range(10):
            base_dict["t2"] = i* 10000
            f.map(calculator, [{"t1": x} for x in range(1000)])


@time_warpper(name="conpro_n")
def test3():
    for i in range(10):
        base_dict["t2"] = i* 10000
        with ProcessPoolExecutor(5) as f:
            f.map(calculator, [{"t1": x} for x in range(1000)])

@time_warpper(name="pool")
def test4():
    pro_pool = Pool(5)
    for i in range(10):
        base_dict["t2"] = i* 10000
        pro_pool.map(calculator, [{"t1": x} for x in range(1000)])
        
test4()
test()
test2()
test3()