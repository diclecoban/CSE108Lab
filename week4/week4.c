#include <stdio.h>

int Generate_file();
int Read_file();
int shape_triangle();
int shape_square();

FILE *fileshape;
char shape;
int i,j,size,op,k;
int spaces, stars;

int main()
{
    
    printf("Welcome to Shape Reader! Please make your choice to continue:\n");
    printf("1-) Generate a shape file.\n");
    printf("2-) Read and draw a shape file.\n");
    printf("3-) Terminate the program.\n");
    printf("Your choice: ");
    scanf("%d", &op);
    
    switch(op)
    {
        case 1:
            Generate_file();
            break;
        case 2:
            Read_file();
            break;
        case 3:
            return 0;
            break;
    }
    
    Read_file();

    return 0;
}

int Generate_file()
{
   
    fileshape = fopen("shapes.txt", "w");
    
    printf("Please choose your shape(s = square, t = triangle): ");
    scanf(" %c", &shape);
    
    switch(shape)
    {
        case 's' :
            printf("Please enter the size: ");
            scanf("%d", &size);
            while(size<3 || size>10)
            {
                printf("Invalid size. Please try again.\n");
                printf("Please enter the size: ");
                scanf("%d", &size);
            }
            fprintf(fileshape, " %c,%d", shape, size);
            break;
        case 't' :
            printf("Please enter the size: ");
            scanf("%d", &size);
            while(size<3 || size>10)
            {
                printf("Invalid size. Please try again.\n");
                printf("Please enter the size: ");
                scanf("%d", &size);
            }
            fprintf(fileshape, " %c,%d", shape, size);
            break;
        case 'e' :
            fclose(fileshape);
            break;
        default:
            printf("Invalid shape type.\n");
    }
    
    fclose(fileshape);
    return 0;
    
    
    
}

int Read_file()
{
    while (fileshape == NULL)
    {
            printf("You can't continue with empty file!\n");
        main();
    }
    
    switch(shape)
    {
        case 's' :
            shape_square();
            break;
        case 't' :
            
            shape_triangle();
            break;
    }
    return 0;
}
 int shape_square()
{
     
     fileshape = fopen("shapes.txt", "r");
     
     fscanf(fileshape, " %c,%d", &shape, &size);
     fclose(fileshape);
    
     switch(shape)
     {
         case 's' :
             
             for (int i = 0; i < size; ++i)
             {
                 for (int j = 0; j < size; ++j)
                 {
                     if ((i == 0) || (i == size-1) || (j == 0) || (j == size-1))
                     {
                         printf("*");
                     }
                     else
                     {
                         printf(" ");
                     }
                 }
                 printf("\n");
             }
             
             break;
     }
     return 0;
}

int shape_triangle()
{
    
    fileshape = fopen("shapes.txt", "r");
    
    fscanf(fileshape, " %c,%d", &shape, &size);
    fclose(fileshape);
    
    for (i = 1; i <= size; ++i)
    {
        spaces = size - i;
        stars = 2 * i - 1;
        
        for (j = 1; j <= spaces; j++) {
            printf(" ");
        }
        
        for (k = 1; k <= stars; k++) {
            if (k == 1 || k == stars || i == size) {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        
        printf("\n");
    }

    return 0;
}

   

