#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define PASSWORD "1511"
#define MAX_TRANSACTION_HISTORY 10
#define DATA_FILE "bank_data.txt"  // File to store data

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
    char transactionHistory[MAX_TRANSACTION_HISTORY][100];
    int transactionCount;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

// Function prototypes
void clearScreen();
int authenticate();
void createAccount();
void deposit();
void withdraw();
void transfer();
void displayAccount(int accountNumber);
void showTransactionHistory(int accountNumber);
void saveDataToFile();
void loadDataFromFile();

int main() {
    int choice;
    printf("Welcome to the Bank Management System\n");
    loadDataFromFile();  // Load data at startup
    if (!authenticate()) {
        printf("Incorrect password! Exiting...\n");
        return 0;
    }
    while (1) {
        clearScreen();  // Clear screen at the start of each iteration
        printf("\n1. Create Account\n2. Deposit\n3. Withdraw\n4. payment\n5. View Account\n");
        printf("6. View Transactions\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: transfer(); break;
            case 5: {
                int acc; printf("Enter Account Number: "); scanf("%d", &acc);
                displayAccount(acc); break;
            }
            case 6: {
                int acc; printf("Enter Account Number: "); scanf("%d", &acc);
                showTransactionHistory(acc); break;
            }
            case 7:
                saveDataToFile();  // Save data before exiting
                printf("Goodbye!\n");
                return 0;
            default: getchar();getchar(); printf("Invalid choice! Try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();getchar();   // Pause for the user to see output before clearing
    }
}

// Clear screen function (Windows-specific)
void clearScreen() {
    system("cls");  // Windows clear screen command
}

// Authentication function
int authenticate() {
    char inputPassword[20];
    printf("Enter password: ");
    scanf("%s", inputPassword);
    return strcmp(inputPassword, PASSWORD) == 0;
}

// Account creation
void createAccount() {
    clearScreen();
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Customer limit reached!\n");
        return;
    }
    Customer newCustomer = {0};
    printf("Enter Account Number: ");
    scanf("%d", &newCustomer.accountNumber);
    printf("Enter Name: ");
    scanf("%s", newCustomer.name);
    newCustomer.balance = 0.0;
    customers[customerCount++] = newCustomer;
    printf("Account created for %s!\n", newCustomer.name);
    saveDataToFile();  // Save data after creating account
}

// Deposit money
void deposit() {
    clearScreen();
    int account;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &account);
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == account) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (amount < 0) {
                printf("Invalid amount!");
                return;
            }
            customers[i].balance += amount;
            snprintf(customers[i].transactionHistory[customers[i].transactionCount++], 100, "Deposited %.2f", amount);
            printf("New Balance: %.2f\n", customers[i].balance);
            saveDataToFile();  // Save data after deposit
            return;
        }
    }
    printf("Account not found!\n");
}

// Withdraw money
void withdraw() {
    clearScreen();
    int account;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &account);
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == account) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (amount > customers[i].balance || amount < 0 ) {
                printf("Invalid amount or insufficient funds! ");
                return;
            }
            customers[i].balance -= amount;
            snprintf(customers[i].transactionHistory[customers[i].transactionCount++], 100, "Withdrew %.2f", amount);
            printf("New Balance: %.2f\n", customers[i].balance);
            saveDataToFile();  // Save data after withdrawal
            return;
        }
    }
    printf("Account not found!\n");
}

// Transfer money
void transfer() {
    clearScreen();
    int from, to;
    float amount;
    printf("Enter Your Account: ");
    scanf("%d", &from);
    printf("Enter Recipient Account: ");
    scanf("%d", &to);
    int fromIdx = -1, toIdx = -1;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == from) fromIdx = i;
        if (customers[i].accountNumber == to) toIdx = i;
    }
    if (fromIdx == -1 || toIdx == -1) {
        printf("Account not found!\n");
        return;
    }
    printf("Enter amount: ");
    scanf("%f", &amount);
    if (amount > customers[fromIdx].balance) {
        printf("Insufficient balance!\n");
        return;}
    customers[fromIdx].balance -= amount;
    printf("New balance (%d) =%.1f\n",from,customers[fromIdx].balance);
    customers[toIdx].balance += amount;
     printf("New balance (%d) =%.1f\n",to,customers[toIdx].balance);
    snprintf(customers[fromIdx].transactionHistory[customers[fromIdx].transactionCount++], 100, "Transferred %.2f to %d", amount, to);
    snprintf(customers[toIdx].transactionHistory[customers[toIdx].transactionCount++], 100, "Received %.2f from %d", amount, from);
    printf("Transfer Successful!\n");
    saveDataToFile();  // Save data after transfer
}
// Save data to file
void saveDataToFile() {
    FILE *file = fopen(DATA_FILE, "w");
    if (!file) {
        printf("Error saving data!\n");
        return;
    }
    fprintf(file, "%d\n", customerCount);  // Save number of customers
    for (int i = 0; i < customerCount; i++) {
        Customer *c = &customers[i];
        fprintf(file, "%d %s %.2f %d\n", c->accountNumber, c->name, c->balance, c->transactionCount);
        for (int j = 0; j < c->transactionCount; j++) {
            fprintf(file, "%s\n", c->transactionHistory[j]);
        }
    }
    fclose(file);
}

// Load data from file
void loadDataFromFile() {
    FILE *file = fopen(DATA_FILE, "r");
    if (!file) return;  // No file found (first time use)
    fscanf(file, "%d", &customerCount);  // Read number of customers
    for (int i = 0; i < customerCount; i++) {
        Customer *c = &customers[i];
        fscanf(file, "%d %s %f %d", &c->accountNumber, c->name, &c->balance, &c->transactionCount);
        for (int j = 0; j < c->transactionCount; j++) {
            fscanf(file, " %[^\n]", c->transactionHistory[j]);
        }
    }
    fclose(file);
}

// Display account details
void displayAccount(int acc) {
    clearScreen();
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == acc) {
            printf("Account: %d\nName: %s\nBalance: %.2f\n", acc, customers[i].name, customers[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Show transaction history
void showTransactionHistory(int accountNumber) {
    clearScreen();
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("\n--- Transaction History for Account %d ---\n", accountNumber);
            for (int j = 0; j < customers[i].transactionCount; j++) {
                printf("%d: %s\n", j + 1, customers[i].transactionHistory[j]);
            }
            return;
        }
    }
    printf("Account not found!\n");
}
