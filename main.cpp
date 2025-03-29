#include "header.hpp"
#include "exceptions.hpp"

int main() {
    try {
        Customer customer("Liana Davtian", "lianadavtian7@gmail.com");

        auto checking = std::make_shared<CheckingAccount>(500.0, 1001);
        auto savings = std::make_shared<SavingsAccount>(1000.0, 1002);

        customer.addAccount(checking);
        customer.addAccount(savings);

        // Successful transactions
        checking->deposit(200.0);
        savings->withdraw(200.0);

        // Demonstrate exception handling
        try {
            checking->withdraw(1000.0); // Should throw InsufficientFundsException
        } catch (const InsufficientFundsException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        try {
            savings->withdraw(850.0); // Should throw InsufficientFundsException
        } catch (const InsufficientFundsException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        try {
            checking->deposit(-50.0); // Should throw InvalidTransactionException
        } catch (const InvalidTransactionException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        // Display all transactions
        customer.displayTransactions();

    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}