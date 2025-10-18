#include <stdio.h>

int main()
{
    int number1;
    
    printf("Please enter a number between 1 and 100: ");
    scanf("%d", &number1);
    
    if(number1%3 == 0 && number1>=5 && number1 <=50)
    {
        printf("Fizzbuzz.\n");
    }
        
        else
        {
            if(number1%3 == 0)
            {
                printf("Fizz\n");
            }
            else if(number1>=5 && number1<=50)
            {
                printf("Buzz.\n");
            }
        }
}
