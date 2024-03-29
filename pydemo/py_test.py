import myextension

print(myextension.add(10, 20))

p1 = myextension.Point(10, 20)
p2 = myextension.Point(30, 40)
p3 = p1 + p2
print(p3.x, p3.y)
