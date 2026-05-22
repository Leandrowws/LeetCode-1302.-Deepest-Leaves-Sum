#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

int Altura(struct TreeNode *root) {
    if(root==NULL) {
        return -1;
    } else {
        int esq = Altura(root->left);
        int dir = Altura(root->right);
        if(esq > dir) {
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}

int Soma(struct TreeNode *root, int nivel, int altura) {

    if(root == NULL) {
        return 0;
    }

    if(altura == nivel) {
        return root->val;
    }

    return Soma(root->left, nivel + 1, altura) + Soma(root->right, nivel + 1, altura);
}

int deepestLeavesSum(struct TreeNode* root) {
    return Soma(root, 0, Altura(root));
}

struct TreeNode* Insert(struct TreeNode *root, int val) {
    if(root==NULL) {
        struct TreeNode* aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->right = NULL;
        aux->left = NULL;
        aux->val = val;
        return aux;
    } else {
        if(val < root->val) {
            root->left = Insert(root->left, val);
        } else {
            root->right = Insert(root->right, val);
        }
        return root;
    }
}

int main() {
    
    struct TreeNode *arv = NULL;

    arv = Insert(arv, 10);
    arv = Insert(arv, 5);
    arv = Insert(arv, 15);

    printf("Soma das folhas do nivel mais baixo: %d", deepestLeavesSum(arv));

    return 0;
}
