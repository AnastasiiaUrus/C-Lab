#ifndef GEOM_H
#define GEOM_H

#include <iostream>
#include <cmath>

class Point {
    double x, y;
    bool empty;
public:
    Point();
    Point(double x, double y);
    void input();
    void output();
    double getX() const { return x; }
    double getY() const { return y; }
    bool isEmpty() const { return empty; }
};

class Segment {
    Point p1, p2;
public:
    Segment();
    Segment(Point a, Point b);
    void input();
    void output();
    double length();
    Point midpoint();
    Point intersect(Segment other);
};

class Triangle {
    Point a, b, c;
public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
    void input();
    void output();
    double perimeter();
    double area();
};

#endif