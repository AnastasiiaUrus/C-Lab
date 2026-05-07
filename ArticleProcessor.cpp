#include "ArticleProcessor.h"

void ArticleProcessor::processArticles(std::string& sentence) {
    std::stringstream ss(sentence);
    std::string word;
    std::vector<std::string> words;

    // Розбиваємо рядок на масив слів
    while (ss >> word) {
        words.push_back(word);
    }

    for (size_t i = 0; i < words.size(); ++i) {
        std::string lower = words[i];
        // Перетворюємо слово в нижній регістр для перевірки на артикль
        for (char &c : lower) c = tolower(c);

        // Перевірка на артиклі 'a', 'an', 'the'
        if (lower == "a" || lower == "an" || lower == "the") {
            // Якщо є наступне слово, змінюємо його першу літеру на маленьку
            if (i + 1 < words.size()) {
                words[i+1][0] = tolower(words[i+1][0]);
            }
        }
    }

    // Збираємо слова назад у речення
    sentence = "";
    for (size_t i = 0; i < words.size(); ++i) {
        sentence += words[i];
        if (i < words.size() - 1) sentence += " ";
    }
}