import json
filename = 'Python\\Python Crash Course\\Chapter 10\\numbers.json'
with open(filename) as file_obj:
    numbers = json.load(file_obj)
print(numbers)