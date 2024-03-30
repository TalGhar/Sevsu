#include <iostream>
#include <vector>
#include <string>
#include <map>

class Student
{
public:
    Student(const std::string &name) : name_(name) {}

    void addGrade(const std::string &subject, int grade)
    {
        grades_[subject].push_back(grade);
    }

    double getAverageGrade(const std::string &subject) const
    {
        int sum = 0;
        int count = 0;

        for (const auto &grade : grades_.at(subject))
        {
            sum += grade;
            count++;
        }

        return static_cast<double>(sum) / count;
    }

    const std::string &getName() const
    {
        return name_;
    }

private:
    std::string name_;
    std::map<std::string, std::vector<int>> grades_;
};

class StudentManager
{
public:
    void addStudent(const std::string &name)
    {
        students_.push_back(Student(name));
    }

    void addGrade(const std::string &name, const std::string &subject, int grade)
    {
        for (auto &student : students_)
        {
            if (student.getName() == name)
            {
                student.addGrade(subject, grade);
                break;
            }
        }
    }

    void printStudentsAverageGrades() const
    {
        for (const auto &student : students_)
        {
            std::cout << student.getName() << ": ";

            double mathAverage = student.getAverageGrade("Math");
            double physicsAverage = student.getAverageGrade("Physics");

            std::cout << "Math: " << mathAverage << ", Physics: " << physicsAverage << std::endl;
        }
    }

private:
    std::vector<Student> students_;
};

int main()
{
    StudentManager manager;

    manager.addStudent("Ivan");
    manager.addStudent("Maria");

    manager.addGrade("Ivan", "Math", 85);
    manager.addGrade("Ivan", "Math", 90);
    manager.addGrade("Ivan", "Physics", 70);
    manager.addGrade("Ivan", "Physics", 80);

    manager.addGrade("Maria", "Math", 95);
    manager.addGrade("Maria", "Math", 92);
    manager.addGrade("Maria", "Physics", 88);
    manager.addGrade("Maria", "Physics", 90);

    manager.printStudentsAverageGrades();

    return 0;
}


