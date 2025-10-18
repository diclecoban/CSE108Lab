#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum PriorityLevel
{
    NORMAL = 1,
    VETERAN = 2,
    OD = 3,
    VIP = 4
};


struct Customer
{
    char name[50];
    int age;
    char priorityGroupName[50];
    enum PriorityLevel priorityLevel;
};


struct Node
{
    struct Customer customer;
    struct Node* next;
};


struct Queue
{
    struct Node* front;
    struct Node* rear;
};


struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}


int isEmpty(struct Queue* queue)
{
    return (queue->front == NULL);
}


void enqueue(struct Queue* queue, struct Customer customer)
{
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->customer = customer;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    
    else
    {
        struct Node* current = queue->front;
        struct Node* prev = NULL;

        
        while (current != NULL && current->customer.priorityLevel >= newNode->customer.priorityLevel)
        {
            prev = current;
            current = current->next;
        }

        if (prev == NULL)
        {
            newNode->next = queue->front;
            queue->front = newNode;
        }
        
        else
        {
            prev->next = newNode;
            newNode->next = current;
        }

        if (current == NULL)
        {
            queue->rear = newNode;
        }
    }
}


void removeCustomer(struct Queue* queue, const char* name)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    struct Node* prev = NULL;

    
    while (current != NULL)
    {
        if (strcmp(current->customer.name, name) == 0)
        {
            
            if (prev == NULL)
            {
                
                queue->front = current->next;
            }
            else
            {
               
                prev->next = current->next;
                
                if (current == queue->rear)
                {
                   
                    queue->rear = prev;
                }
            }

            free(current);
            printf("Customer '%s' removed from the queue.\n", name);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Customer '%s' not found in the queue.\n", name);
    
}


struct Customer front(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        
        struct Customer defaultCustomer;
        strcpy(defaultCustomer.name, "");
        defaultCustomer.age = 0;
        strcpy(defaultCustomer.priorityGroupName, "");
        defaultCustomer.priorityLevel = NORMAL;
        return defaultCustomer;
    }

    return queue->front->customer;
}


void readCustomersFromFile(struct Queue* queue, const char* filename)
{
    
    FILE* file = fopen(filename, "r");
    
    if (file == NULL)
    {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), file))
    {
       
        char name[100];
        int age;
        char priorityGroupName[100];
        enum PriorityLevel priorityLevel = NORMAL;

        int index = 0;
        int lineLength = strlen(line);
        int tokenIndex = 0;
        char token[100];
        
        for (int i = 0; i < lineLength; i++)
        {
            if (line[i] != ',')
            {
                token[index++] = line[i];
            }
            
            else
            {
                token[index] = '\0';
                index = 0;

                
                if (tokenIndex == 0)
                {
                    strcpy(name, token);
                }
                
                else if (tokenIndex == 1)
                {
                    age = atoi(token);
                }
                
                else if (tokenIndex == 2)
                {
                    strcpy(priorityGroupName, token);
                    
                    if (strcmp(priorityGroupName, "VIP") == 0)
                    {
                        priorityLevel = VIP;
                    }
                    
                    else if (strcmp(priorityGroupName, "OD") == 0)
                    {
                        priorityLevel = OD;
                    }
                    
                    else if (strcmp(priorityGroupName, "VETERAN") == 0)
                    {
                        priorityLevel = VETERAN;
                    }
                    
                }

                tokenIndex++;
            }
        }

        
        struct Customer newCustomer;
        strcpy(newCustomer.name, name);
        newCustomer.age = age;
        strcpy(newCustomer.priorityGroupName, priorityGroupName);
        newCustomer.priorityLevel = priorityLevel;
        enqueue(queue, newCustomer);
        
    }

    fclose(file);
}


void writeCustomersToFile(struct Queue* queue, const char* filename)
{
    
    FILE* file = fopen(filename, "w");
    
    if (file == NULL)
    {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    struct Node* current = queue->front;
    
    while (current != NULL)
    {
        fprintf(file, "%s,%d,%s\n", current->customer.name, current->customer.age, current->customer.priorityGroupName);
        current = current->next;
    }

    fclose(file);
}


void insertCustomer(struct Queue* queue, const char* filename, struct Customer customer)
{
    
    enqueue(queue, customer);
    writeCustomersToFile(queue, filename);
    
}


void changePriority(struct Queue* queue, const char* filename, const char* name, enum PriorityLevel newPriorityLevel)
{
    struct Node* current = queue->front;

    
    while (current != NULL)
    {
        if (strcmp(current->customer.name, name) == 0)
        {
            
            current->customer.priorityLevel = newPriorityLevel;
            printf("Priority level of customer '%s' changed to %d.\n", name, newPriorityLevel);

            
            writeCustomersToFile(queue, filename);
            return;
        }

        current = current->next;
    }

    printf("Customer '%s' not found in the queue.\n", name);
}


void displayCustomers(struct Queue* queue)
{
    
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    
    printf("Customers in the Queue:\n");
    
    while (current != NULL)
    {
        printf("Name: %s\n", current->customer.name);
        printf("Age: %d\n", current->customer.age);
        printf("Priority Group Name: %s\n", current->customer.priorityGroupName);
        printf("Priority Level: %d\n", current->customer.priorityLevel);
        printf("\n");
        current = current->next;
    }
}


void searchCustomerRecursive(struct Node* current, const char* name)
{
    
    if (current == NULL)
    {
        printf("Customer '%s' not found.\n", name);
        return;
    }

    if (strcmp(current->customer.name, name) == 0)
    {
        
        printf("Customer Details:\n");
        printf("Name: %s\n", current->customer.name);
        printf("Age: %d\n", current->customer.age);
        printf("Priority Group Name: %s\n", current->customer.priorityGroupName);
        printf("Priority Level: %d\n", current->customer.priorityLevel);
        printf("\n");
    }
    else
    {
        
        searchCustomerRecursive(current->next, name);
    }
}


void searchCustomer(struct Queue* queue, const char* name)
{
    
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    searchCustomerRecursive(queue->front, name);
    
}



void menu(struct Queue* queue, const char* filename)
{
    int option = 0;
    while (option != 6)
    {
        printf("\nWelcome to the ABC Bank\n");
        printf("1- Insert new customer\n");
        printf("2- Remove customer\n");
        printf("3- Display customers in order\n");
        printf("4- Search a customer\n");
        printf("5- Change Priority Settings\n");
        printf("6- Exit\n");

        printf("Please select an option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            {
               
                struct Customer newCustomer;
                printf("Enter customer name: ");
                scanf(" %[^\n]", newCustomer.name);
                printf("Enter customer age: ");
                scanf("%d", &newCustomer.age);
                printf("Enter priority group name: ");
                scanf(" %[^\n]", newCustomer.priorityGroupName);
                printf("Enter priority level (1-NORMAL, 2-VETERAN, 3-OD, 4-VIP): ");
                scanf("%d", (int*)&newCustomer.priorityLevel);
                insertCustomer(queue, filename, newCustomer);
                printf("Customer '%s' inserted successfully.\n", newCustomer.name);
                break;
            }
            case 2:
            {
                
                char customerName[50];
                printf("Enter customer name to remove: ");
                scanf(" %[^\n]", customerName);
                removeCustomer(queue, customerName);
                break;
            }
            case 3:
            {
                printf("\n");
                printf("-----------------\n");
                printf("\n");
                displayCustomers(queue);
                printf("-----------------");
                break;
            }
            case 4:
            {
                
                char customerName[50];
                printf("Enter customer name to search: ");
                scanf(" %[^\n]", customerName);
                printf("\n");
                searchCustomer(queue, customerName);
                break;
            }
            case 5:
            {
                struct Customer newCustomer;
                char customerName[50];
                int newPriorityLevel;
                printf("Enter customer name: ");
                scanf(" %[^\n]", customerName);
                printf("Enter priority group name: ");
                scanf(" %[^\n]", newCustomer.priorityGroupName);
                printf("Enter new priority level (1-NORMAL, 2-VETERAN, 3-OD, 4-VIP): ");
                scanf("%d", &newPriorityLevel);
                changePriority(queue, filename, customerName, (enum PriorityLevel)newPriorityLevel);
                
                // Buradaki sıkıntıyı düzelt
                break;
            }
            case 6:
            {
                
                printf("Exiting the program.\n");
                break;
            }
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

int main()
{

    struct Queue* customerQueue = createQueue();


        readCustomersFromFile(customerQueue, "customers.txt");


        menu(customerQueue, "customers.txt");


    return 0;
}
