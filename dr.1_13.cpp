#include <stdio.h>
#include <math.h>


int main() {
double x, result;
    printf("Enter x: ");
    scanf("%lf", &x);

    if (x <= 0) {
        printf("Error: Logarithm undefined for x <= 0\n");
    } else {
        result = log10(x);
        printf("Result: log10(%.2f) = %.3f\n", x, result);
    }
}

