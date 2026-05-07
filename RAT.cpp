#include <iostream>
#include <vector>
#include <string>
#include "Rat.h"
#include "Rat2.h"

using namespace std;

int Point::count = 0;

void Rational::input() {
    cout << "Input nom and den: ";
    cin >> num >> den;
    if (den == 0) den = 1;
}

void Rational::output() {
    cout << num << "/" << den << "\n";
}

Rational Rational::add(Rational z) {
    Rational n;
    n.num = num * z.den + z.num * den;
    n.den = den * z.den;
    return n;
}

Rational Rational::mul(Rational z) {
    Rational n;
    n.num = num * z.num;
    n.den = den * z.den;
    return n;
}

bool Rational::less(Rational z) {
    return (long long)num * z.den < (long long)z.num * den;
}

int main() {
    int n;
    cin >> n;
    Rational* mas = new Rational[n];
    for (int i = 0; i < n; i++) {
        mas[i].input();
    }
    
    Rational q = mas[0];
    for (int i = 1; i < n; i++) {
        if (mas[i].less(q))
            q = mas[i];
    }
    q.output();

    int k = 1;
    Rational eps(1, 100);
    Rational S(0, 1);
    Rational t(1, 1);
    
    while (eps.less(t)) {
        if (k % 2 != 0) t = Rational(1, k * k);
        else t = Rational(-1, k * k);
        
        S = S.add(t);
        k++;
        t = Rational(1, k * k);
    }
    S.output();

    vector<Point> pts;
    string choice;
    do {
        double px, py;
        cout << "Введіть x y точки: ";
        cin >> px >> py;
        pts.push_back(Point(px, py));
        cout << "Ввести вершину? (Так/Ні): ";
        cin >> choice;
    } while (choice != "Ні" && choice != "No");

    double perim = 0;
    for (size_t i = 0; i < pts.size(); i++) {
        perim += pts[i].dist(pts[(i + 1) % pts.size()]);
    }
    cout << "Кількість вершин: " << Point::getCount() << " Периметр: " << perim << endl;

    delete[] mas;
    return 0;
}