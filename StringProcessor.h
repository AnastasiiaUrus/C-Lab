#ifndef STRING_PROCESSOR_H
#define STRING_PROCESSOR_H

#include <iostream>
#include <string>
#include <vector>

class StringProcessor {
public:
    // Завдання 1
    std::string task1_v1(const std::string& s);
    void task1_v2(std::string& s);

    // Завдання 2
    std::string task2_v1(const std::string& s);
    void task2_v2(std::string& s);

    // Завдання 3
    std::string task3_v1(const std::string& s);
    void task3_v2(std::string& s);

    // Завдання 6
    void task6(const std::string& s);
};

#endif