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
