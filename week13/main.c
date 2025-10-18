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

int main() {
    const char* filename = "input.txt";
    struct BST* bst = generateBST(filename);

    int choice;
    int value;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Add a node\n");
        printf("2. Remove a node\n");
        printf("3. Search for a node\n");
        printf("4. Count total nodes\n");
        printf("5. Get maximum depth\n");
        printf("6. Print the tree\n");
        printf("7. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                insertNode(bst->root, value);
                updateFile(filename, bst);
                printf("Node added successfully!\n");
                break;
            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                bst->root = removeNode(bst->root, value);
                updateFile(filename, bst);
                printf("Node removed successfully!\n");
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = searchNode(bst->root, value);
                
                   if (foundNode != NULL)
                   {
                       printf("Node found!\n");
                   }
                   else
                   {
                       printf("Node not found.\n");
                   }
                break;
            case 4:
                printf("Total nodes in the BST: %d\n", countNodes(bst->root));
                break;
            case 5:
                printf("Maximum depth of the BST: %d\n", getMaxDepth(bst->root));
                break;
            case 6:
                printTree(bst);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    freeBST(bst->root);
    free(bst);

    return 0;
}
