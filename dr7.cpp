#include <stdio.h>
#define N 25

int input_matrix(double matr[N][N], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("a[%d][%d] =", i, j);
            if(scanf("%lf", &matr[i][j]) != 1) return -1;
        }
    }
    return 0;
}

void print_matrix(double matrix[N][N], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%7.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void task20(){
    double a[N][N], b[N][N];
    int n, m, k;
    
    printf("Input n, m, k: ");
    scanf("%d %d %d", &n, &m, &k);
    
    input_matrix(a, n, m);
    
    k = k % m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            b[i][(j + k) % m] = a[i][j];
        }
    }
    
    printf("Result:\n");
    print_matrix(b, n, m);
}

int main(){
    task20();
}