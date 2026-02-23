#include <stdio.h>
#include <math.h>

void task20() {
    double x1, y1, x2, y2, x3, y3, px, py;

    printf("\nTask 20:\n");
    printf("Enter triangle vertices (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    printf("Enter point coordinates (px py): ");
    scanf("%lf %lf", &px, &py);


    double s = fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);

    double s1 = fabs((px*(y1 - y2) + x1*(y2 - py) + x2*(py - y1)) / 2.0);
    double s2 = fabs((px*(y2 - y3) + x2*(y3 - py) + x3*(py - y2)) / 2.0);
    double s3 = fabs((px*(y3 - y1) + x3*(y1 - py) + x1*(py - y3)) / 2.0);

    if (fabs(s - (s1 + s2 + s3)) < 0.01) {
        printf("Result: The point is INSIDE the triangle.\n");
    } else {
        printf("Result: The point is OUTSIDE the triangle.\n");
    }
}

void task23b() {
    double x, relu, derivative;

    printf("\nTask 23b:\n");
    printf("Enter x: ");
    scanf("%lf", &x);

    // function 
    if (x > 0) {
        relu = x;
    } else {
        relu = 0;
    }

    // Derivative 
    if (x > 0) {
        derivative = 1;
    } else {
        derivative = 0;
    }

    printf("ReLU value: %.2f\n", relu);
    printf("Derivative value: %.2f\n", derivative);
}

int main() {
    int choice;

    printf("Select task number (20 or 23): ");
    scanf("%d", &choice);

    if (choice == 20) {
        task20();
    } 
    else if (choice == 23) {
        task23b();
    } 
    else {
        printf("Error: Invalid task number.\n");
    }

    return 0;
}