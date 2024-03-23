total = int(input())

if total <= 150:
    cost = total * 0.4463
elif total <= 400:
    cost = 150 * 0.4463 + (total - 150) * 0.4663
else:
    cost = 150 * 0.4463 + 250 * 0.4663 + (total - 400) * 0.5663

print("{:.1f}".format(cost))