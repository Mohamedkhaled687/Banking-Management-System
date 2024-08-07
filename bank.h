#include <vector>
#include <string>

using namespace std;

class bank {
public:
    bank(); // Constructor to initialize the id
    ~bank(); // Destructor to save data when the object is destroyed
    void open_account();
    void deposit_money();
    void display_account();
    void display_all_users();
    void withdraw_money();
    void delete_user();
    void load_data(); // Function to load data from a file
    void save_data(); // Function to save data to a file

private:
    vector<string> names;
    vector<string> addresses;
    vector<char> account_types;
    vector<double> balances;
    int id;
};
