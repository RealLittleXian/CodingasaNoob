#include <stdio.h>
#include <stdlib.h>
typedef struct date
{
    int year;
    int month;
    int day;

} DATE;
typedef struct student
{
    long stuID;
    char stuName[20];
    char stuSex;
    DATE birthday;
    int score[4];
} STUDENT;
int main()
{
    FILE *fp;
    int i, j, sum[30];
    STUDENT stu[30] = {{10031021, "Wang Gang", 'M', {1991, 5, 19}, {72, 83, 90, 82}},
                       {10031022, "Li Xiaoming", 'M', {1992, 8, 20}, {88, 92, 78, 78}},
                       {10031023, "Wang Lihong", 'F', {1991, 9, 19}, {98, 72, 89, 66}},
                       {10031024, "Chen Lili", 'F', {1992, 3, 22}, {87, 95, 78, 90}}
                       };
    if ((fp = fopen("score.txt", "w")) == NULL)
    {
        printf("open score.txt failed.");
        exit(0);
    }
    for (i = 0; i < 4; i++)
    {
        sum[i] = 0;
        for (j = 0; j < 4; j++) 
        {
            sum[i] = sum[i] + stu[i].score[j];
        }
        fprintf(fp, "%10ld%8s%3c%6d/%02d/%02d%4d%4d%4d%4d%6.1f\n",
                stu[i].stuID,
                stu[i].stuName,
                stu[i].stuSex,
                stu[i].birthday.year,
                stu[i].birthday.month,
                stu[i].birthday.day,
                stu[i].score[0],
                stu[i].score[1],
                stu[i].score[2],
                stu[i].score[3],
                sum[i] / 4.0);
    }
    fclose(fp);
    return 0;
}