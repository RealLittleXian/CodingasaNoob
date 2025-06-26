#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义图书结构体
typedef struct {
    char bookId[20];
    char title[100];
    char author[50];
    int stock;
} Book;

// 定义链表节点
typedef struct Node {
    Book book;
    struct Node *next;
} Node;

// 创建新节点
Node* CreateNode(Book book) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->book = book;
    newNode->next = NULL;
    return newNode;
}

// 在链表尾部插入图书信息
void InsertBook(Node **head, Book book) {
    Node *newNode = CreateNode(book);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 根据书号删除图书信息
int DeleteBook(Node **head, char bookId[]) {
    Node *temp = *head, *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->book.bookId, bookId) == 0) {
            if (prev == NULL) { // 删除头节点
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            printf("图书%s删除成功！\n", bookId);
            free(temp);
            return 0;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("未找到书号为%s的图书，无法删除！\n", bookId);
    return 0;
}

// 根据书号修改图书库存数量
int UpdateStock(Node *head, char bookId[], int newStock) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->book.bookId, bookId) == 0) {
            temp->book.stock = newStock;
            printf("图书%s的库存数量已修改为%d！\n", bookId, newStock);
            return 1;
        }
        temp = temp->next;
    }
    printf("未找到书号为%s的图书，无法修改库存！\n", bookId);
    return 0; 
}

// 根据书号查找图书信息
Node* FindBook(Node *head, char bookId[]) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->book.bookId, bookId) == 0) {
            printf("查找的图书信息：\n");
            printf("书号：%s,书名：%s,作者：%s,库存：%d\n",
                   temp->book.bookId, temp->book.title, temp->book.author, temp->book.stock);
            return 0; 
        }
        temp = temp->next;
    }
    printf("未找到书号为%s的图书\n", bookId);
}

// 遍历并输出所有图书信息
void TraverseList(Node *head) {
    printf("图书列表：\n");
    Node *temp = head;
    while (temp != NULL) {
        printf("书号：%s,书名：%s,作者：%s,库存：%d\n",
               temp->book.bookId, temp->book.title, temp->book.author, temp->book.stock);
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;
    char bookId_find[4], bookId_update[4], bookId_delete[4];
    int num;
    scanf("%s", bookId_find);
    scanf("%s", bookId_update);
    scanf("%d", &num);
    scanf("%s", bookId_delete);
    Book book1 = {"001", "C程序设计", "谭浩强", 10};
    Book book2 = {"002", "数据结构", "严蔚敏", 5};
    Book book3 = {"003", "算法导论", "Thomas H. Cormen", 3};

    InsertBook(&head, book1);
    InsertBook(&head, book2);
    InsertBook(&head, book3);


    // 查找图书信息
    FindBook(head, bookId_find);

    // 修改图书库存数量
    UpdateStock(head, bookId_update, num);

    // 删除图书信息
    DeleteBook(&head, bookId_delete);

    // 遍历输出图书列表
    TraverseList(head);

    // 释放链表内存
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}