w, d = map(int, input().split())
x=0
for i in range(d):
    if (w <= 5 and w>=1):
        x+=250
        
    if (w==7):
        w=1
    elif (w!=7):
        w+=1
print(x)