isbn = input()

isbn_digits = isbn.replace("-", "")

total = 0
for i in range(9):
    total += int(isbn_digits[i]) * (i+1)

ident_code = total % 11
if ident_code == 10:
    correct_ident_code = "X"
else:
    correct_ident_code = str(ident_code)

if correct_ident_code == isbn[-1]:
    print("Right")
else:
    correct_isbn = isbn[:-1] + correct_ident_code
    print(correct_isbn)