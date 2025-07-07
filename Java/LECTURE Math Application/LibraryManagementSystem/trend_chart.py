import csv
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from datetime import datetime, timedelta
from collections import defaultdict
import numpy as np

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False    # 用来正常显示负号

def generate_trend_chart():
    """生成借阅趋势图"""
    daily_borrows = defaultdict(int)
    daily_returns = defaultdict(int)

    try:
        with open('borrow_records.csv', 'r', encoding='utf-8') as file:
            reader = csv.reader(file)
            for row in reader:
                if len(row) >= 4:
                    try:
                        date_str = row[2].split(' ')[0]  # 只取日期部分
                        date_obj = datetime.strptime(date_str, '%Y-%m-%d')

                        if row[3] == '借出':
                            daily_borrows[date_obj] += 1
                        elif row[3] == '归还':
                            daily_returns[date_obj] += 1
                    except ValueError:
                        continue
    except FileNotFoundError:
        print("借阅记录文件不存在")
        return

    if not daily_borrows and not daily_returns:
        print("没有有效的借阅数据")
        return

    # 获取日期范围
    all_dates = set(daily_borrows.keys()) | set(daily_returns.keys())
    if not all_dates:
        print("没有日期数据")
        return

    min_date = min(all_dates)
    max_date = max(all_dates)

    # 生成完整的日期序列
    date_range = []
    current_date = min_date
    while current_date <= max_date:
        date_range.append(current_date)
        current_date += timedelta(days=1)

    # 准备数据
    borrow_counts = [daily_borrows[date] for date in date_range]
    return_counts = [daily_returns[date] for date in date_range]

    # 创建图表
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 8))

    # 借阅趋势图
    ax1.plot(date_range, borrow_counts, marker='o', linewidth=2, markersize=4,
             color='#1f77b4', label='借阅次数')
    ax1.set_title('图书借阅趋势图', fontsize=16, fontweight='bold')
    ax1.set_ylabel('借阅次数', fontsize=12)
    ax1.grid(True, alpha=0.3)
    ax1.legend()

    # 归还趋势图
    ax2.plot(date_range, return_counts, marker='s', linewidth=2, markersize=4,
             color='#ff7f0e', label='归还次数')
    ax2.set_title('图书归还趋势图', fontsize=16, fontweight='bold')
    ax2.set_xlabel('日期', fontsize=12)
    ax2.set_ylabel('归还次数', fontsize=12)
    ax2.grid(True, alpha=0.3)
    ax2.legend()

    # 设置日期格式
    for ax in [ax1, ax2]:
        ax.xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d'))
        ax.xaxis.set_major_locator(mdates.DayLocator(interval=max(1, len(date_range)//10)))
        plt.setp(ax.xaxis.get_majorticklabels(), rotation=45)

    plt.tight_layout()
    plt.savefig('borrow_trend_chart.png', dpi=300, bbox_inches='tight')
    plt.show()

    print("借阅趋势图已生成并保存为 borrow_trend_chart.png")

    # 生成统计摘要
    total_borrows = sum(borrow_counts)
    total_returns = sum(return_counts)
    avg_daily_borrows = np.mean(borrow_counts)
    avg_daily_returns = np.mean(return_counts)

    print(f"\n=== 借阅统计摘要 ===")
    print(f"统计时间范围: {min_date.strftime('%Y-%m-%d')} 至 {max_date.strftime('%Y-%m-%d')}")
    print(f"总借阅次数: {total_borrows}")
    print(f"总归还次数: {total_returns}")
    print(f"日均借阅次数: {avg_daily_borrows:.2f}")
    print(f"日均归还次数: {avg_daily_returns:.2f}")

if __name__ == "__main__":
    generate_trend_chart()