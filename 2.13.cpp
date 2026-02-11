#define _USE_MATH_DEFINES_
#include <stdio.h>
#include <math.h>



int main(){
double V, R, r, a, c;

printf("r, R:");
scanf("%lf %lf", &r, &R);
a=(R-r)/2.0;
c=(r+R)/2.0;


V=2.0*(M_PI*M_PI)*c*(a*a);

printf("volume torus: %.4f\n", V);
return 0;




}