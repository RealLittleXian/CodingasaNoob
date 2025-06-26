#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (inorderSize == 0) {
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int idx;
    for (idx = 0; idx < inorderSize; idx++) {
        if (inorder[idx] == preorder[0]) {
            break;
        }
    }
    root->left = buildTree(preorder+1,idx,inorder,idx);
    root->right = buildTree(preorder+idx+1,preorderSize-1-idx,inorder+idx+1,inorderSize-1-idx);
    return root;
}

void printTree(struct TreeNode* root) {
    if (root == NULL) {
        printf("null\n");
        return;
    }
    struct TreeNode** queue = (struct TreeNode**)malloc(1000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) { 
        struct TreeNode* current = queue[front++];
        if (current) {
            printf("%d ", current->val); 
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        } else {
            printf("null "); 
        }
    }

    free(queue);
    printf("\n");
}


int main() {
    int preorderSize;
    scanf("%d", &preorderSize);
    int* preorder = (int*)malloc(preorderSize * sizeof(int));
    for (int i = 0; i < preorderSize; i++) {
        scanf("%d", &preorder[i]);
    }

    int inorderSize = preorderSize;
    int* inorder = (int*)malloc(inorderSize * sizeof(int));
    for (int i = 0; i < inorderSize; i++) {
        scanf("%d", &inorder[i]);
    }

    struct TreeNode* root = buildTree(preorder, preorderSize, inorder, inorderSize);
    printTree(root);

    return 0;
}