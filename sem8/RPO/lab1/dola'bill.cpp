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

private:
    std::string ownerName_;
    double balance_;
    std::vector<std::string> transactions_;
};

class Transaction
{
public:
    Transaction(BankAccount &fromAccount, BankAccount &toAccount, double amount)
        : fromAccount_(fromAccount), toAccount_(toAccount), amount_(amount) {}

    void execute()
    {
        if (fromAccount_.getBalance() >= amount_)
        {
            fromAccount_.withdraw(amount_);
            toAccount_.deposit(amount_);
            fromAccount_.addTransaction("Transfer $" + std::to_string(amount_) + " to " + toAccount_.getOwnerName());
            toAccount_.addTransaction("Receive $" + std::to_string(amount_) + " from " + fromAccount_.getOwnerName());
        }
        else
        {
            std::cout << "Insufficient funds for transaction." << std::endl;
        }
    }

private:
    BankAccount &fromAccount_;
    BankAccount &toAccount_;
    double amount_;
};

int main()
{
    BankAccount account1("John");
    BankAccount account2("Alice");

    account1.deposit(1000);
    account2.deposit(500);

    Transaction transaction(account1, account2, 300);
    transaction.execute();

    account1.printStatement();
    account2.printStatement();

    return 0;
}