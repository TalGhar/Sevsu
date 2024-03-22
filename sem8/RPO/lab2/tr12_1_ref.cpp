#include <iostream>

using namespace std;

class ContactInfo
{
public:
    ContactInfo() {}
    ContactInfo(const string &email) : m_email(email) {}

    void setEmail(const string &email) { m_email = email; }
    string getEmail() const { return m_email; }

private:
    string m_email;
};

class Employee
{
public:
    Employee() {}
    Employee(const string &name, const string &position, int salary, const string &email)
        : m_name(name), m_position(position), m_salary(salary), m_contactInfo(email) {}

    void setName(const string &name) { m_name = name; }
    string getName() const { return m_name; }

    void setPosition(const string &position) { m_position = position; }
    string getPosition() const { return m_position; }

    void setSalary(int salary) { m_salary = salary; }
    int getSalary() const { return m_salary; } 

    void setContactInfo(ContactInfo contactInfo) { m_contactInfo = contactInfo; }
    ContactInfo getContactInfo() const { return m_contactInfo; }

    string getInfo() const
    {
        return "Name: " + m_name + ", Position: " + m_position + ", Salary: " + to_string(m_salary) + ", Email: " + m_contactInfo.getEmail();
    }

private:
    string m_name;
    string m_position;
    int m_salary;
    ContactInfo m_contactInfo;
};

int main()
{
    ContactInfo bob_info;
    bob_info.setEmail("bob@corp.com");
    Employee bob;
    bob.setName("Bob");
    bob.setPosition("HR");
    bob.setSalary(15000);
    bob.setContactInfo(bob_info);
    cout << bob.getInfo();
}