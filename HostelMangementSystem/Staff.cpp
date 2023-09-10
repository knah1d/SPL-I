#include <bits/stdc++.h>
using namespace std;

class Staff {
private:
    int staffId;
    string name;
    // Add other staff attributes as needed

public:
    Staff(int id, string n) : staffId(id), name(n) {}

    int getStaffId() const {
        return staffId;
    }

    string getName() const {
        return name;
    }

    // Add other getters and setters as needed
};

class StaffManager {
private:
    vector<Staff> staffMembers; // Use a vector to store staff records
    unordered_map<int, Staff*> staffMap; // Use a hash table for quick staff lookups

public:
    // Function to add a new staff member
    void addStaff(int id, string name) {
        Staff newStaff(id, name);
        staffMembers.push_back(newStaff);
        staffMap[id] = &staffMembers.back();
    }

    // Function to retrieve staff by ID
    Staff* getStaffById(int id) {
        if (staffMap.find(id) != staffMap.end()) {
            return staffMap[id];
        }
        return nullptr; // Staff member not found
    }

    // Function to print all staff members
    void printAllStaff() {
        for (const auto& staff : staffMembers) {
            cout << "Staff ID: " << staff.getStaffId() << ", Name: " << staff.getName() << endl;
        }
    }

    // Add other staff management functions as needed
};

int main() {
    StaffManager staffManager;

    // Adding staff members
    staffManager.addStaff(1, "Asif");
    staffManager.addStaff(2, "Jawad");
    staffManager.addStaff(3, "Suvo");

    // Retrieve and print staff information
    Staff* staff = staffManager.getStaffById(2);
    if (staff) {
        cout << "Staff ID: " << staff->getStaffId() << ", Name: " << staff->getName() << endl;
    } else {
        cout << "Staff member not found." << endl;
    }

    // Print all staff members
    staffManager.printAllStaff();

    return 0;
}
