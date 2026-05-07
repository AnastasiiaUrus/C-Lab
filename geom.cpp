#include "geom.h"

Point::Point() : x(0), y(0), empty(true) {}
Point::Point(double x, double y) : x(x), y(y), empty(false) {}

void Point::input() {
    std::cout << "Введіть x та y: ";
    std::cin >> x >> y;
    empty = false;
}

void Point::output() {
    if (empty) std::cout << "Порожня точка";
    else std::cout << "(" << x << ", " << y << ")";
}

Segment::Segment() {}
Segment::Segment(Point a, Point b) : p1(a), p2(b) {}

void Segment::input() {
    std::cout << "Точка 1:\n"; p1.input();
    std::cout << "Точка 2:\n"; p2.input();
}

void Segment::output() {
    p1.output(); std::cout << " --- "; p2.output();
}

double Segment::length() {
    return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}

Point Segment::midpoint() {
    return Point((p1.getX() + p2.getX()) / 2.0, (p1.getY() + p2.getY()) / 2.0);
}

Point Segment::intersect(Segment other) {
    double x1 = p1.getX(), y1 = p1.getY(), x2 = p2.getX(), y2 = p2.getY();
    double x3 = other.p1.getX(), y3 = other.p1.getY(), x4 = other.p2.getX(), y4 = other.p2.getY();

    double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (abs(den) < 1e-9) return Point(); 

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        return Point(x1 + t * (x2 - x1), y1 + t * (y2 - y1));
    }
    return Point();
}

Triangle::Triangle() {}
Triangle::Triangle(Point p1, Point p2, Point p3) : a(p1), b(p2), c(p3) {}

void Triangle::input() {
    std::cout << "Вершина 1:\n"; a.input();
    std::cout << "Вершина 2:\n"; b.input();
    std::cout << "Вершина 3:\n"; c.input();
}

void Triangle::output() {
    std::cout << "Трикутник: "; a.output(); b.output(); c.output();
}

double Triangle::perimeter() {
    return Segment(a, b).length() + Segment(b, c).length() + Segment(c, a).length();
}

double Triangle::area() {
    return 0.5 * abs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
}