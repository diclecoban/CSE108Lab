#include <stdio.h>

void part1(int m, int n, int b);
void part2(int x, int y, int z);
void part3(float n1, float n2, float n3);

int main()
{
    
    int a,b,c;
    part1(a,b,c);
    
    int d,e,f;
    part2(d,e,f);
    
    float o,s,p;
    part3(o,s,p);
    
}

void part1(int n, int m, int k)
{
    printf("Please enter three numbers: ");
    scanf("%d %d %d", &m, &n, &k);
    
    if(n>m)
    {
        if(m>k)
        {
            printf("Median number is: %d\n", m);
        }
        else
        {
            if(n>k)
            {
                printf("Median number is: %d\n", k);
            }
        }
        if(k>n)
        {
            printf("Median number is: %d\n", n);
        }
    }
    else
    {
        if(n>k)
        {
            printf("Median number is: %d\n", n);
        }
        else
        {
            if(m>k)
            {
                printf("Median number is: %d\n", k);
            }
        }
        if(k>m)
        {
            printf("Median number is: %d\n", m);
        }
    }
    
}
void part2(int x, int y, int z)
{
    printf("Please enter your 3 exams: ");
    scanf("%d %d %d", &x, &y, &z);
    
    float av = (x+y+z)/3;
    
    switch(x/10)
    {
        case 10:
        case 9:
            printf("Your grades A+,");
            break;
        case 8:
            printf("Your grades A, ");
            break;
        case 7:
            printf("Your grades B+, ");
            break;
        case 6:
            printf("Your grades B, ");
            break;
        case 5:
            printf("Your grades C, ");
            break;
        case 4:
            printf("Your grades D, ");
        default:
            printf("Your grades F, ");
            break;
    }
    
    switch(y/10)
    {
        case 10:
        case 9:
            printf("A+ ");
            break;
        case 8:
            printf("A ");
            break;
        case 7:
            printf("B+ ");
            break;
        case 6:
            printf("B ");
            break;
        case 5:
            printf("C ");
            break;
        case 4:
            printf("D ");
        default:
            printf("F ");
            break;
    }
    switch(z/10)
    {
        case 10:
        case 9:
            printf("and A+ ");
            break;
        case 8:
            printf("and A ");
            break;
        case 7:
            printf("and B+ ");
            break;
        case 6:
            printf("and B ");
            break;
        case 5:
            printf("and C ");
            break;
        case 4:
            printf("and D ");
            break;
        default:
            printf("and F ");
            break;
    }
    
    printf("with an %2f average.", av);
}

    void part3(float n1, float n2, float n3)
    {
        float result=0;
        char op;
        
        printf("\nPlease enter an operator(+ , -, /, *): ");
        scanf(" %c", &op);
        printf("Please enter your numbers: ");
        scanf("%2f %2f", &n1, &n2);
        printf("Please enter your result: ");
        scanf("%2f", &n3);
        
        switch (op)
        {
            case '+': result = n1+n2;
                if(n3 == result)
                {
                    printf("Bravo, Your answer is correct.\n");
                }
                else
                {
                    printf("Wrong answer, try again.\n");
                }
                break;
            case '-': result = n1-n2;
                if(n3 == result)
                {
                    printf("Bravo, Your answer is correct.\n");
                }
                else
                {
                    printf("Wrong answer, try again.\n");
                }
                break;
            case '/': result = n1/n2;
                if(n3 == result)
                {
                    printf("Bravo, Your answer is correct.\n");
                }
                else
                {
                    printf("Wrong answer, try again.\n");
                }
                break;
            case '*': result = n1*n2;
                if(n3 == result)
                {
                    printf("Bravo, Your answer is correct.\n");
                }
                else
                {
                    printf("Wrong answer, try again.\n");
                }
                break;
        }
    }


