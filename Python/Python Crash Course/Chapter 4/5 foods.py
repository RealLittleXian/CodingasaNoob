# 复制列表
my_foods = ["pizza", "falafel", "carrot cake"]
friend_foods = my_foods[:]

print(my_foods)
print(friend_foods)

my_foods.append("cannoli")
friend_foods.append("ice cream")
print(my_foods)
print(friend_foods)

friend_foods = my_foods[0:2]
print(friend_foods)

friend_foods = my_foods[:-1]
print(friend_foods)

friend_foods = my_foods[-1:]
print(friend_foods)