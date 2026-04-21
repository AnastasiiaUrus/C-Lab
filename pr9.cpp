#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Date {int day, month, year;};
struct Field {char col; int row;};
struct Point {int x, y;};
struct Rect {Point p1, p2;};
struct Poly {int degree; double* coeffs;};
struct Rational {int num; unsigned int den;};
struct Mountain {string name; int height;};

bool is_queen_move(Field f1, Field f2) {
    if (f1.col == f2.col || f1.row == f2.row) return true;
    if (abs(f1.col - f2.col) == abs(f1.row - f2.row)) return true;
    return false;
}

Date get_next_day(Date d) {
    d.day++;
    if (d.day > 30) {
        d.day = 1;
        d.month++;
        if (d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

Rational simplify(Rational r) {
    int a = abs(r.num);
    unsigned int b = r.den;
    while (b != 0) {
        unsigned int t = b;
        b = a % b;
        a = t;
    }
    r.num /= a;
    r.den /= a;
    return r;
}

Rational add_rat(Rational a, Rational b) {
    Rational res;
    res.num = a.num * b.den + b.num * a.den;
    res.den = a.den * b.den;
    return simplify(res);
}

Rational mult_rat(Rational a, Rational b) {
    Rational res;
    res.num = a.num * b.num;
    res.den = a.den * b.den;
    return simplify(res);
}

void compare_rat(Rational a, Rational b) {
    double v1 = (double)a.num / a.den;
    double v2 = (double)b.num / b.den;
    if (v1 > v2) cout << "First > Second" << endl;
    else if (v1 < v2) cout << "First < Second" << endl;
    else cout << "Equal" << endl;
}

void task5() {
    int n;
    cout << "n=";
    cin >> n;
    Mountain* m = new Mountain[n];
    for(int i = 0; i < n; i++) {
        cin >> m[i].name >> m[i].height;
    }
    int max_h = -1;
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(m[i].height > max_h) {
            max_h = m[i].height;
            idx = i;
        }
    }
    if(idx != -1) cout << m[idx].name << endl;
    else cout << "None" << endl;
    delete[] m;
}

int main() {
    Field f1 = {'a', 1}, f2 = {'b', 2};
    if(is_queen_move(f1, f2)) cout << "Move possible" << endl;

    Date d = {25, 4, 2026};
    Date tomorrow = get_next_day(d);
    cout << tomorrow.day << "." << tomorrow.month << "." << tomorrow.year << endl;

    Rational r1 = {1, 2}, r2 = {1, 3};
    Rational sum = add_rat(r1, r2);
    cout << sum.num << "/" << sum.den << endl;

    task5();
}