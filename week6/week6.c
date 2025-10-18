#include <stdio.h>
#include <stdlib.h>

int ReadingArray(int i, int number, int arr[100], char labels[100]);
int EvenorOdd(int i, int number, char labels[100]);
int PrintArray(int i, int arr[100], char labels[100]);
int part2();

int main()
{
    int i;
    int number;
    int arr[100];
    char labels[100];
    
    ReadingArray(i,number,&arr[100],&labels[100]);
    part2();
 //  part3();
}

int ReadingArray(int i, int number, int arr[100], char labels[100])
{
    
    i = 0;
    
        printf("Please enter integers (terminate with -100): ");
        scanf("%d", &number);
    
        while (number != -100 && i < 100)
        {
            arr[i] = number;
            
            EvenorOdd(i,number,labels);
            
            ++i;
            
            printf("Please enter integers (terminate with -100): ");
            scanf("%d", &number);
        }
    
         PrintArray(i,arr,labels);
    
    return 0;
}

int EvenorOdd(int i, int number, char labels[100])
{
    if(number % 2 == 0)
    {
        labels[i] = 'e';
    }
    else
    {
        labels[i] = 'o';
    }
    
    return labels[i];
}

int PrintArray(int i, int arr[100], char labels[100])
{
    printf("Number\tLabel\n");

    for (int j = 0; j < i; ++j)
    {
        printf("%d\t%c\n", arr[j], labels[j]);
    }

    return 0;
}

int part2()
{
    FILE *fans;
        int numRows;
        int age[numRows];
        char occupation[numRows];
        float salary[numRows];
        char team[numRows];
        char selectedTeam;
    int i;
        
        fans = fopen("fans.txt", "r");
        
        if (fans == NULL)
        {
            printf("Failed to open file\n");
            return 1;
          }

    fscanf(fans, "%d", &numRows);
        
        for (int i = 0; i < numRows; i++)
        {
    
    fscanf(fans, "%d ", &age[i]);
    
    occupation[i]=fgetc(fans);
    
    fscanf(fans, " %f ", &salary[i]);
    
    team[i]= fgetc(fans);
    fgetc(fans);
            
        }
   
    
        fclose(fans);

          printf("Please select a team: ");
          scanf("  %c", &selectedTeam);

          float totalSalary = 0;
          int numFans = 0;

          for (int i = 0; i < numRows; ++i)
          {
            if (team[i] == selectedTeam)
            {
              totalSalary = totalSalary + salary[i];
              numFans++;
            }
          }

          if (numFans > 0)
          {
            float avgSalary = totalSalary / numFans;
            printf("Average salaries of %c fans is: %f \n", selectedTeam, avgSalary);
          }
          else
          {
            printf("Sorry. There are no %c fans in the database!\n", selectedTeam);
          }
        
        
    return 0;
}
