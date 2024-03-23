a, b, c = sorted(map(int, input().split()))

if a + b <= c:
    print("Not triangle")
else:
    if a**2 + b**2 == c**2:
        print("Right triangle")
    if a**2 + b**2 > c**2:
        print("Acute triangle")
    if a**2 + b**2 < c**2:
        print("Obtuse triangle")
    if a == b or a == c or b == c:
        print("Isosceles triangle")
    if a == b == c:
        print("Equilateral triangle")