#include <stdio.h>
#include <string.h>
#include <time.h>
#include<stdlib.h>
typedef struct card
{
    char suit[10];
    char face[10];
} CARD;
void deal(CARD *pcard);
void shuffle(CARD *pcard);
void fill(CARD pcard[], const char *pface[],const char *psuit[]);
int main()
{
    const char *suit[] = {"spade", "heart", "club", "diamond"};
    const char *face[] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    CARD cards[52];
    srand(time(NULL));
    fill(cards, face,suit);
    shuffle(cards);
    deal(cards);
    return 0;
}

void deal(CARD pcard[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        printf("%s\t%s\t%c", pcard[i].suit, pcard[i].face, i % 2 == 0 ? '\n' : '\t');
    }
    printf("\n");
}

void shuffle(CARD *pcard)
{
    int i, j;
    CARD temp;
    for (i = 0; i < 52; i++)
    {
        j = rand() % 52;
        temp = pcard[i];
        pcard[i] = pcard[j];
        pcard[j] = temp;
    }
}
void fill(CARD pcard[], const char *pface[],const char *psuit[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        strcpy(pcard[i].suit, psuit[i / 13]);
        strcpy(pcard[i].suit, pface[i % 13]);
    }
}