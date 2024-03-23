import math

n = int(input())

S = 0
for i in range(1, n+1):
    factorial = math.factorial(i)
    S += factorial

print(S)