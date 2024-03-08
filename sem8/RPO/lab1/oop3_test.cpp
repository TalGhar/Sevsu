#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

class Youth
{
public:
    string FIO;
    int YearOfBirth;
    void Input()
    {
        system("clear");
        cout << "Enter the FIO: ";
        cin >> FIO;
        cout << "Enter the year of birth: ";
        cin >> YearOfBirth;
    }

    void Output()
    {
        system("clear");
        cout << "FIO:" << FIO << endl;
        cout << "Year of birth: " << YearOfBirth << endl;
        cin.get();
    }
    Youth()
    {
        system("clear");
        FIO = "";
        YearOfBirth = 0;
    }

    Youth(string _FIO, int _YearOfBirth)
    {
        system("clear");
        FIO = _FIO;
        YearOfBirth = _YearOfBirth;
        cout << "Youth constructor with parametres finished" << endl;
        cin.get();
    }
    void Born();
};

class Studying
{
public:
    int RecBookNum;
    int Course;
    float AverageMark;

    void Input()
    {
        system("clear");
        cout << "Enter the record-book number: ";
        cin >> RecBookNum;
        cout << "Enter the course: ";
        cin >> Course;
        cout << "Enter the average mark: ";
        cin >> AverageMark;
    }

    void Output()
    {
        system("clear");
        cout << "Record-book number: " << RecBookNum << endl;
        cout << "Course: " << Course << endl;
        cout << "Average mark: " << AverageMark << endl;
    }

    Studying()
    {
        system("clear");
        RecBookNum = 0;
        Course = 0;
        AverageMark = 0;
    }

    Studying(int _RecBookNum, int _Course, float _AverageMark)
    {
        system("clear");
        RecBookNum = _RecBookNum;
        Course = _Course;
        AverageMark = _AverageMark;
        cout << "Studying constructor with parametres finished" << endl;
        cin.get();
    }

    void ChToContStud();
};

class Student : public Youth, public Studying
{
public:
    bool Scholarship;

    Student()
    {
        FIO = "";
        YearOfBirth = 0;
        RecBookNum = 0;
        Course = 0;
        AverageMark = 0;
        Scholarship = 0;
    }

    Student(Youth _Youth, Studying _Studying, bool _Scholarship)
    {
        FIO = _Youth.FIO;
        YearOfBirth = _Youth.YearOfBirth;
        RecBookNum = _Studying.RecBookNum;
        Course = _Studying.Course;
        AverageMark = _Studying.AverageMark;
        Scholarship = _Scholarship;
        if (!Scholarship)
        {
            system("clear");
            cout << "You need to write down if student gets the scholarship (true/false) ";
            cin >> Scholarship;
        }
    }

    void Inhert(Youth _Youth, Studying _Studying)
    {
        FIO = _Youth.FIO;
        YearOfBirth = _Youth.YearOfBirth;
        RecBookNum = _Studying.RecBookNum;
        Course = _Studying.Course;
        AverageMark = _Studying.AverageMark;
        cout << "Type '1' if student gets the scholarship and '0' if not ";
        cin >> Scholarship;
    }

    void Output()
    {
        system("clear");
        cout << "~~~~~~~Student~~~~~~~" << endl;
        cout << "FIO:" << FIO << endl;
        cout << "Year of birth: " << YearOfBirth << endl;
        cout << "Record-book number: " << RecBookNum << endl;
        cout << "Course: " << Course << endl;
        cout << "Average mark: " << AverageMark << endl;
        if (Scholarship == true)
            cout << "Student gets the sholarship" << endl;
        else
            cout << "Student doesn't get the scholarship" << endl;
    }
    bool KickOut();
};

void Youth::Born()
{
    system("clear");
    cout << FIO << " was born in " << YearOfBirth << endl;
}

void Studying::ChToContStud()
{
    if (AverageMark > 90)
        cout << "Student has a high chance that he will continue his studies, moreover, he may receive an increased scholarship" << endl;
    else if ((AverageMark < 90) && (AverageMark >= 75))
        cout << "Student has a chance that he will continue his studies" << endl;
    else if (AverageMark < 75)
        cout << "Student has no chances" << endl;
}

bool Student::KickOut()
{
    if (AverageMark < 60)
    {
        cout << "Student " << FIO << " probably be expelled from the university" << endl;
        return true;
    }
    else
    {
        cout << "Student " << FIO << " probably not be expelled from the university" << endl;
        return false;
    }
}

int getKey()
{
    int key;
    cin >> key;
    while ((key < 1) || (key > 4))
    {
        cout << "You need to choose between 1 and 4" << endl;
        cin >> key;
    }
    return key;
}

class StudentRefactored : public Youth, public Studying
{
public:
    bool Scholarship;

    StudentRefactored()
    {
        FIO = "";
        YearOfBirth = 0;
        RecBookNum = 0;
        Course = 0;
        AverageMark = 0;
        Scholarship = 0;
    }

    StudentRefactored(Youth _Youth, Studying _Studying, bool _Scholarship)
    {
        FIO = _Youth.FIO;
        YearOfBirth = _Youth.YearOfBirth;
        RecBookNum = _Studying.RecBookNum;
        Course = _Studying.Course;
        AverageMark = _Studying.AverageMark;
        Scholarship = _Scholarship;
        if (!Scholarship)
        {
            system("clear");
            cout << "You need to write down if student gets the scholarship (true/false) ";
            cin >> Scholarship;
        }
    }

    void Inhert(Youth _Youth, Studying _Studying)
    {
        FIO = _Youth.FIO;
        YearOfBirth = _Youth.YearOfBirth;
        RecBookNum = _Studying.RecBookNum;
        Course = _Studying.Course;
        AverageMark = _Studying.AverageMark;
        cout << "Type '1' if student gets the scholarship and '0' if not ";
        cin >> Scholarship;
    }

    void Output()
    {
        system("clear");
        cout << "~~~~~~~Student~~~~~~~" << endl;
        cout << "FIO:" << FIO << endl;
        cout << "Year of birth: " << YearOfBirth << endl;
        cout << "Record-book number: " << RecBookNum << endl;
        cout << "Course: " << Course << endl;
        cout << "Average mark: " << AverageMark << endl;
        if (Scholarship == true)
            cout << "Student gets the sholarship" << endl;
        else
            cout << "Student doesn't get the scholarship" << endl;
    }
};

TEST_CASE("Student kickout tests")
{
    Student student = Student();
    StudentRefactored student_refactored = StudentRefactored();
    student.AverageMark = 50;
    SUBCASE("Check if the not refactored student method to kickout is working correctly and returns true if AverageMark is less than 60")
    {
        CHECK(student.KickOut() == true);
    }
    student.AverageMark = 70;
    SUBCASE("Check if the not refactored student method to kickout is working correctly and returns false if AverageMark is more than 60")
    {
        CHECK(student.KickOut() == false);
    }
    student_refactored.AverageMark = 50;
    SUBCASE("Check if refactored student method to kickout is working correctly and returns true if AverageMark is less than 60")
    {
        CHECK(student_refactored.AverageMark < 60);
    }
    student_refactored.AverageMark = 70;
    SUBCASE("Check if refactored student method to kickout is working correctly and returns false if AverageMark is more than 60")
    {
        CHECK(student_refactored.AverageMark >= 60);
    }
}