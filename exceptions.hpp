#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException(const std::string str = "InsufficientFundsException") : message_(str) {};
    InsufficientFundsException(const InsufficientFundsException &rhs) noexcept = default;
    ~InsufficientFundsException() override {};
    const char *what() const noexcept override
    {
        return message_.c_str();
    }

private:
    std::string message_;
};

class InvalidTransactionException : public std::exception
{
public:
    InvalidTransactionException(const std::string str = "InvalidTransactionException") : message_(str) {};
    InvalidTransactionException(const InvalidTransactionException &rhs) noexcept = default;
    ~InvalidTransactionException() override {};
    const char *what() const noexcept override
    {
        return message_.c_str();
    }

private:
    std::string message_;
};

#endif // EXCEPTION