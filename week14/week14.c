#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Order {
    char* customerName;
    int orderID;
    char* items;
    time_t orderTime;
    struct Order* next;
} Order;

//LIFO kısmı
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LIFO {
    Node* top;
} LIFO;

// FIFO kısmı
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct FIFO {
    Node* front;
    Node* rear;
} FIFO;

void enqueue(Order** list, char* customerName, int orderID, char* items, time_t orderTime)
{
    Order* current_order = (Order*)malloc(sizeof(Order));

    current_order->customerName = strdup(customerName);
    current_order->orderID = orderID;
    current_order->items = strdup(items);
    current_order->orderTime = orderTime;
    current_order->next = NULL;

    if (*list == NULL)
    {
        *list = current_order;
        return;
    }

    Order* current = *list;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = current_order;
}

Order* dequeue(Order** list, time_t thresholdTime)
{
    Order* removedOrders = NULL;
    Order* prev = NULL;
    Order* current = *list;

    while (current != NULL && current->orderTime < thresholdTime)
    {
        if (prev == NULL)
        {
            *list = current->next;
        }
        else
        {
            prev->next = current->next;
        }

        current->next = removedOrders;
        removedOrders = current;

        current = current->next;
    }

    return removedOrders;
}

void initializeLIFO(LIFO* stack)
{
    stack->top = NULL;
}

int isEmpty(LIFO* stack)
{
    return stack->top == NULL;
}

void push(LIFO* stack, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(LIFO* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }

    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void serializeLIFO(LIFO* stack, const char* filename)
{
    FILE* lifofile = fopen(filename, "wb");
    
    if (lifofile == NULL)
    {
        printf("Failed to open the file for writing.\n");
        return;
    }

    Node* current = stack->top;
    
    while (current != NULL)
    {
        fwrite(&(current->data), sizeof(int), 1, lifofile);
        current = current->next;
    }

    fclose(lifofile);
}

LIFO* deserializeLIFO(const char* filename)
{
    
    FILE* lifofile = fopen(filename, "rb");
    
    if (lifofile == NULL)
    {
        printf("Warning! Failed to open the file for reading.\n");
        return NULL;
    }

    LIFO* stack = (LIFO*)malloc(sizeof(LIFO));
    
    initializeLIFO(stack);

    int data;
    
    while (fread(&data, sizeof(int), 1, lifofile) == 1)
    {
        push(stack, data);
    }

    fclose(lifofile);
    
    return stack;
}

