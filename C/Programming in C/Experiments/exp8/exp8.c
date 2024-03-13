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
        printf(" is not an integer.\n"
               "please enter an integer value.");
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
            printf("Invalid input. Maximum length is %d. Please try again: ", maxLength);
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
        printf("\nPlease enter the number of users (up to 10): ");
        *pnumUsers = getInt();

        if (*pnumUsers <= 0 || *pnumUsers > MAX_USERS)
        {
            printf("\nInvalid number of users.\n");
        }
        else
        {
            sign = 1;
        }
    }
    printf("\nInput record:\n\n(Tips: You can paste data at a time.)\n");
    for (int i = 0; i < *pnumUsers; i++)
    {
        printf("User %d:\n", i + 1);
        int Tid;
        printf("ID: ");
        fflush(stdin);
        fgets(records[i].id, sizeof(records[i].id), stdin);
        if (sscanf(records[i].id, "%d", &Tid) != 1)
        {
            printf("Invalid Input. retry.\n");
            i--;
            continue;
        }
        if (Tid < 10000 || Tid > 99999)
        {
            printf("ID should be a 5-digit number.\n");
            i--;
            continue;
        }
        printf("Name: ");
        getString(records[i].name, MAX_NAME_LENGTH);

        printf("Income: ");
        records[i].income = getInt();

        printf("Expense: ");
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
        printf("Warning: Input Records first.\n");
        return 1;
    }
    printf("Search records by user name:\n");

    int found = 0;
    for (int i = 0; i < *pnumUsers; i++)
    {
        if (strcmp(records[i].name, name) == 0)
        {
            found = 1;
            printf("ID\t Name         Income     Expense\n");
            printf("%s\t %-12s %-10d %-10d\n", records[i].id, records[i].name, records[i].income, records[i].expense);
        }
    }
    if (!found)
    {
        printf("No records found for the given user name.\n");
    }
    return 0;
}

// 计算并列出人均收入和支出的函数
int calculatePerCapita(Record *records, int *pnumUsers)
{
    if (*pnumUsers == 0)
    {
        printf("Warning: Input Records first.\n");
        return 1;
    }
    // 计算总收入和总支出
    printf("Calculate and list per capita income and expenses:\n");
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
    printf("Per capita income: %.2f\n", perCapitaIncome);
    printf("Per capita expense: %.2f\n", perCapitaExpense);
    printf("\n");
    return 0;
}

// 显示所有高于平均支出的用户的函数
int listAboveAverageExpense(Record *records, int *pnumUsers)
{
    if (*pnumUsers == 0)
    {
        printf("Warning: Input Records first.\n");
        return 1;
    }
    printf("List records which have more expenses than per capita expenses:\n");
    int totalExpense = 0;
    for (int i = 0; i < *pnumUsers; i++)
    {
        totalExpense += records[i].expense;
    }
    float perCapitaExpense = (float)totalExpense / *pnumUsers;
    printf("ID\t Name         Income     Expense\n");
    for (int i = 0; i < *pnumUsers; i++)
    {
        if (records[i].expense > perCapitaExpense)
        {
            printf("%s\t %-12s %-10d %-10d\n", records[i].id, records[i].name, records[i].income, records[i].expense);
        }
    }
    return 0;
}

// 显示所有用户的函数
int listAllRecords(Record *records, int *pnumUsers)
{
    if (*pnumUsers == 0)
    {
        printf("Warning: Input Records first.\n");
        return 1;
    }
    printf("List all records:\n");
    printf("ID\t Name         Income     Expense\n");
    for (int i = 0; i < *pnumUsers; i++)
    {
        printf("%s\t %-12s %-10d %-10d\n", records[i].id, records[i].name, records[i].income, records[i].expense);
    }
    return 0;
}

int main()
{
    Record records[MAX_USERS], originalRecords[MAX_USERS]; // 存储用户记录的数组
    int numUsers = 0;                                      // 用户数量
    int *pnumUsers = &numUsers;

    int choice;
    char searchName[MAX_NAME_LENGTH]; // 搜索记录

    do
    {
        printf("----------------------------------------------------------\n");
        printf("1. Input record\n");
        printf("2. Sort and list records in reverse order by user name\n");
        printf("3. Search records by user name\n");
        printf("4. Calculate and list per capita income and expenses\n");
        printf("5. List records which have more expenses than per capita expenses\n");
        printf("6. List all records\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");
        choice = getInt();

        printf("----------------------------------------------------------\n");
        switch (choice)
        {
        case 1:
            inputRecord(records, &numUsers);
            for (int i = 0; i < MAX_USERS; i++)
            {
                originalRecords[i] = records[i];
            }
            break;
        case 2:
            sortRecords(records, &numUsers);
            listAllRecords(records, &numUsers);
            break;
        case 3:
            printf("Enter the user name to search: ");
            scanf("%s", searchName);
            searchRecord(records, &numUsers, searchName);
            break;
        case 4:
            calculatePerCapita(records, &numUsers);
            break;
        case 5:
            listAboveAverageExpense(records, &numUsers);
            break;
        case 6:
            listAllRecords(originalRecords, &numUsers);
            break;
        case 0:
            printf("Exit the program successfully.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}