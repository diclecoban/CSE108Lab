#include <stdio.h>

int main()
{
    
    float x,y,maxvalue;
    float z;
    
    printf("Please enter the first number: ");
    scanf("%2f", &x);
    
    printf("Please enter the second number: ");
    scanf("%2f", &y);
    
    
    if(x>=y)
    {
        maxvalue = x;
    }
    else
    {
        maxvalue = y;
    }
    
    z = (x/y) + (maxvalue/(x+y))
    ;
    
    printf("%2f", z);
    
}
