#include <iostream>
#include <fstream>
#include <string>

class FileProcessor
{
public:
    void processTxtFile(const std::string &filename)
    {
        processFile(filename, &FileProcessor::processTxtLine);
    }

    void processCsvFile(const std::string &filename)
    {
        processFile(filename, &FileProcessor::processCsvLine);
    }

    void processJsonFile(const std::string &filename)
    {
        processFile(filename, &FileProcessor::processJsonLine);
    }

private:
    void processFile(const std::string &filename, void (FileProcessor::*processLine)(const std::string &))
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file");
        }

        std::string line;
        while (std::getline(file, line))
        {
            (this->*processLine)(line);
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
    processor.processTxtFile("file.txt");
    processor.processCsvFile("file.csv");
    processor.processJsonFile("file.json");

    return 0;
}
