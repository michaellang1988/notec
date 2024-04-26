from marust import sum_as_string, SimplePulse


print(sum_as_string(10, 20))
print(SimplePulse.__name__)

t = SimplePulse(5.3, 4.1)
t2 = SimplePulse(5, 4)
# t.time11 = 20

print(t.time,t.test(), str(t))
t3 = t + t2
print(t3, t3 is t)