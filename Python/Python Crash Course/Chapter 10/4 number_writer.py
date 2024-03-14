import json
numbers = [2, 3, 5, 7, 11, 13]
filename = 'Python\\Python Crash Course\\Chapter 10\\numbers.json'
with open(filename, 'w') as f_obj:
    json.dump(numbers, f_obj)