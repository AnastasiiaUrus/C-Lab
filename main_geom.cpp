#include "geom.h"

int main() {
    Segment s1, s2;
    std::cout << "Введіть перший відрізок:\n";
    s1.input();
    std::cout << "Введіть другий відрізок:\n";
    s2.input();

    std::cout << "\nДовжина 1-го відрізка: " << s1.length() << "\n";
    std::cout << "Середина 1-го відрізка: "; s1.midpoint().output(); std::cout << "\n";

    Point inter = s1.intersect(s2);
    std::cout << "Перетин відрізків: "; inter.output(); std::cout << "\n";

    Triangle tr;
    std::cout << "\nВведіть дані трикутника:\n";
    tr.input();
    std::cout << "Периметр: " << tr.perimeter() << "\n";
    std::cout << "Площа: " << tr.area() << "\n";

    return 0;
}