#include <iostream>
#include <string>
#include <vector>

class BankAccount
{
public:
    BankAccount(const std::string &ownerName) : ownerName_(ownerName), balance_(0) {}

    std::string getOwnerName() const
    {
        return ownerName_;
    }

    double getBalance() const
    {
        return balance_;
    }

    void deposit(double amount)
    {
        balance_ += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance_)
        {
            balance_ -= amount;
        }
        else
        {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }

    void printStatement() const
    {
        std::cout << "Bank Account Statement for " << ownerName_ << std::endl;
        std::cout << "Balance: $" << balance_ << std::endl;
        std::cout << "Transactions:" << std::endl;
        for (const auto &transaction : transactions_)
        {
            std::cout << "- " << transaction << std::endl;
        }
    }

    void addTransaction(const std::string &transaction)
    {
        transactions_.push_back(transaction);
    }

    void executeTransaction(BankAccount &toAccount, double amount)
    {
        if (balance_ >= amount)
        {
            withdraw(amount);
            toAccount.deposit(amount);
            addTransaction("Transfer $" + std::to_string(amount) + " to " + toAccount.getOwnerName());
            toAccount.addTransaction("Receive $" + std::to_string(amount) + " from " + ownerName_);
        }
        else
        {
            std::cout << "Insufficient funds for transaction." << std::endl;
        }
    }

private:
    std::string ownerName_;
    double balance_;
    std::vector<std::string> transactions_;
};

int main()
{
    BankAccount account1("John");
    BankAccount account2("Alice");

    account1.deposit(1000);
    account2.deposit(500);

    account1.executeTransaction(account2, 300);

    account1.printStatement();
    account2.printStatement();

    return 0;
}