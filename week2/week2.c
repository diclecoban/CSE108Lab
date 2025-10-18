#include <stdio.h>
#include <math.h>
#define PI 3.14

void part1();
float part2();


int main()
{
    printf("** PART ONE**\n");
    
    part1();
    
    printf("** PART TWO**\n");
    
    part2();
    
}

void part1()
{
    int cube, a, b, c, d, e, f;
    
    printf("Please enter the edge length for cube: ");
    scanf("%d", &cube);
    
    // I made temporary floats of Surface Area and Volume for cube.
    
    float CubeTemp1 = 6*pow(cube,2);
    float CubeTemp2 = pow(cube,3);
    printf("Surface area = %2f   Volume = %2f \n", CubeTemp1, CubeTemp2);
    
    printf("Please enter the side length for prism: ");
    scanf("%d", &a);
    printf("Please enter the side width for prism: ");
    scanf("%d", &b);
    printf("Please enter the side height for prism: ");
    scanf("%d", &c);
    
    // I made temporary floats of Surface Area and Volume for prism.
    
    float PrismTemp1 = 2*(a*b + b*c + a*c);
    float PrismTemp2 = a*b*c;
    printf("Surface area = %2f   Volume = %2f \n", PrismTemp1, PrismTemp2);
    
    printf("Please enter the radius for sphere: ");
    scanf("%d", &d);
    
    // I made temporary floats of Surface Area and Volume for sphere.
    
    float SphereTemp1 = 4*PI*pow(d,2);
    float SphereTemp2 = (4*PI*pow(d,3))/3;
    printf("Surface area = %2f   Volume = %2f \n", SphereTemp1, SphereTemp2);
   
    printf("Please enter the radius for cone: ");
    scanf("%d", &e);
    printf("Please enter the height for cone: ");
    scanf("%d", &f);
    
    // I made temporary floats of Surface Area and Volume for cone.
    
    float ConeTemp1 = PI*e*(sqrt(e*e +f*f)+ e);
    float ConeTemp2 = (PI*e*e*f)/3;
    printf("Surface area = %2f   Volume = %2f \n", ConeTemp1, ConeTemp2);
}

float part2()
{
    float height, weight;
    float BMI;
    
    printf("Please enter your weight(kg) and height(m): ");
    scanf("%f %f", &weight, &height);
    
    BMI = weight/(height*height);
    
    printf("Your BMI is %2f\n ", BMI);
    
    if(BMI<18.5)
    {
        printf("underweight.\n");
    }
    else if(BMI>=18.5 && BMI<=24.9)
    {
        printf("average weight.\n");
    }
    else if(BMI>24.9 && BMI<=29.9)
    {
        printf("overweigth.\n");
    }
    else if(BMI>=30)
    {
        printf("obese.\n");
    }
    return BMI;
}
