n = int(input())
min_cost = float('inf')

for _ in range(3):
    quantity, price = map(int, input().split())
    packs_needed = n // quantity
    if n % quantity != 0:
        packs_needed += 1
    cost = packs_needed * price
    min_cost = min(min_cost, cost)

print(min_cost)