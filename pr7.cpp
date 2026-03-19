#include <stdio.h>

#define N 25

void print_matrix(double matrix[N][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%7.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функція для Задачі 3 та 4
int input_matrix_with_hints(double matr[N][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            if (scanf("%lf", &matr[i][j]) != 1) return -1;
        }
    }
    return 0;
}



void task1() {
    double matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    double n_val, m_val;
    printf("n, m: ");
    scanf("%lf %lf", &n_val, &m_val);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(matrix[i][j] == n_val) matrix[i][j] = m_val;
    print_matrix((double(*)[N])matrix, 3, 3); 
}

void task2() {
        double matrix[3][3] = {{1.0, 2.3, 3.0}, {4.5, 5.0, 6.0}, {7.8, 9.0, 10.0}};
    int i, j; double a;
    printf("Input indices i, j and new value a: ");
    scanf("%d %d %lf", &i, &j, &a);
    if(i >= 0 && i < 3 && j >= 0 && j < 3) {
        matrix[i][j] = a;
        print_matrix((double(*)[N])matrix, 3, 3);
    } else printf("Error: Index out of bounds!\n");
}

void task3_4() {
    double matrix[N][N]; int n, m;
    printf("Input dimensions n m (less than 25): ");
    scanf("%d %d", &n, &m);
    input_matrix_with_hints(matrix, n, m);
    print_matrix(matrix, n, m);
}

void task5() {
    double a[N][N]; int n;
    printf("Input size of square matrix: ");
    scanf("%d", &n);
    input_matrix_with_hints(a, n, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            double temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    printf("Result:\n");
    print_matrix(a, n, n);
}

void task6() {
    double matrix[N][N], sum = 0; int n, m, k;
    printf("Input n, m and k: ");
    scanf("%d %d %d", &n, &m, &k);
    input_matrix_with_hints(matrix, n, m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(i - j == k) sum += matrix[i][j];
    printf("Sum of elements where i-j=%d is: %.2lf\n", k, sum);
}

void task7() {
    double m[3][3];
    printf("Input 3x3 matrix:\n");
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) scanf("%lf", &m[i][j]);
    double det = m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1]
               - m[0][2]*m[1][1]*m[2][0] - m[0][0]*m[1][2]*m[2][1] - m[0][1]*m[1][0]*m[2][2];
    
    printf("Determinant of 3x3 matrix: %.2lf\n", det);
}

int main() {
    task1();
    task3_4();
    task5();
    task6();
    task7();
    }
