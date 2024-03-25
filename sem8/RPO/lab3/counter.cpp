#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("text.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    bool inWord = false;
    char c;
    while (file.get(c)) {
        charCount++;
        if (c == '\n') {
            lineCount++;
            inWord = false;
        } else if (std::isalpha(c)) {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    std::cout << "Line count: " << lineCount << std::endl;
    std::cout << "Word count: " << wordCount << std::endl;
    std::cout << "Char count: " << charCount << std::endl;

    file.close();
    return 0;
}
