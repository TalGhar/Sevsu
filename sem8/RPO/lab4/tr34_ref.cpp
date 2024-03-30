#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class TextEditor
{
public:
    bool open(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return false;
        }
        std::string line;
        buffer_.clear(); // clear previous content
        while (std::getline(file, line))
        {
            buffer_.push_back(line);
        }
        return true;
    }

    void save(const std::string &filename)
    {
        std::ofstream file(filename);
        for (const auto &line : buffer_)
        {
            file << line << std::endl;
        }
    }

    void append(const std::string &line)
    {
        buffer_.push_back(line);
    }

    void print()
    {
        for (const auto &line : buffer_)
        {
            std::cout << line << std::endl;
        }
    }

private:
    std::vector<std::string> buffer_;
};

int main()
{
    TextEditor editor;
    std::string command;
    while (true)
    {
        std::cout << "> ";
        std::cin >> command;
        if (command == "open")
        {
            std::string filename;
            std::cin >> filename;
            if (!editor.open(filename))
            {
                std::cout << "Could not open file" << std::endl;
            }
        }
        else if (command == "save")
        {
            std::string filename;
            std::cin >> filename;
            editor.save(filename);
        }
        else if (command == "append")
        {
            std::string line;
            std::cin.ignore();
            std::getline(std::cin, line);
            editor.append(line);
        }
        else if (command == "print")
        {
            editor.print();
        }
        else if (command == "exit")
        {
            break;
        }
    }

    return 0;
}
