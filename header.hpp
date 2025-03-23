#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <vector>

enum TransactionType
{
    DEPOSIT,
    WITHDRAWAL
};

class Account
{
public:
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual double getBalance() const;

protected:
    double balance_;
};

class CheckingAccount : public Account
{
public:
    void deposit(double amount) override;  // done
    void withdraw(double amount) override; // done
    double getBalance() const override;    // done
};

class SavingsAccount : public Account
{
public:
    void deposit(double amount) override;  // done
    void withdraw(double amount) override; // done
    double getBalance() const override;    // done
};

class Customer
{
private:
    std::string name_;
    std::string email_;
    std::vector<Account *> accounts_;

public:
    Customer(const std::string &name, const std::string &email); // done
    std::string getName() const;                                 // done
    std::string getEmail() const;                                // done
    void addAccount(Account *acc);                               // done
};

class Transaction
{
protected:
    TransactionType type_;
    Account *account_;
    double amount_;
    int transactionType;
    std::string timestamp_;

public:
    void displayTransaction() const;
};

class TransactionHistory
{
private:
    std::vector<Transaction> transactions_;

public:
    void addTransaction(const Transaction &transaction);
    void displayTransactions() const;
};

#endif // HEADER_HPP