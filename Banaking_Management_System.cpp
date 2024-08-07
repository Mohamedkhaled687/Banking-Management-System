#include <iostream>
#include "bank.h"

using namespace std;

void choice(bank& user);

int main() {
    bank user;

    char x;
    do {
        choice(user);

        cout << "\nDo you want to select another option? Press 'y' for yes, 'n' for no: ";
        cin >> x;
    } while (x == 'y' || x == 'Y');

    return 0;
}

void choice(bank& user) {
    int choice;
    cout << "-------------------------------------------------------\n";
    cout << "1) Open account\n";
    cout << "2) Deposit money\n";
    cout << "3) Withdraw money\n";
    cout << "4) Display account\n";
    cout << "5) Delete a User\n";
    cout << "6) Display all users\n";
    cout << "7) Modify account\n";
    cout << "8) Transfer money\n";
    cout << "9) Exit\n";
    
    cout << "Enter Choice : ";
    cin >> choice;
    cout << "-------------------------------------------------------\n";


    switch (choice) {
    case 1:
        user.open_account();
        break;
    case 2:
        user.deposit_money();
        break;
    case 3:
        user.withdraw_money();
        break;
    case 4:
        user.display_account();
        break;
    case 5:
