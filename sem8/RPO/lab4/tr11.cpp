#include <iostream>
#include <vector>
#include <string>

class BankAccount
{
public:
    BankAccount(int id, std::string name, double balance)
        : id_(id), name_(name), balance_(balance) {}

    int id() const { return id_; }
    std::string name() const { return name_; }
    double balance() const { return balance_; }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance_ += amount;
            std::cout << "Deposited " << amount << " to account " << id_ << ". New balance: " << balance_ << ".\n";
        }
        else
        {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    bool withdraw(double amount)
    {
        if (amount > 0 && amount <= balance_)
        {
            balance_ -= amount;
            std::cout << "Withdrew " << amount << " from account " << id_ << ". New balance: " << balance_ << ".\n";
            return true;
        }
        else
        {
            std::cout << "Invalid or insufficient funds for withdrawal.\n";
            return false;
        }
    }

private:
    int id_;
    std::string name_;
    double balance_;
};

class Bank
{
public:
    void addAccount(const BankAccount &account)
    {
        accounts_.push_back(account);
    }

    BankAccount *findAccount(int id)
    {
        for (auto &account : accounts_)
        {
            if (account.id() == id)
            {
                return &account;
            }
        }
        return nullptr;
    }

    void processTransactions(const std::vector<std::pair<int, std::string>> &transactions)
    {
        for (const auto &transaction : transactions)
        {
            BankAccount *account = findAccount(transaction.first);
            if (account != nullptr)
            {
                std::string operation = transaction.second.substr(0, 1);
                double amount = std::stod(transaction.second.substr(2));
                if (operation == "D")
                {
                    account->deposit(amount);
                }
                else if (operation == "W")
                {
                    account->withdraw(amount);
                }
                else
                {
                    std::cout << "Invalid transaction type.\n";
                }
            }
            else
            {
                std::cout << "Account not found.\n";
            }
        }
    }

private:
    std::vector<BankAccount> accounts_;
};

int main()
{
    Bank bank;

    bank.addAccount(BankAccount(1, "John Doe", 1000));
    bank.addAccount(BankAccount(2, "Jane Doe", 2000));

    std::vector<std::pair<int, std::string>> transactions = {
        {1, "D 500"},
        {2, "W 300"},
        {1, "W 800"},
        {3, "D 200"}};

    bank.processTransactions(transactions);

    return 0;
}
