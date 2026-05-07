#ifndef __RAT2_h__
#define __RAT2_h__

#include <iostream>
#include <cmath>

using namespace std;

class Point {
    double x, y;
    static int count;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) { count++; }
    Point(const Point& p) : x(p.x), y(p.y) { count++; }
    ~Point() { count--; }
    static int getCount() { return count; }
    double dist(Point p) { return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)); }
};

class Polinome {
    double* c;
    int n;
public:
    Polinome() : c(nullptr), n(0) {}
    Polinome(int n) {
        c = new double[n];
        this->n = n;
    }
    ~Polinome() {
        delete[] this->c;
    }
    Polinome(const Polinome& p) {
        n = p.n;
        c = new double[n];
        for (int i = 0; i < n; i++) c[i] = p.c[i];
    }
    Polinome(int n, double* d) {
        c = new double[n];
        this->n = n;
        for (int i = 0; i < n; i++) {
            c[i] = d[i];
        }
    }
    void set(int k, double a) {
        if (k < n) { c[k] = a; }
    }
    void show() {
        if (n > 0) cout << c[0];
        for (int i = 1; i < n; i++) {
            cout << (c[i] >= 0 ? "+" : "") << c[i] << "*x^" << i;
        }
        cout << "\n";
    }
};

#endif