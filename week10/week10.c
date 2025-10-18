#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

typedef struct{
    int ID;
    int age;
    float gpa;
}Student;

int *part1(int size);
int findMinimumValue(int size, int *array);
void calculateCumulativeSum(int* array, int size, int* cumulativeArray);
float calculateAverageGPA(Student* students, int size);



int main()
{
    int size;
    int *array;
    int *cumulativeArray;
    
    
    printf("\n*** PART 1 ***\n");
    printf("Please enter the size of the array: ");
    scanf("%d", &size);
    
    array = part1(size);
    
    int minimumValue;
    
    minimumValue = findMinimumValue(size,array);
    
    printf("The minimum value in the array is : %d", minimumValue);
    
    free(array); //Note to myself: It's necessary to release the dynamically allocated memory.
    
    printf("\n*** PART 2 ***\n");
    
    printf("Please enter the size of the array: ");
    scanf("%d", &size);
    
    cumulativeArray = (int *)calloc(size, sizeof(int));
    
    if(cumulativeArray == NULL)
    {
        printf("Warning!\n");
        free(array);
        
        return 1;
    }
    
    array = part1(size);
    
    calculateCumulativeSum(array, size, cumulativeArray);
    
    
    printf("First Array: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Cumulative Sum Array: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", cumulativeArray[i]);
    }
    printf("\n");

    free(array);
    free(cumulativeArray);
    
    printf("\n*** PART 3 ***\n");
    
    Student *students = malloc(SIZE *sizeof(Student));
    
    if(students == NULL)
    {
        printf("Warning!\n");
        return 1;
    }
    
    srand(time(NULL));
    
    for(int i=0; i<SIZE;++i)
    {
        students[i].ID = i + 1;
        students[i].age = rand()%43 + 18; //age between 18 and 60
        students[i].gpa = (rand()%401) / 100.0; // gpa between 0.0 and 4.0
    }
    
    float averageGPA;
    
    averageGPA = calculateAverageGPA(students, SIZE);
    
    printf("The Average GPA is: %.3f\n", averageGPA);
    
    free(students); // Note to myself: Don't forget to add free() function just like fclose() function in files.
    
    return 0;
    
}


int *part1(int size)
{
    
    int *array = (int *)malloc(size *sizeof(int));
    
    if(array == NULL)
    {
        printf("Warning!\n");
        return NULL;
    }
    
    for(int i=0; i<size; ++i)
    {
        printf("Please enter the %d. value: ", (i+1));
        scanf("%d", &array[i]);
    }
    
    return array;
    
}

int findMinimumValue(int size, int *array)
{
    int minimumValue = array[0];
    
    for(int i=0; i<size; ++i)
    {
        if(array[i] < minimumValue)
        {
            minimumValue = array[i];
        }

    }
    
    return minimumValue;
}

void calculateCumulativeSum(int* array, int size, int* cumulativeArray)
{
    // if i = 0, arrayleri eşitliyor.
    cumulativeArray[0] = array[0];
    
    for (int i = 1; i < size; i++)
    {
        cumulativeArray[i] = cumulativeArray[i-1] + array[i];
    }
}

float calculateAverageGPA(Student* students, int size)
{
    float totalGPA = 0.0;
    
    // Note to myself: size already defined
    for (int i = 0; i < size; i++)
    {
        totalGPA += students[i].gpa;
    }
    
    float averageGPA = totalGPA / size;
    
    return averageGPA;
}
