#include "ArticleProcessor.h"

int main() {
    ArticleProcessor ap;
    std::string text;

    std::cout << "Введіть англійське речення: ";
    std::getline(std::cin, text);

    ap.processArticles(text);

    std::cout << "Результат: " << text << std::endl;

    return 0;
}