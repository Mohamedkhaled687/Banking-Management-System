#include <vector>
#include <string>

using namespace std;

class bank {
public:
    bank(); // Constructor to initialize the id and load data
    ~bank(); // Destructor to save data when the object is destroyed

    void open_account(); // Function to open a new account
    void deposit_money(); // Function to deposit money into an account
    void display_account(); // Function to display details of a specific account
    void display_all_users(); // Function to display details of all users
    void withdraw_money(); // Function to withdraw money from an account
    void delete_user(); // Function to delete a user's account
    void modify_account(); // Function to modify a user's account details
    void transfer_money(); // Function to transfer money between accounts

    void load_data(); // Function to load data from a file
    void save_data(); // Function to save data to a file

private:
    vector<string> names; // Vector to store user names
    vector<string> addresses; // Vector to store user addresses
    vector<char> account_types; // Vector to store account types
    vector<double> balances; // Vector to store account balances
    int id; // Variable to store the next account ID

    // Helper function to get valid user input
    template <typename T>
    T get_input(const string& prompt);

    // Helper function to get a positive double value
    double get_positive_double(const string& prompt);

    // Helper function to get a valid ID
    int get_valid_id(const string& prompt = "Enter your ID: ");
};
