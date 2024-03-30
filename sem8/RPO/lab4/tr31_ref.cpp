#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

std::string readFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Error: File not found.");
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

int main()
{
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    try
    {
        std::string content = readFile(filename);
        std::cout << "File content: " << std::endl
                  << content << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
