#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

void preorder(struct TreeNode *root){
    if (root == NULL){
        return;
    }

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct TreeNode *root){
    if (root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void postorder(struct TreeNode *root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int maxDepth(struct TreeNode *root){
    if (root  == NULL){
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    //遞迴去找左右哪邊比較深
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int countNodes(struct TreeNode *root){
    if (root == NULL){
        return 0;
    }

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return 1 + leftCount + rightCount;
}

struct TreeNode* searchBST(struct TreeNode *root, int target){
    if (root == NULL){
        return NULL;
    }

    //要記得return 左右子樹的BST funtion，因為是一層層往下找，找到沒有為止，最後不用再全部彈上來，所以用return
    if (target == root->val){
        return root;
    }
    else if (target < root->val){
        return searchBST(root->left, target);
    }
    else{
        return searchBST(root->right, target);
    }

    return NULL;
}

struct TreeNode* insertBST(struct TreeNode *root, int target){
    if (root == NULL){
        //找到對的位子，把要插入的node return回去給父節點
        struct TreeNode *node = malloc(sizeof(struct TreeNode));
        node->val = target;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (target < root->val){
        root->left = insertBST(root->left, target);
    }
    else{
        root->right = insertBST(root->right, target);
    }

    //回傳root是因為要把tree一層層往上接
    return root;
}

struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL){
        return NULL;
    }

    //先往左右遞迴下去最深的子樹，再往上stack回去一層層交換左右
    struct TreeNode *left = invertTree(root->left);
    struct TreeNode *right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}




