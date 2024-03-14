from name_function import get_formatted_name

print("Enter 'q' at any time to quit.\n")
while True:
    print("Please tell me your name:")
    f_name = input("First name: ")
    if f_name == 'q':
        break
    l_name = input("Last name: ")
    if l_name == 'q':
        break

    formatted_name = get_formatted_name(f_name, l_name)
    print(f"Hello, {formatted_name}!\n")