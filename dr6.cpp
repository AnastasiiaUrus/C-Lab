#include <stdio.h>
#include <math.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int is_square_of_prime(int n) {
    if (n < 4) return 0;
    int s = (int)sqrt(n);
    if (s * s == n) return is_prime(s);
    return 0;
}

void task8a() {
    int n, count = 0;
    int arr[100];
    printf("Input size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (is_square_of_prime(arr[i])) {
            count++;
        }
    }
    printf("Result 8a: %d\n", count);
}

void task15() {
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    if (n < 0) n = -n;
    if (n == 0) {
        printf("Digit: 0\n");
        return;
    }
    int counts[10] = {0};
    while (n > 0) {
        counts[n % 10]++;
        n /= 10;
    }
    int max_count = 0;
    int result = 0;
    for (int i = 0; i < 10; i++) {
        if (counts[i] >= max_count && counts[i] > 0) {
            max_count = counts[i];
            result = i;
        }
    }
    printf("Digit: %d\n", result);
}

int main() {
    task8a();
    task15();
}