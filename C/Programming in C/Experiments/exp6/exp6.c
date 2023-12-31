#include <stdio.h>

#define MAX_NUM 40
void inputStudents(int n, char num[MAX_NUM][12], int score[MAX_NUM][3]);
void calculateResult(int n, char num[MAX_NUM][12], int score[MAX_NUM][3]);

int main()
{
    int n;
    char studentID[MAX_NUM][12]; // 学号
    int scores[MAX_NUM][3];      // 学生成绩

    printf("Input the total number of the students(n<40):\n");
    scanf("%d", &n);
    inputStudents(n, studentID, scores);
    calculateResult(n, studentID, scores);

    return 0;
}

// 接收输入的学生信息
void inputStudents(int n, char studentID[MAX_NUM][12], int scores[MAX_NUM][3])
{
    int i, j;

    printf("Input student’s ID and score as: MT  EN  PH:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%12s", studentID[i]);
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &scores[i][j]);
        }
    }
}

// 利用二维数组的信息进行数值运算，并输出
void calculateResult(int n, char studentID[MAX_NUM][12], int scores[MAX_NUM][3])
{
    int i, j;
    printf("Counting Result:\n");
    printf("Student’s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");

    int totalSum = 0;
    float totalAver = 0.0;
    int courseSum[3] = {0};
    float courseAver[3] = {0.0};

    for (i = 0; i < n; i++)
    {
        printf("%12s\t", studentID[i]);
        int sum = 0;
        for (j = 0; j < 3; j++)
        {
            printf("%4d\t", scores[i][j]);
            sum += scores[i][j];
            courseSum[j] += scores[i][j];
        }
        float aver = (float)sum / 3;
        totalSum += sum;
        totalAver += aver;
        printf("%4d\t%5.1f\n", sum, aver);
    }

    printf("SumofCourse \t");
    for (j = 0; j < 3; j++)
    {
        printf("%4d\t", courseSum[j]);
    }

    printf("\nAverofCourse\t");
    for (j = 0; j < 3; j++)
    {
        courseAver[j] = (float)courseSum[j] / n;
        printf("%4.1f\t", courseAver[j]);
    }
}
