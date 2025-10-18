#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double array[3][3];
    double determinant;
}Matrix;

typedef struct {
    double x;
    double y;
    double z;

}vector;

typedef struct {
    double a3;
    double a2;
    double a1;
    double a0;
} third_order_polynomial;

typedef struct {
    char constant;
    double a2;
    double a1;
    double a0;
    double value;
} polynomial;


void print_matrix(Matrix initial);
void inverse_matrix(Matrix *initial, Matrix *inverted);
void determinant_of_matrix(Matrix *initial);
double find_orthogonal(vector vec1, vector vec2, vector* output_vec);
polynomial integrate_polynomials(third_order_polynomial p1, third_order_polynomial p2, double a, double b);

int main()
{
   /* Matrix initial = {
        {1, 0.9134, 0.2785},
        {0.9058, 0.6324, 0.5469},
        {0.1270, 0.0975, 0.9575},
    0}; */ // şu tanımlamada bir hata alıyorum
    
  // print_matrix(initial);
    
    vector vec_1 = {4.0, 6.0, 8.0};
       vector vec_2 = {2.0, 5.0, 8.0};
       vector output_vec;
       double angle = find_orthogonal(vec_1, vec_2, &output_vec);
       printf("The angle between vec_1 and vec_2 is %.3lf degrees\n", angle);
    
    third_order_polynomial p1, p2;
        double a, b;
        
        printf("Enter the coefficients of the first polynomial (a3, a2, a1, a0): ");
        scanf("%lf %lf %lf %lf", &p1.a3, &p1.a2, &p1.a1, &p1.a0);
        
        printf("Enter the coefficients of the second polynomial (a3, a2, a1, a0): ");
        scanf("%lf %lf %lf %lf", &p2.a3, &p2.a2, &p2.a1, &p2.a0);
        
        printf("Enter the interval values (a, b): ");
        scanf("%lf %lf", &a, &b);
        
        polynomial p = integrate_polynomials(p1, p2, a, b);
        
        printf("Integrated polynomial coefficients: %c %.2lf %.2lf %.2lf\n", p.constant, p.a2, p.a1, p.a0);
        printf("Integrated polynomial value between [%lf, %lf]: %.2lf\n", a, b, p.value);
    
    
}

void print_matrix(Matrix initial)
{
    
    // burada sıkıntı yok ama print edemiyorum
    
    int i,j;
    
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            printf("The matrix array is :\n%8.4lf", initial.array[i][j]);
        }
        
        printf("\n");
        
    }
    printf("\n");
}

void determinant_of_matrix(Matrix *initial)
{
    
    // bazı struct bilgisi eksiklerim var
    
    /*
        double a = initial_matrix->array[0][0];
        double b = initial_matrix->array[0][1];
        double c = initial_matrix->array[0][2];
        double d = initial_matrix->array[1][0];
        double e = initial_matrix->array[1][1];
        double f = initial_matrix->array[1][2];
        double g = initial_matrix->array[2][0];
        double h = initial_matrix->array[2][1];
        double i = initial_matrix->array[2][2];

        double det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
        initial_matrix->determinant = det;
    }
    void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix)
     {
        determinant_of_matrix(initial_matrix);
        double det = initial_matrix->determinant;

        if (det == 0)
     {
            printf("Error: The matrix is not invertible.\n");
            return;
        }

        double a = initial_matrix->array[0][0];
        double b = initial_matrix->array[0][1];
        double c = initial_matrix->array[0][2];
        double d = initial_matrix->array[1][0];
        double e = initial_matrix->array[1][1];
        double f = initial_matrix->array[1][2];
        double g = initial_matrix->array[2][0];
        double h = initial_matrix->array[2][1];
        double i = initial_matrix->array[2][2];

        double inv_det = 1.0 / det;

        inverted_matrix->array[0][0] = (e * i - f * h) * inv_det;
        inverted_matrix->array[0][1] = (c * h - b * i) * inv_det;
        inverted_matrix->array[0][2] = (b * f - c * e) * inv_det;
        inverted_matrix->array[1][0] = (f * g - d * i) * inv_det;
        inverted_matrix->array[1][1] = (a * i - c * g) * inv_det;
        inverted_matrix->array[1][2] = (c * d - a * f) * inv_det;
        inverted_matrix->array[2][0] = (d * h - e * g) * inv_det;
        inverted_matrix->array[2][1] = (b * g - a * h) * inv_det;
        inverted_matrix->array[2][2] = (a * e - b * d) * inv_det;
        inverted_matrix->determinant = det;

        printf("Inverted Matrix:\n");
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%.2f ", inverted_matrix->array[i][j]);
            }
            printf("\n");
        }
     */
}

double find_orthogonal(vector vec1, vector vec2, vector* output_vec)
{
   /* vector vector;
    printf("Please enter the vec1 as 3D: ");
    scanf("%lf %lf %lf", &vector.x1, &vector.y1, &vector.z1);
    
    printf("Please enter the vec2 as 3D: ");
    scanf("%lf %lf %lf", &vector.x2, &vector.y2, &vector.z2);
    
    double numerator = (vector.x1*vector.x2) + (vector.y1*vector.y2) + (vector.z1*vector.z2);
    
    double denominator = (sqrt(pow(vector.x1,2)+pow(vector.y1,2)+pow(vector.z1,2)))*(sqrt(pow(vector.x2,2)+pow(vector.y2,2)+pow(vector.z2,2)));
    
    double angle = acos(numerator/denominator);
    
    double result = (vector.y1*vector.z2 - vector.z1*vector.y2) - (vector.x1*vector.z2 - vector.z1*vector.x2) + (vector.x1*vector.y2 - vector.y1*vector.x2);
    
    printf("The angle between two vectors is %lf\n", angle);
    printf("The result of the cross product is %lf", result); */
    
    // Üstteki kısım çalışmadı beceremedim
    
    double dot = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z; // scaler product
    
    double vec1_result = sqrt(vec1.x * vec1.x + vec1.y * vec1.y + vec1.z * vec1.z); // denominator part (payda)
    
    double vec2_resultresult = sqrt(vec2.x * vec2.x + vec2.y * vec2.y + vec2.z * vec2.z); // denominator part (payda)
    
    double angle = dot / (vec1_result * vec2_resultresult);
    
    double cosangle = acos(angle) * 180 / M_PI; // açının arccos buluyor
    
    output_vec-> x = vec1.y * vec2.z - vec1.z * vec2.y; // x'in outputu
    
    output_vec-> y = vec1.z * vec2.x - vec1.x * vec2.z; // y'nin outputu
    
    output_vec-> z = vec1.x * vec2.y - vec1.y * vec2.x; // z'nin outputu
    
    printf("The cross product of vec1 and vec2 is: (%.2lf, %.2lf, %.2lf)\n",output_vec-> x,output_vec-> y,output_vec-> z );
    
    
    return angle;

}

polynomial integrate_polynomials(third_order_polynomial p1, third_order_polynomial p2, double a, double b)
{
    polynomial result;
    
    result.constant = 'C'; // constant C tanımlama
    
    double c3 = (p1.a3 * p2.a3) / 4.0;
    double c2 = (p1.a2 * p2.a3 + p1.a3 * p2.a2) / 3.0;
    double c1 = (p1.a1 * p2.a3 + p1.a2 * p2.a2 + p1.a3 * p2.a1) / 2.0;
    double c0 = (p1.a0 * p2.a3 + p1.a1 * p2.a2 + p1.a2 * p2.a1 + p1.a3 * p2.a0);
    
    result.a2 = c3 / 4.0;
    result.a1 = c2;
    result.a0 = c1;
    
    double f_b = (result.a2 * pow(b, 4) / 4.0 + result.a1 * pow(b, 3) / 3.0 + result.a0 * pow(b, 2) / 2.0 + c0 * b);
    
    double f_a = (result.a2 * pow(a, 4) / 4.0 + result.a1 * pow(a, 3) / 3.0 + result.a0 * pow(a, 2) / 2.0 + c0 * a);
    
    result.value = f_b - f_a; //intervals
    
    return result;
}
