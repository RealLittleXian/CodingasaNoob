apple = sorted(map(int, input().split()))
height = int(input()) + 30
n = 0
for i in range(10):
    if height >= apple[i]:
        n += 1
print(n)
