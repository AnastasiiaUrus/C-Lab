#include <stdio.h>
#include <math.h>


double sigmoid(double x){

    return 1.0 / (1.0 + exp(-x));

}

double sigmoid_poh( double x){

    double s = sigmoid(x);
    return s * (1.0 - s );

}


int main(){

double x;

printf("x:");
scanf("%lf", &x);

printf("sigmoid f(x)= %.4f\n", sigmoid(x));
printf("sigmoid_poh f`(x)= %.4f\n", sigmoid_poh(x));

return 0;
}