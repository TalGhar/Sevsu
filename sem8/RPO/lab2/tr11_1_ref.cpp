#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const string& name, const string& street, const string& city, const string& country)
        : name_(name), street_(street), city_(city), country_(country) {}

    void print() const {
        cout << "Name: " << name_ << endl;
        cout << "Address:" << endl;
        cout << "Street: " << street_ << endl;
        cout << "City: " << city_ << endl;
        cout << "Country: " << country_ << endl;
    }

private:
    string name_;
    string street_;
    string city_;
    string country_;
};

int main() {
    Person person("John Doe", "123 Main St", "New York", "USA");
    person.print();

    return 0;
}
