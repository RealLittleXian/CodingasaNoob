A, B, C = sorted(map(int, input().split()))
letter = input()
for i in range(3):
    if letter[i] == "A":
        print(A,end=" ")
    elif letter[i] == "B":
        print(B,end=" ")
    elif letter[i] == "C":
        print(C,end=" ")