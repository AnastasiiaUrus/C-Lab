#ifndef __RAT_h__
#define __RAT_h__

#include <iostream>
#include <fstream>

using namespace std;

class Rational {
    int num; 
    unsigned den;
public:
    Rational(int x, unsigned y) {
        num = x;
        den = y;
    }
    Rational() {
        num = 0;
        den = 1;
    }

    void input();
    void output();
    Rational add(Rational z);
    Rational mul(Rational z);
    bool less(Rational z);

private:
    unsigned gcd(int a, int b) {
        a = abs(a);
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    void reduce() {
        if (den == 0) return;
        unsigned a = gcd(num, den);
        num = num / a;
        den = den / a;
    }

public:
    void save(const char *f) {
        ofstream g(f, ios::app);
        if (!g.is_open()) {
            cout << "Cannot open file :((" << f;
            return;
        }
        g << num << "/" << den << " ";
        g.close();
    }
};

#endif