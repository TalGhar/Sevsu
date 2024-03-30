#include <iostream>
#include <fstream>
#include <string>

std::string readFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

int main()
{
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::string content = readFile(filename);
    if (content.empty())
    {
        std::cout << "Error: File not found." << std::endl;
    }
    else
    {
        std::cout << "File content: " << std::endl
                  << content << std::endl;
    }

    return 0;
}
