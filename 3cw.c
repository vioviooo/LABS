#include <math.h>
#include <stdio.h>
#include <stdbool.h> 

int main(void) {

    printf("%s", "Input the number of segmentations: ");

    int N;
    scanf("%d", &N);

    long double a = 0.0, b = 0.5;

    long double step = (b - a) / N;

    long double x = a;

    long double eps = 1.0;
    while (1.0 + eps / 2.0 > 1) {
        eps /= 2;
    }

    printf(" ");

    for (int x = 0; x < 96; x++) {
        printf("_");
    }

    printf("\n|\tx\t|\t  Taylor's Function  \t|\t   Function      \t|   Iterations\t|");

    printf("\n");

    printf("|_______________|_______________________________|_______________________________|_______________|\n");

    // printf("\n");

    for (int i = 0; i <= N; i++) {

        long double row0 = -((4 * x * x) / 2);
        long double taylor_function = row0;

        int x0 = 2, num_of_operations = 0;

        bool flag = true;

        for (int n = 0; n < 100 && flag; n++) {

            row0 = (-1) * row0 * ((4 * x * x) / ((x0 + 1) * (x0 + 2)));

            // long double eps_curr = eps * abs(row0);

            if (abs(row0) < eps) {
                flag = false;
                num_of_operations = n;
            }

            taylor_function += row0;
            x0 += 2;

        }

        long double function = 2 * (cos(x) * cos(x) - 1);
        
        printf("|\t%.3Lf\t|\t%.20Lf\t|\t%.20Lf\t|\t%d\t| \n", x, taylor_function, function, num_of_operations);

        x += step;
    }

    printf("|_______________|_______________________________|_______________________________|_______________|\n");

    //cout << endl << timing();
    
    return 0;
}