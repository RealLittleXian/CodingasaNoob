import math

x1, y1 = map(float, input().split())
x2, y2 = map(float, input().split())
x3, y3 = map(float, input().split())

def distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

side1 = distance(x1, y1, x2, y2)
side2 = distance(x2, y2, x3, y3)
side3 = distance(x3, y3, x1, y1)

perimeter = side1 + side2 + side3

print('%.2f' % perimeter)