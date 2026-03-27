#include <stdio.h>
#include <math.h>


// Обчислення x_k = ((-1)^k * x^(2k+1)) / (2k+1)!
void task18() {
    printf("\nTask 18 \n");
    double x;
    int k_limit;
    
    printf("Введіть значення x: ");
    scanf("%lf", &x);
    printf("Введіть номер елемента k (k >= 0): ");
    scanf("%d", &k_limit);

    // Перший елемент x_0 (при k=0): (-1)^0 * x^(2*0+1) / (2*0+1)! = x / 1 = x
    double term = x; 

    // Коефіцієнт переходу: (-x^2) / (2k * (2k + 1))
    for (int k = 1; k <= k_limit; k++) {
        term = term * (-x * x) / ((2 * k) * (2 * k + 1));
    }

    printf("Результат x_%d = %.10lf\n", k_limit, term);
}

void task27() {
    printf("\nTask 27\n");
    double eps;
    printf("Введіть точність eps : ");
    scanf("%lf", &eps);

    double sum = 0;
    double term;
    int k = 0;
    double power_of_16 = 1.0;

    do {
 
        double bracket = (8.0 / (8 * k + 2)) + 
                         (4.0 / (8 * k + 3)) + 
                         (4.0 / (8 * k + 4)) - 
                         (1.0 / (8 * k + 7));
        
        
        // (k % 2 == 0 ? 1 : -1) реалізує чергування знаку (-1)^k
        term = (k % 2 == 0 ? 1.0 : -1.0) * bracket / power_of_16;
        
        sum += term;
        k++;
        power_of_16 *= 16.0;
        
    } while (fabs(term) > eps);
    double pi = sum / 2.0; 
    printf("Обчислене пі = %.10lf (ітерацій: %d)\n", pi, k);
}



int main() {
    task18();
    task27();
}