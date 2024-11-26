#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define NumofEletorate 10
#define NumofCandidate 3

typedef struct candidate
{
    char name[20];
    int count;
} CANDIDATE;
CANDIDATE stu[3] = {{"li", 0},
                    {"zhang", 0},
                    {"wang", 0}};
int main()
{
    int i, j, sign = true, invalidVote = 0;
    char name[20];
    for (i = 1; i < NumofEletorate; i++)
    {
        printf("input vote %d:", i);
        scanf("%s", name);
        strlwr(name);
        sign = true;
        for (j = 0; j < NumofCandidate; j++)
        {
            if (strcmp(name, stu[j].name) == 0)
            {
                stu[j].count++;
                sign = false;
            }
        }
        if (sign)
        {
            invalidVote++;
            sign = false;
        }
    }
    printf("election resulys:\n");
    for (i = 0; i < NumofCandidate; i++)
    {
        printf("%s\t%d\n", stu[i].name, stu[i].count);
    }
    printf("invald vote\t%d", invalidVote);
    return 0;
}