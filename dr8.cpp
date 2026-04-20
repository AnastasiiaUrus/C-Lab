#include <stdio.h>
#include <stdlib.h>

double** add_row_to_end(double** matrix, int* n, int m) {
    matrix = (double**)realloc(matrix, (*n + 1) * sizeof(double*));
    matrix[*n] = (double*)malloc(m * sizeof(double));
    for (int j = 0; j < m; j++) {
        scanf("%lf", &matrix[*n][j]);
    }
    (*n)++;
    return matrix;
}

void task9v() {
    int n, m;
    printf("Input n, m: ");
    scanf("%d %d", &n, &m);
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) scanf("%lf", &matrix[i][j]);
    }
    matrix = add_row_to_end(matrix, &n, m);
    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%7.2f ", matrix[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

void task10() {
    int n, m;
    printf("Input n, m: ");
    scanf("%d %d", &n, &m);
    double** matrix = (double**)malloc(n * sizeof(double*));
    double product = 1.0;
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
            product *= matrix[i][j];
        }
    }
    printf("Product: %7.2f\n", product);
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

int main() {
    task9v();
    task10();
}