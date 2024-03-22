#include <iostream>

using namespace std;

class Database
{
public:
    void connect(const string &host, const string &user, const string &password)
    {
        cout << "User: " << user << " connected to: " << host << " using password\n";
    }

    void disconnect()
    {
        cout << "User disconnected\n";
    }

    void saveUser(const string &name, const string &email)
    {
        cout << "User: " << name << " " << email << " saved to database\n";
    }
};

class User
{
private:
    Database database;

public:
    Database getDatabase()
    {
        return database;
    }

    void save(const string &name, const string &email)
    {
        database.saveUser(name, email);
    }
};

int main()
{
    User user;
    Database db = user.getDatabase();
    db.connect("localhost", "user", "password");
    user.save("John Doe", "john.doe@example.com");
    db.disconnect();
}
