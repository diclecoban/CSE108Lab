#include <stdio.h>
#include <stdlib.h>

int part1menu();
double CtoF();
double FtoC();
int Palindrom();
int part3menu(int dec);
int dectobi(int dec);
int dectooctal(int dec);
int dectohex(int dec);



int main()
{
    int part, dec, number;
    
    printf("\nPlease enter your part(1-3): ");
    scanf("%d", &part);
     switch(part)
     {
         case 1:
             part1menu();
             break;
         case 2:
             Palindrom();
             break;
         case 3:
             part3menu(dec);
             break;
     }
    
    
    
}


int part1menu()
{
    int choice;
    
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Quit\n");

    
    printf("Please enter your choice(1-3): ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            CtoF();
            break;
        case 2:
            FtoC();
            break;
        case 3:
            exit(0);
            break;
    }
    
    return 0;
}

double CtoF()
{
    double temp;
    double result;
    
    printf("Please enter the temperature value to convert: ");
    scanf("%lf", &temp);

    result = ((temp*9/5)+32);
    
    printf("%.2lf Celsius = %.2lf Fahrenheit", temp, result);
    
    printf("\nHeading to the menu...\n");
    
    printf("\n");
    part1menu();
    
    return result;
}

double FtoC()
{
    
    double temp;
    double result;
    
    printf("Please enter the temperature value to convert: ");
    scanf("%lf", &temp);
    
    result = (temp - 32) * 5/9;
    
    printf("%.2lf Fahrenheit = %.2lf Celsius", temp, result);
    
    printf("\nHeading to the menu...\n");
    
    printf("\n");
    part1menu();
    
    return result;
}

int Palindrom()
{
    int number, tempNumber, copy, digit, p = 0;
    
    printf("Enter a number with 3, 4, or 5 digits: ");
    scanf("%d", &number);
    
    while( number<100 || number>10000)
    {
        printf("You can't enter that number!");
        printf("\nEnter a number with 3, 4, or 5 digits: ");
        scanf("%d", &number);
    }
    
    tempNumber = number;
    
    while (tempNumber != 0)
    {
        digit = tempNumber % 10;
        p = p * 10 + digit;
        tempNumber = tempNumber / 10;
    }
    
        printf("The number %d reversed is %d.\n", number, p);


    
    return 0;
}

int part3menu(int dec)
{
    int choice;
    
    printf("1. Convert a number to decimal, binary, octal and hexadecimal\n");
    printf("2. Quit\n");
    
    printf("Please enter a choice(1-2): ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            
    printf("Enter the number to convert: ");
    scanf("%d", &dec);
            
    printf("Decimal equivalent = %d", dec);
            
            dectobi(dec);
            dectooctal(dec);
            dectohex(dec);
            
            printf("\nHeading to the menu...\n");
            printf("\n");
            
            part3menu(dec);
            
            break;
        case 2:
            exit(0);
            break;
        default:
            break;
    }
    
    return 0;
}

int dectobi(int dec)
{
    int bit;
    int i = 1, bi = 0;
    
    while (dec != 0)
    {
        bit = dec % 2;
        dec = dec / 2;
        bi += bit * i;
        i =  i * 10;
    }
    
    printf("\nBinary equivalent = %d", bi);
    
    return bi;
}

int dectooctal(int dec)
{
    int octal = 0, i = 1;
        
    while (dec != 0)
    {
            octal += (dec % 8) * i;
            dec = dec / 8;
            i = i * 10;
    }
    
    printf("\nOctal equivalent = %d", octal);
    
    return octal;
}

int dectohex(int dec)
{
    int hex = 0, i = 1;
        
    while (dec != 0)
    {
            hex += (dec % 16) * i;
            dec = dec / 16;
            i = i * 10;
    }
    
    printf("\nHexadecimal equivalent = %d", hex);
    
    return hex;
}
