#include <stdio.h>

int DayofYear(int year, int month, int day){
    int daysInMonth, Dayofyear=0;
    for(int m=1;m<=month;m++){
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            daysInMonth = 30;
        } else if (m == 2) {
            int isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            daysInMonth = (isLeapYear ? 29 : 28);
        } else {
            daysInMonth = 31;
        }
        if (m<month){
            Dayofyear+=daysInMonth;
        }
        else{
            Dayofyear+=day;
        }
    }
    return Dayofyear;
}
void MonthDay(int year, int yearDay, int *pMonth, int *pDay){
    int daysInMonth, month, day, Dayofyear=0;
    for(int m=1;m<=12;m++){
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            daysInMonth = 30;
        } else if (m == 2) {
            int isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
            daysInMonth = (isLeapYear ? 29 : 28);
        } else {
            daysInMonth = 31;
        }
        if (yearDay>daysInMonth)
        {
            yearDay -= daysInMonth;
        }
        else if (yearDay==daysInMonth)
        {
            day=yearDay;
            month = m;
            break;
        }
        
        else
        {
            day=yearDay;
            month = m+1;
            break;
        }
    }
        *pMonth=month;
        *pDay=day;
}

int main(){
    printf("1. year/ month/ day -> yearDay\n"
           "2. yearDay -> year/ month/ day\n"
           "3. Exit\n"
           "Please enter your choice:");
           int choice;
           scanf("%d",&choice);
            int year, month, day, yearDay;
    switch (choice)
    {
    case 1:
        printf("enter year:");
        scanf(" %d",&year);
        printf("enter month:");
        scanf(" %d",&month);        
        printf("enter day:");
        scanf(" %d",&day);
        printf("%d",DayofYear(year, month, day));
        break;
    case 2:
        printf("enter year:");
        scanf(" %d",&year);
        printf("enter day of year:");
        scanf(" %d",&yearDay);
        MonthDay(year, yearDay,&month, &day);
        printf("%d/ %d/ %d",year, month, day);
        break;
    case 3:
        exit(0);
    default:
        break;
    }
    return 0;
}