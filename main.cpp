#include "StringProcessor.h"

int main() {
    StringProcessor sp;
    std::string input1 = "Приклад:шуканий_текст,кінець";
    std::string input2 = "  Багато пробілів. Видалити це . Крапка";
    std::string input3 = "Hello world from university";
    std::string input6 = "Я вивчаю програмування та мову Сі";

    std::cout << "Завдання 1: " << sp.task1_v1(input1) << "\n";
    std::cout << "Завдання 2: " << sp.task2_v1(input2) << "\n";
    std::cout << "Завдання 3: " << sp.task3_v1(input3) << "\n";
    
    std::cout << "\nЗавдання 6:\n";
    sp.task6(input6);

    return 0;
}