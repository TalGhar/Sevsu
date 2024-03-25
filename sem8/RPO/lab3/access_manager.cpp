#include <iostream>
#include <string>
#include <map>

enum class Role {
    Guest,
    User,
    Moderator,
    Admin
};

class UserAccount {
public:
    UserAccount(const std::string& name, const std::string& password, Role role)
        : name_(name), password_(password), role_(role) {}

    bool authenticate(const std::string& name, const std::string& password) {
        if (name == name_ && password == password_) {
            return true;
        }
        return false;
    }

    Role getRole() const {
        return role_;
    }

private:
    std::string name_;
    std::string password_;
    Role role_;
};

class AccessControl {
public:
    void addUser(const std::string& name, const std::string& password, Role role) {
        users_.emplace(name, UserAccount(name, password, role));
    }

    Role login(const std::string& name, const std::string& password) {
        auto it = users_.find(name);
        if (it != users_.end()) {
            if (it->second.authenticate(name, password)) {
                return it->second.getRole();
            }
        }
        return Role::Guest;
    }

private:
    std::map<std::string, UserAccount> users_;
};

int main() {
    AccessControl accessControl;

    accessControl.addUser("user", "qwerty123", Role::User);
    accessControl.addUser("moderator", "qwerty321", Role::Moderator);
    accessControl.addUser("admin", "123qwerty", Role::Admin);

    std::string name;
    std::string password;

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your password: ";
    std::cin >> password;

    Role role = accessControl.login(name, password);

    if (role == Role::Guest) {
        std::cout << "Access denied.\n";
    } else if (role == Role::User) {
        std::cout << "Welcome, user.\n";
    } else if (role == Role::Moderator) {
        std::cout << "Welcome, moderator.\n";
    } else if (role == Role::Admin) {
        std::cout << "Welcome, admin.\n";
    }

    return 0;
}
