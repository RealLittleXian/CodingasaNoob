import csv
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from datetime import datetime, timedelta
import json

def load_email_config():
    """加载邮件配置"""
    default_config = {
        "smtp_server": "smtp.qq.com",
        "smtp_port": 587,
        "sender_email": "your_email@qq.com",
        "sender_password": "your_password",
        "use_tls": True
    }

    try:
        with open('email_config.json', 'r', encoding='utf-8') as file:
            config = json.load(file)
            return config
    except FileNotFoundError:
        # 创建默认配置文件
        with open('email_config.json', 'w', encoding='utf-8') as file:
            json.dump(default_config, file, ensure_ascii=False, indent=2)
        print("已创建默认邮件配置文件 email_config.json，请修改其中的邮箱设置")
        return default_config

def get_user_email(username):
    """获取用户邮箱地址（模拟功能）"""
    # 在实际应用中，这里应该从数据库或配置文件中获取用户邮箱
    # 这里使用模拟数据
    user_emails = {
        "admin": "admin@example.com",
        "user1": "user1@example.com",
        "user2": "user2@example.com"
    }
    return user_emails.get(username, f"{username}@example.com")

def get_overdue_books():
    """获取即将到期的图书"""
    overdue_books = []
    current_time = datetime.now()

    try:
        with open('borrow_records.csv', 'r', encoding='utf-8') as file:
            reader = csv.reader(file)
            borrow_records = {}

            for row in reader:
                if len(row) >= 4:
                    book_id = row[0]
                    borrower = row[1]
                    date_str = row[2]
                    action = row[3]

                    try:
                        action_time = datetime.strptime(date_str, '%Y-%m-%d %H:%M:%S')

                        if action == '借出':
                            borrow_records[book_id] = {
                                'borrower': borrower,
                                'borrow_time': action_time
                            }
                        elif action == '归还' and book_id in borrow_records:
                            del borrow_records[book_id]
                    except ValueError:
                        continue

            # 检查仍未归还的图书
            for book_id, record in borrow_records.items():
                borrow_time = record['borrow_time']
                due_time = borrow_time + timedelta(days=30)  # 假设借阅期限为30天
                days_until_due = (due_time - current_time).days

                # 如果在1天内到期或已经过期
                if days_until_due <= 1:
                    overdue_books.append({
                        'book_id': book_id,
                        'borrower': record['borrower'],
                        'borrow_time': borrow_time,
                        'due_time': due_time,
                        'days_until_due': days_until_due
                    })

    except FileNotFoundError:
        print("借阅记录文件不存在")

    return overdue_books

def get_book_info(book_id):
    """获取图书信息"""
    try:
        with open('books.csv', 'r', encoding='utf-8') as file:
            reader = csv.reader(file)
            for row in reader:
                if len(row) >= 3 and row[0] == book_id:
                    return {'title': row[1], 'author': row[2]}
    except FileNotFoundError:
        pass

    return {'title': '未知图书', 'author': '未知作者'}

def send_overdue_notification(config, borrower, book_info, overdue_info):
    """发送到期提醒邮件"""
    try:
        # 创建邮件内容
        msg = MIMEMultipart()
        msg['From'] = config['sender_email']
        msg['To'] = get_user_email(borrower)
        msg['Subject'] = "图书归还提醒"

        # 邮件正文
        days_until_due = overdue_info['days_until_due']
        if days_until_due > 0:
            status_text = f"即将在 {days_until_due} 天后到期"
        elif days_until_due == 0:
            status_text = "今天到期"
        else:
            status_text = f"已逾期 {abs(days_until_due)} 天"

        body = f"""
亲爱的 {borrower}：

您好！这是来自图书管理系统的自动提醒。

您借阅的图书信息如下：
- 图书编号：{overdue_info['book_id']}
- 书名：{book_info['title']}
- 作者：{book_info['author']}
- 借阅时间：{overdue_info['borrow_time'].strftime('%Y-%m-%d %H:%M:%S')}
- 应还时间：{overdue_info['due_time'].strftime('%Y-%m-%d %H:%M:%S')}
- 状态：{status_text}

请尽快到图书馆归还图书，避免产生逾期费用。

感谢您使用图书管理系统！

此邮件为系统自动发送，请勿回复。
        """

        msg.attach(MIMEText(body, 'plain', 'utf-8'))

        # 发送邮件
        server = smtplib.SMTP(config['smtp_server'], config['smtp_port'])
        if config.get('use_tls', True):
            server.starttls()
        server.login(config['sender_email'], config['sender_password'])

        text = msg.as_string()
        server.sendmail(config['sender_email'], get_user_email(borrower), text)
        server.quit()

        print(f"成功发送提醒邮件给 {borrower} ({get_user_email(borrower)})")
        return True

    except Exception as e:
        print(f"发送邮件给 {borrower} 失败: {str(e)}")
        return False

def send_overdue_notifications():
    """发送所有到期提醒邮件"""
    print("开始检查即将到期的图书...")

    config = load_email_config()
    overdue_books = get_overdue_books()

    if not overdue_books:
        print("没有即将到期的图书")
        return

    print(f"发现 {len(overdue_books)} 本即将到期的图书")

    success_count = 0
    for overdue_info in overdue_books:
        book_info = get_book_info(overdue_info['book_id'])

        print(f"\n处理图书: {overdue_info['book_id']} - {book_info['title']}")
        print(f"借阅者: {overdue_info['borrower']}")
        print(f"到期状态: {overdue_info['days_until_due']} 天")

        if send_overdue_notification(config, overdue_info['borrower'], book_info, overdue_info):
            success_count += 1

    print(f"\n邮件发送完成！成功发送 {success_count}/{len(overdue_books)} 封邮件")

if __name__ == "__main__":
    send_overdue_notifications()