#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>

class Transaction {
public:
    Transaction(const std::string& accType, double amt, const std::string& tType);
    void display() const;
    double getAmount() const { return amount_; }
    std::string getType() const { return type_; }
    std::string getTimestamp() const { return timestamp_; }

private:
    std::string accountType_;
    double amount_;
    std::string type_;
    std::string timestamp_;
    std::string getCurrentTime() const;
};

class Account {
public:
    Account() = default;
    virtual ~Account() = default;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual double getBalance() const = 0;
    virtual int getAccountId() const = 0;
    virtual std::string getType() const = 0;
    void addTransaction(const Transaction& transaction);

protected:
    std::vector<Transaction> transactions_;
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double initialBalance, int accountId);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    double getBalance() const override;
    int getAccountId() const override;
    std::string getType() const override { return "Checking"; }

private:
    double balance_;
    int accountId_;
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double initialBalance, int accountId);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    double getBalance() const override;
    int getAccountId() const override;
    std::string getType() const override { return "Savings"; }

private:
    double balance_;
    int accountId_;
    static constexpr double MIN_BALANCE = 100.0;
};

class Customer {
public:
    Customer(const std::string& name, const std::string& email);
    void addAccount(std::shared_ptr<Account> account);
    void displayTransactions() const;
    const std::vector<std::shared_ptr<Account>>& getAccounts() const;
    std::string getName() const { return name_; }
    std::string getEmail() const { return email_; }

private:
    std::string name_;
    std::string email_;
    std::vector<std::shared_ptr<Account>> accounts_;
};

template <typename Container>
void displayTransactionHistory(const Container& container);

#endif