#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

/******************* 染色 *******************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getNumber(struct TreeNode* root, int** ops, int opsSize){
    int cnt = 0;

    struct TreeNode *buf[32767];
    int front = 0;
    int rear = 0;
    buf[front] = root;
    front++;
    while (rear < front) {
        struct TreeNode *temp = buf[rear];
        rear++;
        int value = temp->val;
        if (temp->left != NULL) {
            buf[front] = temp->left;
            front++;
        }
        if (temp->right != NULL) {
            buf[front] = temp->right;
            front++;
        }
        for (int i = opsSize - 1; i >=0; i--) {
            if (value >= ops[i][1] && value <= ops[i][2]) {
                if (ops[i][0] == 1) {
                    cnt++;
                }
                break;
            }
        } 
    }
    printf("%d\n", cnt);
    return cnt;
}

/*****************************************************/

/******************* 读取数据 *******************/
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* constructTree(int size) {
    if (size == 0)
        return NULL;

    struct TreeNode** nodes = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    for (int i = 0; i < size; i++) {
        int val;
        scanf("%d", &val);
        if (val == -1) {
            nodes[i] = NULL;
        } else {
            nodes[i] = newTreeNode(val);
        }
    }

    for (int i = 0, j = 1; j < size; i++) {
        if (nodes[i] != NULL) {
            if (j < size)
                nodes[i]->left = nodes[j++];
            if (j < size)
                nodes[i]->right = nodes[j++];
        }
    }

    struct TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

void readOps(int ***ops, int *opsSize) {
    scanf("%d", opsSize);

    *ops = (int **)malloc(*opsSize * sizeof(int *));
    while(getchar() != '[') {}
    for (int i = 0; i < *opsSize; i++) {
        (*ops)[i] = (int *)malloc(3 * sizeof(int));
        while(getchar() != '[') {}
        for (int j = 0; j < 3; j++) {
            scanf("%d", &((*ops)[i][j]));
        }
        while(getchar() != ']') {}
    }
}
/*****************************************************/

int main() {
    int nodeSize;
    scanf("%d", &nodeSize);
    struct TreeNode* root = constructTree(nodeSize);
    int **ops, opsSize;
    readOps(&ops, &opsSize);
    getNumber(root, ops, opsSize);

    return 0;
}