# Bank-Management-System-Using-C-Programming-Language
Bank Management System Using C Programming Language

Password: 1511

================================================================================
                     BANK MANAGEMENT SYSTEM - CODE EXPLANATION
================================================================================

--------------------------------------------------------------------------------
1. INTRODUCTION
--------------------------------------------------------------------------------
This document explains the implementation of a simple Bank Management System 
written in C. The program allows basic banking operations such as account 
creation, deposit, withdrawal, money transfer, viewing account details, and 
transaction history. Customer data is stored persistently in a text file.

--------------------------------------------------------------------------------
2. MAIN FUNCTION & WORKFLOW
--------------------------------------------------------------------------------
The main function serves as the entry point of the program. 
* It begins by calling 'loadDataFromFile' to load existing data at startup.
* It authenticates the user using a system-wide password.
* It provides a menu-driven interface using a continuous loop ('while(1)') and 
  a 'switch-case' structure to handle user choices.

The main menu includes the following options:
 1. Create Account
 2. Deposit
 3. Withdraw
 4. Payment (Transfer)
 5. View Account
 6. View Transactions
 7. Exit (Saves data automatically before closing)

--------------------------------------------------------------------------------
3. CORE SYSTEM FUNCTIONS
--------------------------------------------------------------------------------

3.1 Authentication
The authentication function prompts the user to enter a password. The entered 
password is compared to a predefined macro value ('1511') using 'strcmp'. 
If the password matches, the user is granted access; otherwise, the program exits.

3.2 Create Account
This function allows users to create a new bank account.
* It first checks if the system has reached the limit ('MAX_CUSTOMERS = 100').
* It collects details such as the account number and customer name.
* It initializes the account balance to 0.0 and transaction count to 0.
* It automatically saves the updated data to the text file.

3.3 Deposit Money
The deposit function allows users to add money to an existing account.
* It validates the account number by searching the 'customers' array.
* It ensures the input amount is non-negative.
* It updates the account balance and records the transaction in the history log.

3.4 Withdraw Money
This function lets users withdraw money from their account.
* It checks whether the account exists in the system.
* It ensures that the withdrawal amount is non-negative and does not exceed 
  the current available balance (insufficient funds check).
* If valid, it deducts the amount, updates the balance, and logs the transaction.

3.5 Transfer Money
The transfer function facilitates fund transfers between two distinct accounts.
* It verifies both the sender ('from') and the recipient ('to') accounts.
* It ensures sufficient balance exists in the sender's account.
* It updates the balances of both accounts simultaneously.
* The transaction is dynamically logged into the history of both customers.

--------------------------------------------------------------------------------
4. DATA PERSISTENCE & FILE HANDLING
--------------------------------------------------------------------------------
The program uses a local text file named 'bank_data.txt' to store customer data 
persistently, ensuring that data is not lost between program runs.

* 'saveDataToFile': Opens the file in write mode ("w") and exports the total 
  customer count, account details (number, name, balance), and the complete 
  transaction history lines.
* 'loadDataFromFile': Opens the file in read mode ("r") at startup, parses the 
  stored values, and repopulates the 'customers' structural array.

--------------------------------------------------------------------------------
5. ERROR HANDLING & VALIDATION
--------------------------------------------------------------------------------
The current program incorporates basic conditional error handling to manage:
* Insufficient funds during withdrawals and transfers.
* Invalid/negative amounts during deposits and withdrawals.
* Account not found errors for invalid account numbers.
* Maximum customer capacity guardrails.

--------------------------------------------------------------------------------
6. POTENTIAL ENHANCEMENTS
--------------------------------------------------------------------------------
To transition this prototype into a more robust and professional application, 
the following enhancements can be implemented:
 1. Unique ID Validation: Prevent duplicate account numbers during creation.
 2. Secure Cryptography: Secure password storage using hashing (e.g., SHA-256) 
    instead of plain text.
 3. Dynamic Memory Allocation: Use linked lists or dynamic arrays to expand 
    customer limits and transaction history dynamically.
 4. UI Improvement: Create a cross-platform clear-screen system and improve 
    the command-line interface layout.
 5. Robust File Validation: Gracefully handle missing files or data corruption 
    during file read/write operations.

================================================================================
