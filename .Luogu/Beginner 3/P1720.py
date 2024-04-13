s1=s2=1
s3=0
n=int(input())
for i in range(1,n-1):
    s3=s1+s2
    s1=s2
    s2=s3
print(f"{s3}.00")