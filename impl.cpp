#include "header.hpp"
#include "exceptions.hpp"
#include <iomanip>
#include <stdexcept>

CheckingAccount::CheckingAccount(double initialBalance, int accountId) 
    : balance_(initialBalance), accountId_(accountId) {
    if (initialBalance < 0) {
        throw InvalidTransactionException("Initial balance cannot be negative");
    }
}

void CheckingAccount::deposit(double amount) {
    if (amount <= 0) {
        throw InvalidTransactionException("Deposit amount must be positive");
    }
    balance_ += amount;
    addTransaction(Transaction(getType(), amount, "Deposit"));
}

void CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw InvalidTransactionException("Withdrawal amount must be positive");
    }
    if (amount > balance_) {
        throw InsufficientFundsException("Not enough funds in checking account");
    }
    balance_ -= amount;
    addTransaction(Transaction(getType(), amount, "Withdrawal"));
}

double CheckingAccount::getBalance() const { return balance_; }
int CheckingAccount::getAccountId() const { return accountId_; }

SavingsAccount::SavingsAccount(double initialBalance, int accountId) 
    : balance_(initialBalance), accountId_(accountId) {
    if (initialBalance < MIN_BALANCE) {
        throw InvalidTransactionException("Initial balance below minimum requirement");
    }
}

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) {
        throw InvalidTransactionException("Deposit amount must be positive");
    }
    balance_ += amount;
    addTransaction(Transaction(getType(), amount, "Deposit"));
}

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw InvalidTransactionException("Withdrawal amount must be positive");
    }
    if (balance_ - amount < MIN_BALANCE) {
        throw InsufficientFundsException("Withdrawal would violate minimum balance");
    }
    balance_ -= amount;
    addTransaction(Transaction(getType(), amount, "Withdrawal"));
}

double SavingsAccount::getBalance() const { return balance_; }
int SavingsAccount::getAccountId() const { return accountId_; }

Customer::Customer(const std::string& name, const std::string& email) 
    : name_(name), email_(email) {}

void Customer::addAccount(std::shared_ptr<Account> account) {
    accounts_.push_back(account);
}

void Customer::displayTransactions() const {
    std::cout << "Transaction history for " << name_ << ":\n";
    for (const auto& account : accounts_) {
        std::cout << account->getType() << " Account (ID: " << account->getAccountId() << "):\n";
        //displayTransactionHistory(account->transactions_);
    }
}

const std::vector<std::shared_ptr<Account>>& Customer::getAccounts() const {
    return accounts_;
}

void Account::addTransaction(const Transaction& transaction) {
    transactions_.push_back(transaction);
}

std::string Transaction::getCurrentTime() const {
    std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", std::localtime(&now));
    return std::string(buf);
}

Transaction::Transaction(const std::string& accType, double amt, const std::string& tType)
    : accountType_(accType), amount_(amt), type_(tType), timestamp_(getCurrentTime()) {}

void Transaction::display() const {
    std::cout << "[" << timestamp_ << "] " << type_ << " of $" 
              << std::fixed << std::setprecision(2) << amount_ 
              << " on " << accountType_ << " account\n";
}

template <typename Container>
void displayTransactionHistory(const Container& container) {
    for (const auto& transaction : container) {
        transaction.display();
    }
}
template void displayTransactionHistory(const std::vector<Transaction>&);