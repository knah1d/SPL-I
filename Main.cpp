#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A class to represent an account
class Account {
  private:
    string name; // The name of the account
    double balance; // The current balance of the account
    vector<double> inflows; // The list of cash inflows to the account
    vector<double> outflows; // The list of cash outflows from the account
  public:
    // A constructor to initialize an account with a name and a balance
    Account(string n, double b) {
      name = n;
      balance = b;
    }
    // A function to get the name of the account
    string getName() {
      return name;
    }
    // A function to get the balance of the account
    double getBalance() {
      return balance;
    }
    // A function to add a cash inflow to the account
    void addInflow(double amount) {
      inflows.push_back(amount); // Add the amount to the inflows list
      balance += amount; // Update the balance
    }
    // A function to add a cash outflow from the account
    void addOutflow(double amount) {
      outflows.push_back(amount); // Add the amount to the outflows list
      balance -= amount; // Update the balance
    }
    // A function to print the summary of the account
    void printSummary() {
      cout << "Account name: " << name << "\n";
      cout << "Account balance: " << balance << "\n";
      cout << "Cash inflows: \n";
      for (double inflow : inflows) { // Loop through the inflows list
        cout << inflow << "\n";
      }
      cout << "Cash outflows: \n";
      for (double outflow : outflows) { // Loop through the outflows list
        cout << outflow << "\n";
      }
      cout << "\n";
    }
};

int main() {
  // Create an account object with a name and a balance
  Account myAccount("My Business", 1000.0);
  // Add some cash inflows and outflows to the account
  myAccount.addInflow(500.0); // Received payment from a customer
  myAccount.addOutflow(200.0); // Paid salary to an employee
  myAccount.addInflow(300.0); // Received interest from a bank deposit
  myAccount.addOutflow(100.0); // Paid tax to the government
  myAccount.addOutflow(50.0); // Bought some supplies
  // Print the summary of the account
  myAccount.printSummary();
  return 0;
}

