motorcycles=['honda','yamaha','suzuki','ducati']
print(motorcycles)

too_expensive='ducati'
motorcycles.remove(too_expensive)   # list.remove()
print(motorcycles)
print(f"\nA {too_expensive.title()} is too expensive for me.")

print(motorcycles[-1])  # list[-1]