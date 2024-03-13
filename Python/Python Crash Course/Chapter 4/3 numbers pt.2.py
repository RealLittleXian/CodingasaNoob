digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print(min(digits), max(digits), sum(digits))


squares = []
for value in range(1,11):
    squares.append(value**2)
print(squares)

squares = [value**2 for value in range(1,11)] # list comprehension 列表解析
print(squares)