#include <stdio.h>
#include <math.h>

void task1() {
    double x, y;
    int n;
    printf("\nTask 1 \nEnter x and n: ");
    scanf("%lf %d", &x, &n);
    y = x;
    for (int i = 0; i < n; i++) {
        y = sin(y);
    }
    printf("Result: %lf\n", y);
}

void task2() {
    int n;
    double fact = 1;
    printf("\n Task 2\nEnter n: ");
    scanf("%d", &n);
    
    printf("%d! = ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d%s", i, (i == n ? "" : "*"));
        fact *= i;
    }
    printf("\nResult: %.0f\n", fact);
}

void task3() {
    printf("\nTask 3\n");
    int n = 3; double x = 2, y = 0;
    for (int i = n; i >= 0; i--) y += pow(x, i);
    printf("a) Result: %.1lf\n", y);

    n = 4; x = 1; double y_val = 2, res = 0;
    for (int i = n; i >= 0; i--) res += pow(x, 2 * i) * pow(y_val, i);
    printf("b) Result: %.1lf\n", res);
}

void task4() {
    int n; double x, res = 0;
    printf("\nTask 4\nEnter n and x: ");
    scanf("%d %lf", &n, &x);
    for (int i = 1; i <= n; i++) {
        res += i * pow(x, i);
    }
    printf("Result: %lf\n", res);
}

void task5() {
    int n; double res = 1;
    printf("\nTask 5\nEnter n: ");
    scanf("%d", &n);
    for (int i = n; i > 0; i -= 2) {
        res *= i;
    }
    printf("%d!! = %.0f\n", n, res);
}

void task6() {
    int n;
    printf("\n Task 6\nEnter n: ");
    scanf("%d", &n);
    double resA = 0;
    for (int i = 0; i < n; i++) resA = sqrt(2 + resA);
    printf("a) Result: %lf\n", resA);

    double resB = 0;
    for (int i = n; i >= 1; i--) resB = sqrt(3 * i + resB);
    printf("b) Result: %lf\n", resB);
}

void task7() {
    double x, res = 1.0, term = 1.0;
    int n;
    printf("\nTask 7\nEnter x and n: ");
    scanf("%lf %d", &x, &n);
    for (int i = 1; i <= n; i++) {
        term *= x / i;
        res += term;
    }
    printf("Result: %lf\n", res);
}

void task8() {
    int m, k = 0;
    double val = 1;
    printf("\nTask 8\nEnter m: ");
    scanf("%d", &m);
    while (val * 4 <= m) {
        val *= 4;
        k++;
    }
    printf("Max k: %d\n", k);
}

void task9() {
    int n;
    double res = 1;
    printf("\n Task 9 \nEnter n: ");
    scanf("%d", &n);
    while (res <= n) {
        res *= 2;
    }
    printf("Result: %.0f\n", res);
}

void task10() {
    float a = 1.0f;
    while (1.0f + a / 2.0f != 1.0f) {
        a /= 2.0f;
    }
    printf("\nTask 10\nMachine zero: %e\n", a);
}

void task11() {
    double num, sum = 0, prod = 1;
    int count = 0;
    printf("\n Task 11 \nEnter numbers (0 to stop):\n");
    do {
        printf("a[%d]= ", count);
        scanf("%lf", &num);
        if (num != 0) {
            sum += num;
            prod *= num;
            count++;
        }
    } while (num != 0);

    if (count > 0) {
        printf("Average: %lf\n", sum / count);
        printf("Geometric mean: %lf\n", pow(prod, 1.0 / count));
    }
}

void task12() {
    int n;
    printf("\nTask 12\nEnter n: ");
    scanf("%d", &n);
    
    if (n == 0) { printf("!0 = 1\n"); return; }
    if (n == 1) { printf("!1 = 0\n"); return; }

    double p2 = 1; // !0
    double p1 = 0; // !1
    double cur = 0;

    for (int i = 2; i <= n; i++) {
        cur = (i - 1) * (p1 + p2);
        p2 = p1;
        p1 = cur;
    }
    printf("!%d = %.0f\n", n, cur);
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    task11();
    task12();
}