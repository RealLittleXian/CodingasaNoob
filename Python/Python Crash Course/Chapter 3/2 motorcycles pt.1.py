motorcycles=['honda','yamaha','suzuki']
print(motorcycles)

motorcycles[0]='ducati' # list[]=
print(motorcycles)

motorcycles[0]='honda'
motorcycles.append('ducati')    # list.append()
print(motorcycles)

motorcycles.insert(0,'ducati')  # list.insert()
print(motorcycles)

del motorcycles[0]  # del
print(motorcycles)

popped_motorcycle=motorcycles.pop() # list.pop()
print(motorcycles)
print(popped_motorcycle)
print(f"The motorcycle I popped was {popped_motorcycle.capitalize()}.")

popped_motorcycle=motorcycles.pop(0)
print(motorcycles)
print(popped_motorcycle)