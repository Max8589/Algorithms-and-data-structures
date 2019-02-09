#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T int

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *root;
} Node;

// Распечатка двоичного дерева
void printTree(Node *root) {
    if (root) {
        printf("%d",root->data);
        if (root->left || root->right) {
            printf("(");
            
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

// Создание нового узла
Node* getFreeNode(T value, Node *root) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->root = root;
    return tmp;
}

//1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
int amountOfSymbols(char symbols[]) {
    int amount = 0;
    for (int i = 0; i < strlen(symbols); i++)
        amount += symbols[i];
    return amount;
}
//2. Переписать программу, реализующее двоичное дерево поиска.
//
//а) Добавить в него обход дерева различными способами;
void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(Node* root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ",root->data);
        inOrderTravers(root->right);
    }
}

void postOrderTravers(Node* root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ",root->data);
    }
}
//б) Реализовать поиск в двоичном дереве поиска;
void searchNode(Node *root, T value) {
    if (root == NULL)
        printf("Value does not exist in tree");
    else if (root->data == value)
            printf("Value found");
        else if (value > root->data)
                searchNode(root->right, value);
            else
                searchNode(root->left, value);
}

int main(int argc, const char** argv) {
    char st[] = "asdfa sqqtaer3245gtc";
    printf("Amount of symbols - %s: %d\n", st, amountOfSymbols(st));
    
    Node *Tree = NULL;
    Tree = getFreeNode(5, NULL);
    Tree->left = getFreeNode(-1, Tree);
    Tree->right = getFreeNode(8, Tree);
    Tree->left->left = getFreeNode(-14, Tree->left);
    Tree->left->right = getFreeNode(3, Tree->left);
    Tree->right->left = getFreeNode(6, Tree->right);
    Tree->right->right = getFreeNode(10, Tree->right);
    Tree->right->right->left = getFreeNode(9, Tree->right->right);
   
    
    printf("Binary tree: ");
    printTree(Tree);
    printf("\n");
    printf("Preorder travers: ");
    preOrderTravers(Tree);
    printf("\n");
    printf("Inorder travers: ");
    inOrderTravers(Tree);
    printf("\n");
    printf("Postorder travers: ");
    postOrderTravers(Tree);
    printf("\n");
    printf("Binary tree search: ");
    searchNode(Tree, 323);
    printf("\n");
    printf("Binary tree search: ");
    searchNode(Tree, -14);
    printf("\n");
    return 0;
}
