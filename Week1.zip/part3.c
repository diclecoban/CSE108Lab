#include <stdio.h>

int main()
{
    int age,exp;
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    printf("Please enter your experience: ");
    scanf("%d", &exp);
    
    if(age<20)
    {
        if(exp>0 && exp<10)
        {
            printf("Your salary is 10.000\n");
        }
        else if(exp>10)
        {
            printf("ERROR\n");
        }
    }
    if(age>=20 && age<=50)
    {
        if(exp>0 && exp<10)
        {
            printf("Your salary is 15.000");
        }
        else if(exp>10)
        {
            printf("Your salary is 20.000");
        }
    }
    if(age>50)
    {
        if(exp>0 && exp<10)
        {
            printf("Your salary is 20.000");
        }
        else if(exp>10)
        {
            printf("Your salary is 25.000");
        }
    }
}
