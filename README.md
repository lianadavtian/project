Task 2: Advanced Banking System Simulation
Objective:
Develop a simplified banking system in C++ that showcases object-oriented programming (OOP) principles, adheres to SOLID design guidelines, and integrates advanced C++ features such as templates, iterators, and custom exceptions. The system should manage bank accounts, customers, and their transactions, providing a modular and extensible framework for basic banking operations. Your goal is to create a functional system that can be implemented within approximately one hour.

Detailed Description
1. Account Class Hierarchy
Purpose: Represent different types of bank accounts with shared and specialized behaviors.
Requirements:
Design an abstract base class named Account to serve as the foundation for all account types.
Include the following pure virtual methods in Account:
deposit(double amount): Adds the specified amount to the account balance.
withdraw(double amount): Removes the specified amount from the account balance, subject to account-specific rules.
getBalance() const: Returns the current balance of the account.
Create two derived classes:
CheckingAccount:
Allows withdrawals as long as the balance covers the amount (i.e., balance ≥ withdrawal amount).
Represents a typical checking account with straightforward deposit and withdrawal capabilities.
SavingsAccount:
Enforces a minimum balance requirement (e.g., $100). Withdrawals are only permitted if the remaining balance meets or exceeds this minimum.
Simulates a savings account with restrictions to encourage saving.
Each derived class should implement the virtual methods according to its specific rules.
2. Customer Class
Purpose: Manage information about a bank customer and their associated accounts.
Requirements:
Define a Customer class with attributes such as:
name: The customer's full name.
contactInfo: Basic contact details (e.g., email or phone number).
A collection of accounts (e.g., a vector of Account pointers) owned by the customer.
Provide functionality to:
Add a new account to the customer's list.
Access or retrieve the list of accounts for further operations.
3. Transaction Class
Purpose: Record individual banking operations like deposits and withdrawals.
Requirements:
Create a Transaction class to encapsulate details of each operation, including:
A reference or identifier linking it to a specific account.
The transaction amount (e.g., $50.00).
The transaction type (e.g., "deposit" or "withdrawal").
A timestamp (could be a simple string like "2023-10-15 14:30" or derived from std::time).
This class should be used whenever a deposit or withdrawal occurs to log the activity.
4. Transaction History
Purpose: Track and display a history of transactions for accounts or customers.
Requirements:
Store a list of transactions either in the Account class (for per-account history) or the Customer class (for all accounts owned by the customer).
Use iterators to traverse this list and display transaction details, such as amount, type, and timestamp, in a readable format.
5. Template Function
Purpose: Provide a flexible way to display transaction information.
Requirements:
Implement a template function that can process and print details of transactions.
The function should be generic enough to work with different containers (e.g., a vector of transactions) or potentially different transaction types, allowing for future extensibility.
Example usage: Pass a transaction history list to the function to output details for each entry.
6. Custom Exceptions
Purpose: Handle error conditions gracefully during banking operations.
Requirements:
Define at least two custom exception classes:
InsufficientFundsException: Thrown when a withdrawal attempt exceeds the available balance (e.g., in CheckingAccount) or violates the minimum balance rule (e.g., in SavingsAccount).
InvalidTransactionException: Thrown for invalid operations, such as attempting to deposit a negative amount or other illogical actions.
Integrate these exceptions into the deposit and withdraw methods, ensuring they are thrown when appropriate and caught elsewhere (e.g., in main) to display error messages.
7. Main Function Demonstration
Purpose: Showcase the system’s functionality in a simple test scenario.
Requirements:
In the main function, include the following actions:
Create a Customer instance with at least one CheckingAccount and one SavingsAccount.
Perform a series of operations, such as:
Depositing money into both accounts.
Withdrawing money, including cases that should trigger exceptions (e.g., overdrawing a checking account or dropping below the savings account’s minimum balance).
Use iterators to display the transaction history for the customer’s accounts.
Catch and handle any exceptions, printing meaningful error messages (e.g., "Error: Insufficient funds").

What the Code Should Do
The completed system should simulate a basic banking environment where:
A customer can own multiple accounts (checking and savings).
Deposits and withdrawals can be performed, with appropriate rules enforced (e.g., minimum balance for savings).
Every transaction is recorded and can be reviewed using iterators.
Errors like insufficient funds or invalid inputs are caught and reported via custom exceptions.
A generic template function displays transaction details, demonstrating flexibility.
Task 2: Advanced Banking System Simulation
Objective:


Develop a simplified banking system in C++ that showcases object-oriented programming (OOP) principles, adheres to SOLID design guidelines, and integrates advanced C++ features such as templates, iterators, and custom exceptions. The system should manage bank accounts, customers, and their transactions, providing a modular and extensible framework for basic banking operations. Your goal is to create a functional system that can be implemented within approximately one hour.

Detailed Description
1. Account Class Hierarchy
Purpose: Represent different types of bank accounts with shared and specialized behaviors.
Requirements:
Design an abstract base class named Account to serve as the foundation for all account types.
Include the following pure virtual methods in Account:
deposit(double amount): Adds the specified amount to the account balance.
withdraw(double amount): Removes the specified amount from the account balance, subject to account-specific rules.
getBalance() const: Returns the current balance of the account.
Create two derived classes:
CheckingAccount:
Allows withdrawals as long as the balance covers the amount (i.e., balance ≥ withdrawal amount).
Represents a typical checking account with straightforward deposit and withdrawal capabilities.
SavingsAccount:
Enforces a minimum balance requirement (e.g., $100). Withdrawals are only permitted if the remaining balance meets or exceeds this minimum.
Simulates a savings account with restrictions to encourage saving.
Each derived class should implement the virtual methods according to its specific rules.
2. Customer Class
Purpose: Manage information about a bank customer and their associated accounts.
Requirements:
Define a Customer class with attributes such as:
name: The customer's full name.
contactInfo: Basic contact details (e.g., email or phone number).
A collection of accounts (e.g., a vector of Account pointers) owned by the customer.
Provide functionality to:
Add a new account to the customer's list.
Access or retrieve the list of accounts for further operations.
3. Transaction Class
Purpose: Record individual banking operations like deposits and withdrawals.
Requirements:
Create a Transaction class to encapsulate details of each operation, including:
A reference or identifier linking it to a specific account.
The transaction amount (e.g., $50.00).
The transaction type (e.g., "deposit" or "withdrawal").
A timestamp (could be a simple string like "2023-10-15 14:30" or derived from std::time).
This class should be used whenever a deposit or withdrawal occurs to log the activity.
4. Transaction History
Purpose: Track and display a history of transactions for accounts or customers.
Requirements:
Store a list of transactions either in the Account class (for per-account history) or the Customer class (for all accounts owned by the customer).
Use iterators to traverse this list and display transaction details, such as amount, type, and timestamp, in a readable format.
5. Template Function
Purpose: Provide a flexible way to display transaction information.
Requirements:
Implement a template function that can process and print details of transactions.
The function should be generic enough to work with different containers (e.g., a vector of transactions) or potentially different transaction types, allowing for future extensibility.
Example usage: Pass a transaction history list to the function to output details for each entry.
6. Custom Exceptions
Purpose: Handle error conditions gracefully during banking operations.
Requirements:
Define at least two custom exception classes:
InsufficientFundsException: Thrown when a withdrawal attempt exceeds the available balance (e.g., in CheckingAccount) or violates the minimum balance rule (e.g., in SavingsAccount).
InvalidTransactionException: Thrown for invalid operations, such as attempting to deposit a negative amount or other illogical actions.
Integrate these exceptions into the deposit and withdraw methods, ensuring they are thrown when appropriate and caught elsewhere (e.g., in main) to display error messages.
7. Main Function Demonstration
Purpose: Showcase the system’s functionality in a simple test scenario.
Requirements:
In the main function, include the following actions:
Create a Customer instance with at least one CheckingAccount and one SavingsAccount.
Perform a series of operations, such as:
Depositing money into both accounts.
Withdrawing money, including cases that should trigger exceptions (e.g., overdrawing a checking account or dropping below the savings account’s minimum balance).
Use iterators to display the transaction history for the customer’s accounts.
Catch and handle any exceptions, printing meaningful error messages (e.g., "Error: Insufficient funds").

What the Code Should Do
The completed system should simulate a basic banking environment where:
A customer can own multiple accounts (checking and savings).
Deposits and withdrawals can be performed, with appropriate rules enforced (e.g., minimum balance for savings).
Every transaction is recorded and can be reviewed using iterators.
Errors like insufficient funds or invalid inputs are caught and reported via custom exceptions.
A generic template function displays transaction details, demonstrating flexibility.
