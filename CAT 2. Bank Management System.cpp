#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Base class for Account
class ACCOUNT {
protected:
    string email;    // Email of the account holder
    int ID;          // ID of the account holder
    string frtNme, lName;  // First and last name of the account holder

public:
    // Default constructor with initializer list
    ACCOUNT() : email(""), ID(0), frtNme(""), lName("") {}

    // Virtual destructor to allow proper cleanup of derived class objects
    virtual ~ACCOUNT() {
        cout << "Account for " << frtNme << " " << lName << " is being closed." << endl;
    }
   void Test()
  {
  	cout<<"\n...WELCOME TO BANKING SYSTEM...\n\n";
  	string choice;
  	cout<<"\n...Please select Option.\n";
  	cout<<"1) Continue...\n";
  	cout<<"2) Quit...\n";
  	cout<<" Enter Choice :";
  	cin>>choice;
  	
	  
  	if(choice == "1")
	  {
  		void client_Personal_Details();
	  }
	  else if (choice == "2")
	  {
	  	cout<<"\n";
	  	cout<<"You quit.Thank you and Welcome Again. ";
	  	exit(0); // Exit the program
	  	 }
	  	 else 
	  	 {
	  	 	cout<<"Invalid choice. please try Again.\n";
		  Test(); //re-prompt for input	
  }
  }
    // Method to input personal details of the client
    void client_Personal_Details() {
    	
        cout << "\n...Enter your Personal Details...\n\n";
        cout << "Enter your first Name: ";
        cin >> frtNme;
        cout << "\nEnter your last Name: ";
        cin >> lName;
        cout << "\nEnter your ID number: ";
        cin >> ID;
        cout << "\nEnter your Email Address: ";
        cin >> email;
        cout << "\nDetails saved successfully...";
    }

    // Pure virtual functions to be implemented by derived classes
    virtual void display_acc_info() const = 0;
    virtual void deposit(float amount) = 0;
    virtual void withdraw(float amount) = 0;
};

// Derived class for Client
class Client : public ACCOUNT {
private:
    int acc_no;          // Account number
    long int amt;        // Account balance
    string acc_type;     // Account type
    string acctype[6] = { "saving", "current", "fixed", "SAVING", "CURRENT", "FIXED" };  // Valid account types

public:
    static int temp;     // Static variable to generate unique account numbers

    // Default constructor
    Client() : acc_no(0), amt(0), acc_type("") {}

    // Destructor
    ~Client() override {}

    // Method to check the validity of account type
    int check_type() {
        try {
            for (int i = 0; i < 6; i++) {
                if (acc_type == acctype[i]) {
                    return 0;
                }
            }
            throw runtime_error("Invalid account type...");
        } catch (const runtime_error& client) {
            cerr << "Exception: " << client.what() << endl;
            return 1;
        }
    }

    // Method to check the initial balance
    int check_initial_balance() {
    	// use exception handling
        try {
            if (amt < 1000) {
                throw runtime_error("Account opening amount cannot be less than 1000 KES...");
            } else {
                return 0;
            }
        } catch (const runtime_error& client) {
            cerr << "Exception: " << client.what() << endl;
            return 1;
        }
    }

    // Method to set data for a new account
    void setdata() {
        client_Personal_Details();
        cout << "\n...Please select...\n";
        cout << "1) OPEN ACCOUNT\n";
        cout << "2) EXIT\n";
        cout<<"\n";
        cout << "Enter choice: ";
        string choice;
        cin >> choice;

        if (choice == "1") {
            acc_no = temp++;
             cout<<"\n";
            cout<<"Acount types are: current,fixed and saving.\n";
            cout << "\nEnter account Type: ";
            cin >> acc_type;
            cout << "\nEnter account Opening amount (initial): ";
            cin >> amt;
        }
        else if (choice == "2") {
        	cout<<"\n";
            cout << "You Quit.\n";
            exit(0);
        }
        else 
        {
        	cout<<"Invalid Choice..Please try Again.\n";
		}

        // Validate account type
        while (check_type()) {
            cout << "\nPlease Enter again: ";
            cin >> acc_type;
        }
        // Validate initial balance
        while (check_initial_balance()) {
            cout << "\nPlease Enter again: ";
            cin >> amt;
        }
    }

    // Override to display account information
    void display_acc_info() const override {
    	cout<<"\n";
        cout << "Account owner name: " << frtNme << " " << lName << endl;
        cout << "Account number: " << acc_no << endl;
        cout << "Account type: " << acc_type << endl;
        cout << "Account Balance: " << fixed << setprecision(2) << amt << endl;
    }

    // Override to deposit amount into the account
    void deposit(float amount) override {
        amt += amount;
        cout << amount << " has been deposited to your account.\n";
        cout << "Current Balance: " << fixed << setprecision(2) << amt << endl;
    }

    // Override to withdraw amount from the account
    void withdraw(float amount) override {
        if (amount > amt) {
            cout << "Insufficient funds.\n";
            return;
        }
        amt -= amount;
        cout << amount << " has been withdrawn from your account.\n";
        cout << "Current Balance: " << fixed << setprecision(2) << amt << endl;
    }
};

// Initialize static member variable
int Client::temp = -2200000000;

// Bank class to manage multiple accounts
class Bank {
private:
    vector<ACCOUNT*> accounts;  // Vector to store pointers to ACCOUNT objects

public:
    // Destructor to clean up dynamically allocated accounts
    ~Bank() {
        for (size_t i = 0; i < accounts.size(); ++i) {
            delete accounts[i];
        }
    }

    // Method to add a new account to the bank
    void addAccount(ACCOUNT* account) {
        accounts.push_back(account);
    }

    // Method to display all accounts in the bank
    void displayAllAccounts() const {
        for (size_t i = 0; i < accounts.size(); ++i) {
            accounts[i]->display_acc_info();
        }
    }
};

int main() {
    Bank bank;  // Create a Bank object
    Client obj;  // Create a Client object
    obj.Test(); // create a client choice
    obj.setdata();  // Set data for the client
    bank.addAccount(&obj);  // Add the client account to the bank

    int ch;  // Variable to store user's choice
    float amount;  // Variable to store amount for deposit/withdrawal

    // Loop to perform banking operations
    do {
    	cout<<"\n";
        cout << ",,,,,,,,,Banking Operation,,,,,,,,,\n";
        cout<<"\n";
        cout << "1) Deposit Amount.\n";
        cout << "2) Withdraw Amount.\n";
        cout << "3) Display account information.\n";
        cout << "4) Exit\n";

        cout << "Please select option: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            obj.deposit(amount);  // Deposit amount
            break;
        case 2:
            cout << "Enter withdraw amount: ";
            cin >> amount;
            obj.withdraw(amount);  // Withdraw amount
            break;
        case 3:
            obj.display_acc_info();  // Display account information
            break;
        }

    } while (ch != 4);  // Exit the loop if the user selects 4

    return 0;
}
