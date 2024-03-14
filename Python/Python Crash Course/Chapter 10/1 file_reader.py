filename = 'Python\\Python Crash Course\\Chapter 10\\pi_digits.txt'
with open(filename) as file_object:
    
    for line in file_object:
        print(line.rstrip())
        
with open(filename) as file_object:
    contents = file_object.read()
    print(contents)
