#include <iostream>
#include <vector>
#include <string>

class DataProcessor
{
public:
    template <typename T>
    T processData(std::vector<T> data)
    {
        T result = data[0];
        for (size_t i = 1; i < data.size(); ++i)
        {
            result += data[i];
        }
        return result;
    }
};

int main()
{
    DataProcessor processor;

    std::vector<int> intData = {1, 2, 3, 4, 5};
    int sum = processor.processData(intData);
    std::cout << "Сумма целых чисел: " << sum << std::endl;

    std::vector<double> doubleData = {1.5, 2.5, 3.5};
    double product = processor.processData(doubleData);
    std::cout << "Произведение дробных чисел: " << product << std::endl;

    std::vector<std::string> stringData = {"Hello ", "World ", "from ", "C++"};
    std::string concatenatedString = processor.processData(stringData);
    std::cout << "Объединенная строка: " << concatenatedString << std::endl;

    return 0;
}