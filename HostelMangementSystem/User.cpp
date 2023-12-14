#include <bits/stdc++.h>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    User(string uname, string pwd) : username(uname), password(pwd) {}

    string getUsername() const {
        return username;
    }

    // Method to authenticate a user
    bool authenticate(string inputPassword) const {
        return password == inputPassword;
    }

};

class AccessControl {
private:
    vector<User> users; // Store user accounts

public:
    // Function to add a new user
    void addUser(string username, string password) {
        User newUser(username, password);
        users.push_back(newUser);
    }

    // Method to authenticate a user by username and password
    bool authenticateUser(string username, string password) {
        for (const auto& user : users) {
            if (user.getUsername() == username) {
                return user.authenticate(password);
            }
        }
        return false; // User not found or incorrect credentials
    }

};

int main() {
    AccessControl accessControl;

    // Register users
    accessControl.addUser("user1", "password1");
    accessControl.addUser("user2", "password2");

    // Authenticate users
    bool authResult1 = accessControl.authenticateUser("user1", "password1");
    bool authResult2 = accessControl.authenticateUser("user2", "wrong_password");

    if (authResult1) {
        cout << "User1 authenticated successfully." << endl;
    } else {
        cout << "User1 authentication failed." << endl;
    }

    if (authResult2) {
        cout << "User2 authenticated successfully." << endl;
    } else {
        cout << "User2 authentication failed." << endl;
    }

    return 0;
}
