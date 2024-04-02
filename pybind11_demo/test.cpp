#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include <vector>

namespace py = pybind11;

// 定义 Pulse 结构体
struct Pulse
{
    double amp;
    double freq;
    int time;
    std::string type_;

    // 构造函数
    Pulse(double amp, double freq, int time, std::string type_)
        : amp(amp), freq(freq), time(time), type_(type_) {}

    // 方法：将另一个 Pulse 对象添加到当前对象的列表中
    void add_pulse(const Pulse &other_pulse)
    {
        _pulse.push_back(other_pulse);
    }

    // 方法：获取脉冲列表
    std::vector<Pulse> get_pulses() const
    {
        return _pulse;
    }

private:
    std::vector<Pulse> _pulse;
};

int add(int a, int b)
{
    return a + b;
}

PYBIND11_MODULE(pyqc, m)
{
    m.doc() = "pybind11 test";
    m.def("add", &add, "a add func");
    py::class_<Pulse>(m, "Pulse")
        .def(py::init<double, double, int, std::string>(),
             py::arg("amp"), py::arg("freq"), py::arg("time"), py::arg("type_"),
             "Construct a Pulse object")
        .def_readonly("amp", &Pulse::amp, "Amplitude property")
        .def_readonly("freq", &Pulse::freq, "Frequency property")
        .def_readonly("time", &Pulse::time, "Time property")
        .def_readonly("type", &Pulse::type_, "Type property")
        .def("add_pulse", &Pulse::add_pulse,
             py::arg("other_pulse"),
             "Add another Pulse object to the list")
        .def("get_pulses", &Pulse::get_pulses,
             "Get the list of pulses");
}