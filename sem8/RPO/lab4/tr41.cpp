#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Student
{
public:
    Student(const std::string &name, int age, double gpa)
        : name_(name), age_(age), gpa_(gpa) {}

    void setName(const std::string &name)
    {
        name_ = name;
    }

    const std::string &getName() const
    {
        return name_;
    }

    int getAge() const
    {
        return age_;
    }

    double getGpa() const
    {
        return gpa_;
    }

private:
    std::string name_;
    int age_;
    double gpa_;
};

class StudentList
{
public:
    void addStudent(const Student &student)
    {
        students_.push_back(student);
    }

    void editStudent(int index, const Student &newStudent)
    {
        if (index >= 0 && index < students_.size())
        {
            students_[index] = newStudent;
        }
        else
        {
            std::cout << "Invalid index" << std::endl;
        }
    }

    void saveToFile(const std::string &filename)
    {
        std::ofstream outputFile(filename);
        if (outputFile.is_open())
        {
            for (const auto &student : students_)
            {
                outputFile << student.getName() << ','
                           << student.getAge() << ','
                           << student.getGpa() << std::endl;
            }
            outputFile.close();
        }
        else
        {
            std::cout << "Unable to open file for writing" << std::endl;
        }
    }

    void loadFromFile(const std::string &filename)
    {
        std::ifstream inputFile(filename);
        if (inputFile.is_open())
        {
            students_.clear();
            std::string line;
            while (std::getline(inputFile, line))
            {
                size_t comma1 = line.find(',');
                size_t comma2 = line.find(',', comma1 + 1);
                if (comma1 != std::string::npos && comma2 != std::string::npos)
                {
                    std::string name = line.substr(0, comma1);
                    int age = std::stoi(line.substr(comma1 + 1, comma2 - comma1 - 1));
                    double gpa = std::stod(line.substr(comma2 + 1));
                    students_.push_back(Student(name, age, gpa));
                }
            }
            inputFile.close();
        }
        else
        {
            std::cout << "Unable to open file for reading" << std::endl;
        }
    }

    void printStudents() const
    {
        for (const auto &student : students_)
        {
            std::cout << student.getName() << ", "
                      << student.getAge() << ", "
                      << student.getGpa() << std::endl;
        }
    }

private:
    std::vector<Student> students_;
};

int main()
{
    StudentList list;

    list.addStudent(Student("John Doe", 20, 3.5));
    list.addStudent(Student("Jane Smith", 22, 3.8));

    list.printStudents();

    list.editStudent(0, Student("John Updated", 21, 3.6));

    list.printStudents();

    list.saveToFile("students.txt");
    list.loadFromFile("students.txt");

    list.printStudents();

    return 0;
}
