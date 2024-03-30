#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Student
{
public:
    Student(const string &name) : name_(name) {}

    void addGrade(const string &subject, int grade)
    {
        grades_[subject].push_back(grade);
    }

    double getAverageGrade(const string &subject) const
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

    const string &getName() const
    {
        return name_;
    }

private:
    string name_;
    map<string, vector<int>> grades_;
};

class StudentManager
{
public:
    void addStudent(const string &name)
    {
        students_.push_back(Student(name));
    }

    void addGrade(const string &name, const string &subject, int grade)
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

    void printStudentsAverageGrades(const string &subject = "") const
    {
        for (const auto &student : students_)
        {
            double subjectAverage = student.getAverageGrade(subject);

            if (subject.empty() || subjectAverage != -1)
            {
                cout << student.getName() << ": ";

                double mathAverage = student.getAverageGrade("Math");
                double physicsAverage = student.getAverageGrade("Physics");

                cout << "Math: " << mathAverage << ", Physics: " << physicsAverage;

                if (!subject.empty())
                {
                    cout << ", " << subject << ": " << subjectAverage;
                }

                cout << endl;
            }
        }
    }

private:
    vector<Student> students_;
};

int main()
{
    StudentManager manager;

    manager.addStudent("Ivan");
    manager.addStudent("Maria");

    manager.addGrade("Ivan", "Math", 85);
    manager.addGrade("Ivan", "Physics", 70);

    manager.addGrade("Maria", "Math", 95);
    manager.addGrade("Maria", "Physics", 88);

    manager.printStudentsAverageGrades("Math");

    return 0;
}