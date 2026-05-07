#include "StringProcessor.h"
#include <sstream>
#include <algorithm>

// Завдання 1: підрядок між ':' та ','
std::string StringProcessor::task1_v1(const std::string& s) {
    size_t colon = s.find(':');
    if (colon == std::string::npos) return s;
    size_t comma = s.find(',', colon);
    if (comma == std::string::npos) return s.substr(colon + 1);
    return s.substr(colon + 1, comma - colon - 1);
}

void StringProcessor::task1_v2(std::string& s) {
    s = task1_v1(s);
}

// Завдання 2: видалити між першою та останньою крапкою
std::string StringProcessor::task2_v1(const std::string& s) {
    size_t first = s.find('.');
    size_t last = s.find_last_of('.');
    if (first == std::string::npos) {
        std::string res = s;
        res.erase(0, res.find_first_not_of(' '));
        return res;
    }
    if (first == last) return "";
    std::string res = s;
    res.erase(first + 1, last - first - 1);
    return res;
}

void StringProcessor::task2_v2(std::string& s) {
    s = task2_v1(s);
}

// Завдання 3: видалити останню літеру кожного слова
std::string StringProcessor::task3_v1(const std::string& s) {
    std::string res = "";
    std::string word = "";
    for (size_t i = 0; i <= s.length(); ++i) {
        if (i < s.length() && s[i] != ' ') {
            word += s[i];
        } else {
            if (!word.empty()) {
                res += word.substr(0, word.length() - 1);
                word = "";
            }
            if (i < s.length()) res += ' ';
        }
    }
    return res;
}

void StringProcessor::task3_v2(std::string& s) {
    s = task3_v1(s);
}

// Завдання 6: найкоротше слово
void StringProcessor::task6(const std::string& s) {
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> words;
    size_t minLen = 1e9;

    while (ss >> word) {
        words.push_back(word);
        if (word.length() < minLen) minLen = word.length();
    }

    std::vector<std::string> shortest;
    for (const auto& w : words) {
        if (w.length() == minLen) shortest.push_back(w);
    }

    std::cout << "a) Перше найкоротше: " << shortest[0] << "\n";
    std::cout << "б) Останнє найкоротше: " << shortest.back() << "\n";
    std::cout << "в) Всі найкоротші: ";
    for (const auto& w : shortest) std::cout << w << " ";
    std::cout << "\n";
}