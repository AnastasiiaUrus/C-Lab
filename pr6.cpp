#include <stdio.h>
#include <math.h>

#define N1_2 5
#define N3 10
#define N4 5
#define N5 50
#define N6 10

/////////////////////////////////
void task1() {
    int mas[N1_2] = {1, 2, 3, 4, 5};
    double x;
    int count = 0;
    printf("\nTask 1 \nInput:");
    scanf("%lf", &x);
    for (int i = 0; i < N1_2; i++) {
        if (mas[i] < x) {
            count++;
        }
    }
    printf("Count of elements < %g: %d\n", x, count);
}

///////////////////////////////////


void reverse(int a[N1_2]) {
    for (int i = 0; i < N1_2 / 2; i++) {
        int tmp = a[i];
        a[i] = a[N1_2 - 1 - i];
        a[N1_2 - 1 - i] = tmp;
    }
}

void task2() {
    int mas[N1_2] = {5, 112, 4, 3, 1}; 
    printf("\n--- Task 2 ---\nOriginal: ");
    for(int i=0; i<4; i++) printf("%d ", mas[i]); 
    
    reverse(mas); 
    
    printf("\nReversed: ");
    for(int i=1; i<5; i++) printf("%d ", mas[i]);
    printf("\n");
}

//////////////////////////////////



int input_array_double(double ar[N3]) {
    for (int i = 0; i < N3; i++) {
        printf("input ar[%d] = ", i);
        int ch = scanf("%lf", &ar[i]);
        if (ch != 1) return i;
    }
    return N3;
}

double summary(double ar[N3]) {
    double y = 0;
    for (int i = 0; i < N3; i++) {
        if (ar[i] > M_E) { 
            y += ar[i];
        }
    }
    return y;
}

void task3() {
    double mas[N3];
    printf("\n Task 3 \n");
    int k = input_array_double(mas);
    double y = summary(mas);
    printf("Sum of elements > e: %lf\n", y);
}

////////////


int input_array_task4(int ar[N4]) {
    for (int i = 0; i < N4; i++) {
        printf("Input ar[%d] = ", i);
        int ch = scanf("%d", &ar[i]);
        if (ch != 1) return i;
    }
    return N4;
}

int max_array(int ar[], int n) {
    int maximum = ar[0];
    for (int i = 1; i < n; i++) {
        if (maximum < ar[i]) {
            maximum = ar[i];
        }
    }
    return maximum;
}

void task4() {
    int mas[N4];
    printf("\nTask 4 (From Blackboard)\n");
    int k = input_array_task4(mas);
    int maximum = max_array(mas, k);
    printf("maximum = %d\n", maximum);
}

////////////////////////////////////


int input_until_zero(int ar[N5]) {
    int i;
    for (i = 0; i < N5; i++) {
        printf("input ar[%d] (0 to stop): ", i);
        scanf("%d", &ar[i]);
        if (ar[i] == 0) break;
    }
    return i;
}

void task5_logic(int x[], int n) {
    int n1 = 0; // парні
    int n2 = 0; // непарні
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 0) {
            n1++;
        } else {
            n2++;
        }
    }
    printf("Even: %d, Odd: %d\n", n1, n2);
}

void task5() {
    int mas[N5];
    printf("\nTask 5\n");
    int count = input_until_zero(mas);
    task5_logic(mas, count);
}
#define N6 20
////////////////////////////////////


int input_array6(double ar[N6], int n){
    for(int i=0; i<n; i++){
        printf("ar[%d]=", i);
        int ch = scanf("%lf", &ar[i]);
        if (ch != 1) return i;
    }
    return n;
}

void sum_vec(double a[N6], double b[N6], double res[N6], int n){
    for(int i=0; i<n; i++){
        res[i] = a[i] + b[i];
    }
}

double scalar(double a[N6], double b[N6], int n){
    double y = 0;
    for(int i=0; i<n; i++){
        y += a[i] * b[i];
    }
    return y;
}

void task6(){
    double a[N6], b[N6], c[N6];
    int n;
    printf("\nTask 6\nInput n:");
    scanf("%d", &n);

    printf("Input vector a:\n");
    input_array6(a, n);
    printf("Input vector b:\n");
    input_array6(b, n);

    sum_vec(a, b, c, n);
    
    printf("Sum result: ");
    for(int i=0; i<n; i++) printf("%lf ", c[i]);

    double res = scalar(a, b, n);
    printf("\nScalar product = %lf\n", res);
}
int main() {

    //task1();
    //task2();
    //task3();
    //task4();
    //task5();
    task6();
}