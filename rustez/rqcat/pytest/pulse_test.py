# from rqcat.pulse import BasePulse
import rqcat
import sys
# 优化rust导包， 直接采用下述的导包方式无法导入。
sys.modules["rqcat.pulse"] = rqcat.pulse

from rqcat.pulse import BasePulse, PulseComponent

print(rqcat.version())

p1 = BasePulse()
p2 = PulseComponent(10, "x")
print(p1.pulse(), p2.type_)

# p1 = BasePulse()

# print(p1.pulse())