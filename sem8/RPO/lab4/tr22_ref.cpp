#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>

class BankAccount
{
public:
    BankAccount(const std::string &owner, double balance, int account_number)
        : owner_(owner), balance_(balance), account_number_(account_number) {}

    const std::string &owner() const
    {
        return owner_;
    }

    double balance() const
    {
        return balance_;
    }

    int account_number() const
    {
        return account_number_;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw std::invalid_argument("Deposit amount must be positive");
        }
        balance_ += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw std::invalid_argument("Withdrawal amount must be positive");
        }
        if (balance_ - amount < 0)
        {
            throw std::runtime_error("Insufficient funds");
        }
        balance_ -= amount;
    }

private:
    std::string owner_;
    double balance_;
    int account_number_;
};

class BankAccountFactory
{
public:
    static std::unique_ptr<BankAccount> create(const std::string &owner, double balance, int account_number)
    {
        if (owner.empty())
        {
            throw std::invalid_argument("Owner's name cannot be empty");
        }
        if (balance < 0)
        {
            throw std::invalid_argument("Balance cannot be negative");
        }
        if (account_number <= 0)
        {
            throw std::invalid_argument("Account number must be positive");
        }
        return std::make_unique<BankAccount>(owner, balance, account_number);
    }
};

int main()
{
    try
    {
        auto account = BankAccountFactory::create("John Doe", 1000, 123456);
        account->deposit(500);
        account->withdraw(200);
        std::cout << "Owner: " << account->owner() << std::endl;
        std::cout << "Balance: " << account->balance() << std::endl;
        std::cout << "Account number: " << account->account_number() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
