#include <iostream>

using namespace std;

class Employee
{
public:
    Employee() {}
    Employee(const string &name, const string &position, int salary, const string &email)
        : m_name(name), m_position(position), m_salary(salary), m_email(email) {}

    void setName(const string &name) { m_name = name; }
    string getName() const { return m_name; }

    void setPosition(const string &position) { m_position = position; }
    string getPosition() const { return m_position; }

    void setSalary(int salary) { m_salary = salary; }
    int getSalary() const { return m_salary; }

    void setEmail(const string &email) { m_email = email; }
    string getEmail() const { return m_email; }

    string getInfo() const
    {
        return "Name: " + m_name + ", Position: " + m_position + ", Salary: " + to_string(m_salary) + ", Email: " + m_email;
    }

private:
    string m_name;
    string m_position;
    int m_salary;
    string m_email;
};

int main()
{
    Employee bob;
    bob.setName("Bob");
    bob.setPosition("HR");
    bob.setSalary(15000);
    bob.setEmail("bob@corp.com");
    cout << bob.getInfo();
}
