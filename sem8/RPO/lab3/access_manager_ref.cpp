#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

enum class Role {
    Guest,
    User,
    Moderator,
    Admin
};

class UserAccount {
public:
    UserAccount(const string& name, const string& password, Role role)
        : name_(name), password_(password), role_(role) {}

    bool authenticate(const string& name, const string& password) {
        return name == name_ && password == password_;
    }

    Role getRole() const {
        return role_;
    }

private:
    string name_;
    string password_;
    Role role_;
};

class AccessControl {
public:
    void addUser(const string& name, const string& password, Role role) {
        users_.emplace(name, UserAccount(name, password, role));
    }

    Role login(const string& name, const string& password) {
        auto it = users_.find(name);
        if (it != users_.end() && it->second.authenticate(name, password)) {
            return it->second.getRole();
        }
        return Role::Guest;
    }

private:
    map<string, UserAccount> users_;
};

string getGreetingMessage(Role role) {
    static const unordered_map<Role, string> greetings = {
        {Role::Guest, "Access denied."},
        {Role::User, "Welcome, user."},
        {Role::Moderator, "Welcome, moderator."},
        {Role::Admin, "Welcome, admin."}
    };

    return greetings.at(role);
}

int main() {
    AccessControl accessControl;

    accessControl.addUser("user", "qwerty123", Role::User);
    accessControl.addUser("moderator", "qwerty321", Role::Moderator);
    accessControl.addUser("admin", "123qwerty", Role::Admin);

    string name;
    string password;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> password;

    Role role = accessControl.login(name, password);

    cout << getGreetingMessage(role) << '\n';

    return 0;
}
