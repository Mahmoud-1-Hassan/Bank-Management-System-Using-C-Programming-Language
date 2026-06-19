# Bank-Management-System-Using-C-Programming-Language
Bank Management System Using C Programming Language

Password: 1511

# Bank Management System - Code Explanation
Introduction

This document explains the implementation of a simple Bank Management 

System written in C. The program allows basic banking operations such as 

account creation, deposit, withdrawal, money transfer, viewing account 

details, and transaction history. Customer data is stored persistently in a text 
file.



Main Function

The main function serves as the entry point of the program.

It begins by authenticating the user with a password and then provides a menu-driven 
interface for performing various banking operations.

The main menu includes options for creating an account, depositing money, withdrawing money, 
transferring funds, viewing account details, and viewing transaction history.



Authentication

The authentication function prompts the user to enter a password.

The entered password is compared to a predefined value ('1511'). If the password 
matches, the user is granted access; otherwise, the program exits.



Create Account

This function allows users to create a new bank account.

It collects details such as account number and customer name, initializes the account balance 
to zero, and saves the data to the file.

It also ensures that the number of accounts does not exceed the predefined limit.



Deposit Money

The deposit function allows users to add money to an existing account.

It validates the account number, ensures the amount is non-negative, updates 
the account balance, and records the transaction in the history.



Withdraw Money

This function lets users withdraw money from their account. 

It checks whether the account exists and whether there are sufficient funds for the 
withdrawal. If valid, it updates the account balance and logs the transaction.



Transfer Money

The transfer function facilitates fund transfers between two accounts. 

It verifies both accounts, ensures sufficient balance in the sender's account, 
and updates the balances of both accounts.

The transaction is logged for both the sender and the recipient.



File Handling

The program uses a file ('bank_data.txt') to store customer data persistently. 
The 'saveDataToFile' function writes the account details and transaction 
history to the file, while the 'loadDataFromFile' function reads the data when 
the program starts.

This ensures that data is not lost between program runs.

Error Handling The program incorporates basic error handling to manage scenarios such as 
insufficient funds during withdrawals, invalid account numbers, and 
exceeding the transaction history limit.

Additional validation could be added to improve robustness.



Potential Enhancements

1. Validate unique account numbers during account creation.
   
2. Secure password storage using hashing.
   
3. Dynamically expand transaction history instead of setting a fixed limit.
   
4. Improve the user interface for better usability.
   
5. Handle file read/write errors more gracefully
