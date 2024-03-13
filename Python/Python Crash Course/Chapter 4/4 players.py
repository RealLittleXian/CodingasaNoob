# slice 切片
players = ["charles", "martina", "michael", "florence", "eli"]
print(players[0:3])
print(players[:4])
print(players[2:])
print(players[-3:])

for player in players[0:3]:
    print(player.title())
