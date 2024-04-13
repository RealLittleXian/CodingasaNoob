def check_prize(winning_numbers, ticket_numbers):
    count = 0
    for num in ticket_numbers:
        if num in winning_numbers:
            count += 1
    return count

n = int(input())
winning_numbers = list(map(int, input().split()))

prizes = [0] * 7

for _ in range(n):
    ticket_numbers = list(map(int, input().split()))
    matched_nums = check_prize(winning_numbers, ticket_numbers)

    if matched_nums == 7:
        prizes[0] += 1
    elif matched_nums == 6:
        prizes[1] += 1
    elif matched_nums == 5:
        prizes[2] += 1
    elif matched_nums == 4:
        prizes[3] += 1
    elif matched_nums == 3:
        prizes[4] += 1
    elif matched_nums == 2:
        prizes[5] += 1
    elif matched_nums == 1:
        prizes[6] += 1

for prize_count in prizes:
    print(prize_count, end=" ")