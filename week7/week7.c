#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int minStep(char *array);
void getArray(int arr[], int size);
int findMin(int arr[], int n);
int findMax(int arr[], int n);
void deleteWords(char *input, char *substring);

int main()
{
    char array[100] = "";
    int result = minStep(array);
        printf("It takes at least %d times to delete your string.\n", result);
    
    int arr[100];
    int size, min, max;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Please enter %d integers: ", size);
    
    getArray(arr, size);
    
    min = findMin(arr, size);
    max = findMax(arr, size);
    
    printf("Minimum integer is %d\n", min);
    printf("Maximum integer is %d\n", max);
    
}

int minStep(char* array)
{
    // char array[100] = "";
    
    printf("Please enter a string: ");
   // fgets(array,sizeof(array),stdin);
    scanf("%s", array);

    int length = strlen(array);
    int steps = 0;
    int i = 0; // keep track of the current string.

    while (i < length)
    {
        int j = i + 1;
        
        while (j < length && array[j] == array[i])
        {
            j++;
        }
        
        steps += (j - i) / 3;
        i = j;
    }

    return steps;
}

void getArray(int arr[], int size)
{
    
    if(size == 0)
    {
        return;
    }
    
    scanf("%d", &arr[size-1]);
    getArray(arr, size-1);
    
}

int findMin(int arr[], int n)
{
    if(n == 1)
    {
        return arr[0];
    }
    
    int min = findMin(arr, n-1);
    
    if (arr[n-1] < min)
    {
        return arr[n-1];
    }
    else
    {
        return min;
    }
}

int findMax(int arr[], int n)
{
    if(n == 1)
    {
        return arr[0];
    }
    
    int max = findMax(arr, n-1);
    
    if (arr[n-1] > max)
    {
        max = arr[n-1];
    }

        return max;
}


void deleteWords(char *input, char *substring)
{
    // Part2 but I couldn't make it.
    
    /* char *word = strtok(input, " "); // tokenize the input string
    char *prev = NULL;
    while (word != NULL)
    {
        if (strstr(word, substring) != NULL)
        {
            if (prev != NULL)
            {

                memmove(prev, word + strlen(word) + 1, strlen(word + strlen(word) + 1) + 1);
                
                word = prev;
            } else {
 
                memmove(input, word + strlen(word) + 1, strlen(word + strlen(word) + 1) + 1);
 
                word = input;
            }
        }
        prev = word;
        word = strtok(NULL, " ");
    } */
}
