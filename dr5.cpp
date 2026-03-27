#include <stdio.h>
#include <math.h>

void task_12b() {
    int n;
    double u, v;
    printf("\nTask 12b\n");
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter u and v: ");
    scanf("%lf %lf", &u, &v);

    double s = 0, ak = u, bk = v;

    for (int k = 1; k <= n; k++) {
        double fact = 1;
        for (int i = 1; i <= k + 1; i++) fact *= i;

        s += (ak * bk) / fact;

        double next_a = (ak / (k + 1.0)) + ak + bk;
        double next_b = 2 * bk + ak;
        ak = next_a;
        bk = next_b;
    }
    printf("Result Sn = %lf\n", s);
}

void task_16d() {
    double x, eps;
    printf("\nTask 16d\n");
    printf("Enter x and eps: ");
    scanf("%lf %lf", &x, &eps);

    double y = 1.0, ak = 1.0;
    int k = 1;
    while (fabs(ak) >= eps) {
        ak = ak * (x / k);
        y += ak;
        k++;
        if (k > 10000) break;
    }
    printf("Result y = %lf\n", y);
}

int main() {
    task_12b();
    task_16d();
}