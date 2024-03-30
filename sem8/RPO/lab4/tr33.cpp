#include <iostream>
#include <vector>
#include <string>

class DataProcessor
{
public:
    void processIntegers(std::vector<int> data)
    {
        int sum = 0;
        for (int num : data)
        {
            sum += num;
        }
        std::cout << "Сумма целых чисел: " << sum << std::endl;
    }

    void processDoubles(std::vector<double> data)
    {
        double product = 1.0;
        for (double num : data)
        {
            product *= num;
        }
        std::cout << "Произведение дробных чисел: " << product << std::endl;
    }

    void processStrings(std::vector<std::string> data)
    {
        std::string concatenatedString;
        for (const std::string &str : data)
        {
            concatenatedString += str + " ";
        }
        std::cout << "Объединенная строка: " << concatenatedString << std::endl;
    }
};

int main()
{
    DataProcessor processor;

    processor.processIntegers({1, 2, 3, 4, 5});
    processor.processDoubles({1.5, 2.5, 3.5});
    processor.processStrings({"Hello", "World", "from", "C++"});

    return 0;
}