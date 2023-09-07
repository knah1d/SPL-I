class Staff {
private:
    int staffId;
    string name;
    // Add other staff attributes

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

    // Add other staff management functions as needed
};
