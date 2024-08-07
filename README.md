# Banking-Management-System

## Overview

The Bank Management System is a console-based application implemented in C++ that simulates basic banking operations. This project provides functionalities such as opening an account, depositing and withdrawing money, viewing account details, and transferring money between accounts. The system also includes persistent storage to save and load user data using file operations.

## Features
#### • Open Account: Create a new account by providing your name, address, account type (saving or current), and initial deposit.
#### • Deposit Money: Add funds to an existing account.
#### • Withdraw Money: Remove funds from an account with validation to ensure sufficient balance.
#### • Display Account: View the details of a specific account using a unique ID.
#### • Display All Users: List all user accounts with their details.
#### • Delete User: Remove an account from the system.
#### • Modify Account: Update account details such as name and address.
#### • Transfer Money: Transfer funds between two accounts.
#### • Data Persistence: Load and save user data from/to a file to ensure data is retained between program executions.

## File Sturcture
#### • bank.h: Header file defining the bank class and its methods.
#### • bank.cpp: Implementation file containing the definitions of the bank class methods.
#### • main.cpp: Client code that interacts with the user and utilizes the bank class.
#### • bank_data.txt: Data file used for storing user account information (created and updated automatically).

## Usage
#### 1 . Open Account: Select option 1 to create a new account. Enter your details as prompted.
#### 2 . Deposit Money: Choose option 2 to deposit funds into an existing account. Provide the account ID and amount to deposit.
#### 3 . Withdraw Money: Select option 3 to withdraw funds. Provide the account ID and amount to withdraw.
#### 4 . Display Account: Choose option 4 to view details of a specific account. Enter the account ID when prompted.
#### 5 . Delete User: Option 5 allows you to delete an account by providing the account ID.
#### 6 . Display All Users: Select option 6 to view details of all users.
#### 7 . Transfer Money: Option 7 lets you transfer funds between two accounts. Provide both account IDs and the transfer amount.
#### 8 . Exit: Option 8 exits the application.
