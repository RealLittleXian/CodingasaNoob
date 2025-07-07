import csv
import json
from collections import defaultdict, Counter
from datetime import datetime

def generate_borrow_ranking():
    """生成借阅排行榜Top10"""
    book_borrow_count = Counter()
    user_borrow_count = Counter()

    try:
        with open('borrow_records.csv', 'r', encoding='utf-8') as file:
            reader = csv.reader(file)
            for row in reader:
                if len(row) >= 4 and row[3] == '借出':
                    book_id = row[0]
                    user = row[1]
                    book_borrow_count[book_id] += 1
                    user_borrow_count[user] += 1
    except FileNotFoundError:
        print("借阅记录文件不存在")
        return

    # 获取图书信息
    book_info = {}
    try:
        with open('books.csv', 'r', encoding='utf-8') as file:
            reader = csv.reader(file)
            for row in reader:
                if len(row) >= 3:
                    book_info[row[0]] = {'title': row[1], 'author': row[2]}
    except FileNotFoundError:
        print("图书信息文件不存在")
        return

    # 生成图书借阅排行榜
    print("=== 图书借阅排行榜 Top10 ===")
    book_ranking = []
    for book_id, count in book_borrow_count.most_common(10):
        book_data = book_info.get(book_id, {'title': '未知', 'author': '未知'})
        ranking_item = {
            'book_id': book_id,
            'title': book_data['title'],
            'author': book_data['author'],
            'borrow_count': count
        }
        book_ranking.append(ranking_item)
        print(f"{len(book_ranking)}. {book_data['title']} ({book_data['author']}) - 借阅次数: {count}")

    # 生成用户借阅排行榜
    print("\n=== 用户借阅排行榜 Top10 ===")
    user_ranking = []
    for user, count in user_borrow_count.most_common(10):
        ranking_item = {
            'user': user,
            'borrow_count': count
        }
        user_ranking.append(ranking_item)
        print(f"{len(user_ranking)}. {user} - 借阅次数: {count}")

    # 保存到JSON文件
    ranking_data = {
        'book_ranking': book_ranking,
        'user_ranking': user_ranking,
        'generated_time': datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    }

    with open('borrow_ranking.json', 'w', encoding='utf-8') as file:
        json.dump(ranking_data, file, ensure_ascii=False, indent=2)

    print(f"\n排行榜数据已保存到 borrow_ranking.json")

if __name__ == "__main__":
    generate_borrow_ranking()