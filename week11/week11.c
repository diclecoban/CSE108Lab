#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {
    char customer_name[1000];
    int order_id;
    char items_ordered[1000];
    char order_time[1000];
    struct Order* next;
} Order;

Order* enqueue(Order* queue, char* customerName, int* orderID, char* items, char* orderTime)
{
    Order* new_order = (Order*)malloc(sizeof(Order));
    strcpy(new_order->customer_name, customerName);
    new_order->order_id = *orderID;
    strcpy(new_order->items_ordered, items);
    strcpy(new_order->order_time, orderTime);
    new_order->next = NULL;

    if (queue == NULL)
    {
        return new_order;
    }
    
    else
    {
        Order* current = queue;
        
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_order; // Sıranın sonunu buldu
        return queue;
    }
}

Order* dequeue(Order* queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    
    else
    {
        Order* oldest_order = queue;
        queue = queue->next;
        free(oldest_order);
        return queue;
    }
}

void display(Order* queue)
{
    if (queue == NULL)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        Order* current = queue;
        while (current != NULL)
        {
            printf("Customer Name: %s\n", current->customer_name);
            printf("Order ID: %d\n", current->order_id);
            printf("Items Ordered: %s\n", current->items_ordered);
            printf("Order Time: %s\n", current->order_time);
            printf("--------------------\n");
            current = current->next;
        }
    }
}

void updateOrder(Order* queue, int orderID, char* newItems)
{
    Order* current = queue;
    
    while (current != NULL)
    {
        if (current->order_id == orderID)
        {
            strcpy(current->items_ordered, newItems);
            return;
        }
        
        current = current->next;
    }
    
    printf("Order with ID %d not found.\n", orderID);
}

int main()
{
    Order* root = NULL;
    int choice = 0;
    Order new_order;

    while (choice != 5)
    {
        printf("1. Add an order\n");
        printf("2. Remove the oldest order\n");
        printf("3. Update an order's items\n");
        printf("4. Display all orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter order ID: ");
                scanf("%d", &new_order.order_id);
                printf("Enter customer name: ");
                scanf(" %[^\n]", new_order.customer_name);
                printf("Enter items ordered: ");
                scanf(" %[^\n]", new_order.items_ordered);
                printf("Enter order time: ");
                scanf(" %[^\n]", new_order.order_time);
                root = enqueue(root, new_order.customer_name, &new_order.order_id, new_order.items_ordered, new_order.order_time);
                printf("Order added successfully.\n");
                printf("\n");
                display(root);
                break;
            case 2:
                root = dequeue(root);
                printf("Oldest order removed.\n");
                break;
            case 3:
                printf("Enter the order ID to update: ");
                scanf("%d", &new_order.order_id);
                printf("Enter new items: ");
                scanf(" %[^\n]", new_order.items_ordered);
                updateOrder(root, new_order.order_id, new_order.items_ordered);
                break;
            case 4:
                printf("Displaying the orders by order time...\n");
                printf("-----------------------\n");
                display(root);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    // Free memory for the remaining orders in the list
    while (root != NULL)
    {
        root = dequeue(root);
    }

    return 0;
}
