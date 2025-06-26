#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct {
    ElemType *elem;    // 空间基地址，空间存放纸牌正反面状态值,正/反分别用1/0表示
    int length;        // 存放纸牌数
    int listsize;      // 存放空间的容量
} SqList;

void InitList(SqList *L, int size) {
    L->elem = (ElemType *)malloc(size * sizeof(ElemType));
    if (L->elem == NULL) {
        exit(EXIT_FAILURE);
    }
    L->length = size;
    L->listsize = size;

    for (int i = 0; i < size; i++) {
        L->elem[i] = 1;
    }
}

void FlipCards(SqList *L) {
    for (int step = 2; step <= L->length; step++) {
        for (int i = step - 1; i < L->length; i += step) {
            L->elem[i] = !L->elem[i]; 
        }
    }
}

void PrintFaceUpCards(SqList *L) {
    int count = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == 1) { 
            printf("%d ", i + 1);
            count++;
        }
    }
    printf("\n%d", count);
}

void FreeList(SqList *L) {
    free(L->elem);
    L->elem = NULL;
}

int main() {
    SqList cards;
    int n;
    scanf("%d",&n);

    InitList(&cards, n);
    FlipCards(&cards); 
    PrintFaceUpCards(&cards); 
    FreeList(&cards);

    return 0;
}