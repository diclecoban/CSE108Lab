#ifndef _UTIL_H_
#define _UTIL_H_

struct Node* createNode(int value);
struct Node* insertNode(struct Node* node, int value);
struct BST* generateBST(const char* filename);
void saveBSTToFile(struct Node* node, FILE* file);
void updateFile(const char* filename, struct BST* bst);
void printInOrder(struct Node* node);
int countNodes(struct Node* node);
int getMaxDepth(struct Node* node);
void printTree(struct BST* bst);
void freeBST(struct Node* node);
struct Node* findMinNode(struct Node* node);
struct Node* removeNode(struct Node* node, int value);
struct Node* searchNode(struct Node* node, int value);

#endif /* _UTIL_H_ */
