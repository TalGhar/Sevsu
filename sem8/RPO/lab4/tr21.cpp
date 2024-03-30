#include <iostream>
#include <fstream>
#include <string>

enum FileType
{
    TXT,
    CSV,
    JSON
};

class FileProcessor
{
public:
    void processFile(const std::string &filename, FileType fileType)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file");
        }

        std::string line;
        while (std::getline(file, line))
        {
            switch (fileType)
            {
            case TXT:
                processTxtLine(line);
                break;
            case CSV:
                processCsvLine(line);
                break;
            case JSON:
                processJsonLine(line);
                break;
            default:
                throw std::invalid_argument("Invalid file type");
            }
        }

        file.close();
    }

    void processTxtLine(const std::string &line)
    {
        std::cout << "Processing TXT line: " << line << std::endl;
    }

    void processCsvLine(const std::string &line)
    {
        std::cout << "Processing CSV line: " << line << std::endl;
    }

    void processJsonLine(const std::string &line)
    {
        std::cout << "Processing JSON line: " << line << std::endl;
    }
};

int main()
{
    FileProcessor processor;
    processor.processFile("file.txt", TXT);
    processor.processFile("file.csv", CSV);
    processor.processFile("file.json", JSON);

    return 0;
}
