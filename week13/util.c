#include <stdio.h>
#include <stdlib.h>
#include "util.h"

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct BST {
    struct Node* root;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->value) {
        node->left = insertNode(node->left, value);
    } else if (value > node->value) {
        node->right = insertNode(node->right, value);
    }
    return node;
}

struct BST* generateBST(const char* filename) {
    struct BST* bst = (struct BST*)malloc(sizeof(struct BST));
    bst->root = NULL;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return bst;
    }

    int value;
    fscanf(file, "%d", &value);
    bst->root = createNode(value);

    while (fscanf(file, "%d", &value) == 1) {
        insertNode(bst->root, value);
    }

    fclose(file);
    return bst;
}

struct Node* findMinNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* removeNode(struct Node* node, int value) {
    if (node == NULL) {
        return node;
    }

    if (value < node->value) {
        node->left = removeNode(node->left, value);
    } else if (value > node->value) {
        node->right = removeNode(node->right, value);
    } else {
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }

        struct Node* minRightNode = findMinNode(node->right);
        node->value = minRightNode->value;
        node->right = removeNode(node->right, minRightNode->value);
    }

    return node;
}

void saveBSTToFile(struct Node* node, FILE* file) {
    if (node != NULL) {
        saveBSTToFile(node->left, file);
        fprintf(file, "%d ", node->value);
        saveBSTToFile(node->right, file);
    }
}

void updateFile(const char* filename, struct BST* bst) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }
    saveBSTToFile(bst->root, file);
    fclose(file);
}

void printInOrder(struct Node* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d ", node->value);
        printInOrder(node->right);
    }
}

int countNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int getMaxDepth(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = getMaxDepth(node->left);
    int rightDepth = getMaxDepth(node->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

void printTree(struct BST* bst) {
    if (bst->root == NULL) {
        printf("BST is empty.\n");
        return;
    }

    int choice;
    printf("Choose the print format:\n");
    printf("1. In-order\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Binary Search Tree: ");
    switch (choice) {
        case 1:
            printInOrder(bst->root);
            break;
        case 2:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    printf("\n");
}

void freeBST(struct Node* node) {
    if (node != NULL) {
        freeBST(node->left);
        freeBST(node->right);
        free(node);
    }
}
struct Node* searchNode(struct Node* node, int value)
{
    if (node == NULL || node->value == value)
    {
        return node;
    }

    if (value < node->value)
    {
        return searchNode(node->left, value);
    }
    else
    {
        return searchNode(node->right, value);
    }
}
