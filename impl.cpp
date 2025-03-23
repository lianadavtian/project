#include "header.hpp"
#include "exceptions.hpp"
#include "templ.tpp"

void CheckingAccount::deposit(double amount)
{
    // verifyCustomer();
    balance_ += amount;
}

void CheckingAccount::withdraw(double amount)
{
    // verifyCustomer();
    // checkBalance();
    if (amount > balance_)
    {
        throw InsufficientFundsException();
    }
    balance_ -= amount;
}

double CheckingAccount::getBalance() const
{
    // verifyCustomer();
    // checkBalance();
    return balance_;
}

void SavingsAccount::deposit(double amount)
{
    if (amount < 0)
    {
        throw InvalidTransactionException();
    }
    // verifyCustomer();
    balance_ += amount;
}
void SavingsAccount::withdraw(double amount)
{
    // verifyCustomer();
    // checkBalance();
    if (amount - balance_ < 100)
    {
        throw InsufficientFundsException();
    }
    balance_ -= amount;
}
double SavingsAccount::getBalance() const
{
    //    verifyCustomer();
    return balance_;
}

Customer::Customer(const std::string &name, const std::string &email) : name_(name), email_(email) {}
std::string Customer::getName() const
{
    return name_;
}
std::string Customer::getEmail() const
{
    return email_;
}
void Customer::addAccount(Account *acc)
{
    accounts_.push_back(acc);
}
void TransactionHistory::addTransaction(const Transaction &transaction)
{
    transactions_.push_back(transaction);
}
void TransactionHistory::displayTransactions() const
{
    for (const auto &transaction : transactions_)
    {
        transaction.displayTransaction();
    }
}
void Transaction::displayTransaction() const
{
    std::cout << account_ << amount_ << type_ << timestamp_ << std::endl;
}
template <typename Container>
void displayTransactionHistory(const Container &container)
{
    for (const auto &transaction : container)
    {
        transaction.displayTransaction();
    }
}
