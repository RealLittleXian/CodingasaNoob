/*
4001 特殊星期天

实验内容
已知1900年1月1日是星期一。请编写程序计算在1901年1月1日至某年12月31日期间，
共有多少个星期日落在每月的第一天上。
输入：
一行，正整数y（y>=1901），表示年份
输出：
一行，1901年1月1日至y年12月31日期间，星期日落在每月第一天的天数
输入样例：
1901
输出样例：
2
*/
#include <stdio.h>

int countFirstSundays(int year) {
    int dayOfWeek = 1;  // 当前日期是星期几，初始为星期一
    int firstSundays = 0;  // 星期日在每月第一天的次数

    for (int y = 1901; y <= year; y++) {
        for (int m = 1; m <= 12; m++) {
            if (dayOfWeek == 1) {
                firstSundays++;
            }

            int daysInMonth;
            if (m == 4 || m == 6 || m == 9 || m == 11) {
                daysInMonth = 30;
            } else if (m == 2) {
                int isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
                daysInMonth = (isLeapYear ? 29 : 28);
            } else {
                daysInMonth = 31;
            }

            dayOfWeek = (dayOfWeek + daysInMonth) % 7;
        }
    }

    return firstSundays;
}

int main() {
    int year;
    scanf("%d", &year);
    printf("%d\n", countFirstSundays(year));

    return 0;
}
