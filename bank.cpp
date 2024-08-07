#include "bank.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Constructor: Initializes id and loads data from the file
bank::bank() : id(0) {
    load_data(); // Load data when the object is created
}

// Destructor: Saves data to the file when the object is destroyed
bank::~bank() {
    save_data(); // Save data when the object is destroyed
}

// Function to open a new account
void bank::open_account() {
    // Get user details
    string name = get_input<string>("Enter your full name: ");
    names.push_back(name);

    string address = get_input<string>("Enter your address: ");
    addresses.push_back(address);

    char type;
    while (true) {
        cout << "What type of account do you want to open, saving(s) or current(c): ";
        cin >> type;
        if (type == 's' || type == 'c') {
            account_types.push_back(type);
            break;
        }
        else {
            cout << "Invalid account type. Please enter 's' for saving or 'c' for current.\n";
        }
    }

    double balance = get_positive_double("Enter amount for deposit: ");
    balances.push_back(balance);

    cout << "Your account is created, and your id is: " << id << endl;
    id++;
}

// Function to deposit money into an account
void bank::deposit_money() {
    // Get deposit amount and user ID
    double money = get_positive_double("Enter how much you want to deposit: ");
    int ids = get_valid_id();

    // Increment the balance
    balances[ids] += money;
    cout << "The total amount now is: " << balances[ids] << endl;
}

// Function to display details of a specific account
void bank::display_account() {
    int ids = get_valid_id();

    cout << "Your full name: " << names[ids] << endl;
    cout << "Your address: " << addresses[ids] << endl;
    cout << "Type of account: " << (account_types[ids] == 's' ? "Saving" : "Current") << endl;
    cout << "Your balance: " << balances[ids] << endl;
}

// Function to display details of all users
void bank::display_all_users() {
    if (id == 0) {
        cout << "No Users in the Bank.\n";
        return;
    }

    cout << "All users of the bank:\n";
    for (int i = 0; i < id; ++i) {
        cout << "ID: " << i << endl;
        cout << "Full Name: " << names[i] << endl;
        cout << "Address: " << addresses[i] << endl;
        cout << "Account Type: " << (account_types[i] == 's' ? "Saving" : "Current") << endl;
        cout << "Balance: " << balances[i] << endl;
        cout << "----------------------\n";
    }
}

// Function to withdraw money from an account
void bank::withdraw_money() {
    int ids = get_valid_id();

    cout << "Your balance is: " << balances[ids] << endl;

    double amount;
    while (true) {
        amount = get_positive_double("Enter amount to withdraw: ");
        if (amount <= balances[ids]) {
            break;
        }
        else {
            cout << "Error, the amount is larger than balance. Try again.\n";
        }
    }

    balances[ids] -= amount;
    cout << "Your balance now is: " << balances[ids] << endl;
}

// Function to delete a user's account
void bank::delete_user() {
    int ids = get_valid_id();

    // Erase the user from the bank
    names.erase(names.begin() + ids);
    addresses.erase(addresses.begin() + ids);
    account_types.erase(account_types.begin() + ids);
    balances.erase(balances.begin() + ids);

    // Decrement ID
    cout << "User with ID " << ids << " has been deleted.\n";
    --id;
}

// Function to modify a user's account details
void bank::modify_account() {
    int ids = get_valid_id();

    // Modify user details
    names[ids] = get_input<string>("Enter your new full name: ");
    addresses[ids] = get_input<string>("Enter your new address: ");
    cout << "Account details updated successfully.\n";
}

// Function to transfer money between accounts
void bank::transfer_money() {
    int from_id = get_valid_id("Enter your ID: ");
    int to_id = get_valid_id("Enter the recipient's ID: ");

    double amount;
    while (true) {
        amount = get_positive_double("Enter amount to transfer: ");
        if (amount <= balances[from_id]) {
            break;
        }
        else {
            cout << "Error, the amount is larger than balance. Try again.\n";
        }
    }

    balances[from_id] -= amount;
    balances[to_id] += amount;
    cout << "Transfer successful. Your new balance is: " << balances[from_id] << endl;
}

// Function to load data from a file
void bank::load_data() {
    ifstream infile("bank_data.txt");
    if (!infile.is_open()) {
        return; // No file to read from, so just return
    }

    infile >> id;
    infile.ignore();

    for (int i = 0; i < id; ++i) {
        string name, address;
        char account_type;
        double balance;

        getline(infile, name);
        names.push_back(name);

        getline(infile, address);
        addresses.push_back(address);

        infile >> account_type;
        account_types.push_back(account_type);

        infile >> balance;
        balances.push_back(balance);
        infile.ignore();
    }

    infile.close();
}

// Function to save data to a file
void bank::save_data() {
    ofstream outfile("bank_data.txt");
    if (!outfile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    outfile << id << endl;

    for (int i = 0; i < id; ++i) {
        outfile << names[i] << endl;
        outfile << addresses[i] << endl;
        outfile << account_types[i] << endl;
        outfile << balances[i] << endl;
    }

    outfile.close();
}

// Helper function to get valid user input
template <typename T>
T bank::get_input(const string& prompt) {
    T input;
    cout << prompt;
    cin >> ws; // Clear leading whitespace
    getline(cin, input);
    return input;
}

// Helper function to get a positive double value
double bank::get_positive_double(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value) || value <= 0) {
        cin.clear(); // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive value: ";
    }
    return value;
}

// Helper function to get a valid ID
int bank::get_valid_id(const string& prompt) {
    int id;
    cout << prompt;
    while (!(cin >> id) || id < 0 || id >= this->id) {
        cin.clear(); // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID. Please enter a valid ID: ";
    }
    return id;
}
