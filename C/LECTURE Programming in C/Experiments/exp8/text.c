#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_ID_LENGTH 6
#define MAX_NAME_LENGTH 11

typedef struct
{
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    int income;
    int expense;
} Record;

// 从用户获取整数输入的函数
int getInt(void)
{
    int input;
    char ch;
    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" 不是整数。\n"
               "请重新输入整数值：");
    }
    return input;
}

// 从用户获取字符串输入的函数
void getString(char *str, int maxLength)
{
    char temp[maxLength];
    int validInput = 0;

    while (!validInput)
    {
        scanf("%s", temp);

        // 检查字符串长度是否超过最大长度
        if (strlen(temp) > maxLength)
        {
            printf("无效输入。最大长度为 %d。请重试：", maxLength);
            continue;
        }
        validInput = 1;
    }

    strcpy(str, temp);
}

// 输入记录的函数
void inputRecord(Record *records, int *pnumUsers)
{
    int sign = 0;
    while (sign == 0)
    {
        printf("\n请输入用户数量（最多 10 个）：");
        *pnumUsers = getInt();

        if (*pnumUsers <= 0 || *pnumUsers > MAX_USERS)
        {
            printf("\n无效的用户数量。\n");
        }
        else
        {
            sign = 1;
        }
    }
    printf("\n输入记录：\n");
    for (int i = 0; i < *pnumUsers; i++)
    {
        printf("用户 %d：\n", i + 1);
        int Tid;
        printf("ID：");
        fflush(stdin);
        fgets(records[i].id, sizeof(records[i].id), stdin);
        if (sscanf(records[i].id, "%d", &Tid) != 1)
        {
            printf("无效输入。请重试。\n");
            i--;
            continue;
        }
        if (Tid < 10000 || Tid > 99999)
        {
            printf("ID 应为 5 位数字。\n");
            i--;
            continue;
        }
        printf("姓名：");
        getString(records[i].name, MAX_NAME_LENGTH);

        printf("收入：");
        records[i].income = getInt();

        printf("支出：");
        records[i].expense = getInt();

        printf("\n");
    }
}

// 对记录进行排序的函数
int sortRecords(Record *records, int *pnumUsers)
{
    if (*pnumUsers == 0)
    {
        return 1;
    }

    for (int i = 0; i < *pnumUsers - 1; i++)
    {
        for (int j = 0; j < *pnumUsers - i - 1; j++)
        {
            if (strcmp(records[j].name, records[j + 1].name) < 0)
            {
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
    return 0;
}

// 根据用户名搜索记录的函数
int searchRecord(Record *records, int *pnumUsers, char *name)
{
    if (*pnumUsers == 0)
    {
        printf("警告：请先输入记录。\n");
        return 1;
    }
    printf("按用户名搜索记录：\n");

    int found = 0;
    for (int i = 0; i < *pnumUsers; i++)
    {
        if (strcmp(records[i].name, name) == 0)
        {
            found = 1;
            printf("ID\t 姓名         收入     支出\n");
            printf("%s\t %-12s %-10d %-10d\n", records[i].id, records[i].name, records[i].income, records[i].expense);
        }
    }
    if (!found)
    {
        printf("未找到给定用户名的记录。\n");
    }
    return 0;
}

// 计算并列出人均收入和支出的函数
int calculatePerCapita(Record *records, int *pnumUsers)
{
    if (*pnumUsers == 0)
    {
        printf("警告：请先输入记录。\n");
        return 1;
    }
    // 计算总收入和总支出
    int totalIncome = 0;
    int totalExpense = 0;
    for (int i = 0; i < *pnumUsers; i++)
    {
        totalIncome += records[i].income;
        totalExpense += records[i].expense;
    }

    // 计算人均收入和支出
    float perCapitaIncome = (float)totalIncome / *pnumUsers;
    float perCapitaExpense = (float)totalExpense / *pnumUsers;

    // 显示人均收入和支出
    printf("人均收入：%0.2f\n", perCapitaIncome);
    printf("人均支出：%0.2f\n", perCapitaExpense);

    return 0;
}

int main()
{
    Record records[MAX_USERS];  // 存储用户记录的数组
    int numUsers = 0;           // 用户数量

    // 输入记录
    inputRecord(records, &numUsers);

    // 对记录进行排序
    sortRecords(records, &numUsers);

    // 搜索记录
    char searchName[MAX_NAME_LENGTH];
    printf("\n请输入要搜索的用户名：");
    getString(searchName, MAX_NAME_LENGTH);
    searchRecord(records, &numUsers, searchName);

    // 计算人均收入和支出
    calculatePerCapita(records, &numUsers);

    return 0;
}