#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <vector>

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
    string getPassword() const {
        return password;
    }

    bool authenticate(string inputPassword) const {
        return password == inputPassword;
    }
};

class AccessControl {
private:
    vector<User> users;
    string filename; // File to store usernames and passwords

public:
    AccessControl(const string& file) : filename(file) {
        // Load users from the file when the AccessControl object is created
        loadFromFile();
    }

    // Add a new user to the system and save to the file
    void addUser(string username, string password) {
        User newUser(username, password);
        users.push_back(newUser);

        // Save all users to the file
        saveToFile();
    }

    // Authenticate a user based on username and password from the file
    bool authenticateUser(string username, string password) {
        // Load users from the file before attempting authentication
        loadFromFile();

        for (const auto& user : users) {
            if (user.getUsername() == username) {
                return user.authenticate(password);
            }
        }

        return false;
    }

private:
    // Save all users to the file
    void saveToFile() {
        ofstream outFile(filename); // Open the file for writing
        if (outFile.is_open()) {
            for (const auto& user : users) {
                outFile << user.getUsername() << " " << user.getPassword() << endl;
            }
            outFile.close();
        } else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    // Load users from the file// ...

private:
    // Load users from the file
    void loadFromFile() {
        users.clear(); // Clear existing users

        ifstream inFile(filename);
        if (inFile.is_open()) {
            string username, password;
            while (inFile >> username >> password) {
                if (isUsernameTaken(username)) {
                    // If username is taken, prompt for a new one
                    username = promptForNewUsername(username);
                }
                User newUser(username, password);
                users.push_back(newUser);
            }
            inFile.close();
        } else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    // Check if a username is already taken
    bool isUsernameTaken(const string& username) const {
        for (const auto& user : users) {
            if (user.getUsername() == username) {
                return true;
            }
        }
        return false;
    }

    // Prompt user for a new username
    string promptForNewUsername(const string& oldUsername) const {
        string newUsername;
        do {
            cout << "Username '" << oldUsername << "' already exists. Please choose a different username: ";
            cin >> newUsername;
        } while (isUsernameTaken(newUsername));
        return newUsername;
    }
};


//    bool authenticate(string inputPassword) const {

//        return password == inputPassword;

 //   }
//};






// Class representing a person
class Person {

public:

    // Constructor to initialize person details
    Person(const string& firstName, const string& lastName, int age)
        : firstName(firstName), lastName(lastName), age(age) {}


    // Setters and getters for personal details
    void setFirstName(const string& fName) {

        firstName = fName;
    }

    void setLastName(const string& lName) {

        lastName = lName;
    }

    void setAge(int newAge) {

        age = newAge;
    }

    string getFirstName() const {

        return firstName;
    }

    string getLastName() const {

        return lastName;
    }

    int getAge() const {

        return age;
    }



    // Display details of the person
    void displayDetails() const {

        cout << "Name: " << firstName << " " << lastName << endl;

        cout << "Age: " << age << " years old" << endl;

    }

private:

    string firstName;
    string lastName;
    int age;


};

// Class representing a student, inheriting from Person
class Student : public Person {

public:

    // Constructor to initialize student details
    Student(const string& firstName, const string& lastName, int age, int studentId)

        : Person(firstName, lastName, age), studentId(studentId) {}


    // Setters and getters for student details
    void setStudentId(int id) {

        studentId = id;
    }

    int getStudentId() const {

        return studentId;

    }



    // Display details of the student (overrides displayDetails in Person)
    void displayDetails() const {

        Person::displayDetails();

        cout << "Student ID: " << studentId << endl;

    }



private:

    int studentId;

};



// Class representing staff
class Staff {


private:

    int staffId;
    string name;


public:

    // Constructor to initialize staff details
    Staff(int id, string n) : staffId(id), name(n) {}


    // Getters for staff details
    int getStaffId() const {

        return staffId;
    }


    string getName() const {

        return name;
    }
};




// Class managing staff members
class StaffManager {


private:

    vector<Staff> staffMembers;

    unordered_map<int, Staff*> staffMap;


public:
    // Add a new staff member
    void addStaff(int id, string name) {

        Staff newStaff(id, name);

        staffMembers.push_back(newStaff);


        staffMap[id] = &staffMembers.back();
    }

    // Get staff member by ID
    Staff* getStaffById(int id) {

        if (staffMap.find(id) != staffMap.end()) {

            return staffMap[id];
        }

        return nullptr;
    }



    // Print details of all staff members
    void printAllStaff() {

        for (const auto& staff : staffMembers) {

            cout << "Staff ID: " << staff.getStaffId() << ", Name: " << staff.getName() << endl;
        }
    }
};



// Class representing a room
class Room {


private:

    int roomNumber;
    bool occupied;
    vector<Room> rooms;

public:

    // Constructor to initialize room details
    Room(int number) : roomNumber(number), occupied(false) {}

    // Getters for room details
    int getRoomNumber() const {

        return roomNumber;
    }

    bool isOccupied() const {

        return occupied;

    }

    // Mark the room as occupied
    void occupy() {

        occupied = true;
    }

    // Mark the room as vacant
    void vacate() {

        occupied = false;
    }
};




// Class managing room allocation
class RoomAllocator {


private:

    vector<Room> rooms;


public:
    // Constructor to initialize rooms
    RoomAllocator(int numRooms) {

        for (int i = 1; i <= numRooms; ++i) {

            rooms.push_back(Room(i));

        }
    }



    // function to retrieve the rooms
    const vector<Room>& getRooms() const {

        return rooms;

    }

    // Allocate a room to a student
    Room* allocateRoom(Student* student, int preferredRoomNumber = -1) {

        for (auto& room : rooms) {

            if (!room.isOccupied()) {

                room.occupy();

                return &room;

            }

        }

        return nullptr;
    }


    // Deallocate a room (mark it as vacant)

    void deallocateRoom(Room* room) {

        if (room) {

            room->vacate();
        }
    }
};


// Class representing a facility

class Facility {


private:

    string facilityName;


public:

    // Constructor to initialize facility details
    Facility(string name) : facilityName(name) {}

    // Getter for facility name
    string getFacilityName() const {

        return facilityName;

    }
};




// Class managing facilities
class FacilityManager {


private:

    vector<Facility> facilities;
    unordered_map<string, Facility*> facilityMap;


public:
    // Add a new facility
    void addFacility(string name) {

        Facility newFacility(name);

        facilities.push_back(newFacility);

        facilityMap[name] = &facilities.back();

    }



    // Get facility by name
    Facility* getFacilityByName(string name) {

        if (facilityMap.find(name) != facilityMap.end()) {

            return facilityMap[name];

        }

        return nullptr;
    }

    // Print details of all facilities
    void printAllFacilities() {

        for (const auto& facility : facilities) {

            cout << "Facility Name: " << facility.getFacilityName() << endl;
        }
    }
};


// Class representing a fee record
class FeeRecord {

private:

    int studentId;
    double amount;


public:

    // Constructor to initialize fee record

    FeeRecord(int id, double amt) : studentId(id), amount(amt) {}


    // Getters for fee record details
    int getStudentId() const {

        return studentId;
    }

    double getAmount() const {

        return amount;
    }


    // Define the < operator for FeeRecord
    bool operator<(const FeeRecord& other) const {

        return amount < other.amount;

    }
};




// Class managing fee records and payments
//class FeeManager {

//private:
//    vector<FeeRecord> feeRecords;
//    std::priority_queue<FeeRecord> pendingPayments; // Use a priority queue for pending payments

// Class managing fee records and payments (continued)
class FeeManager {


private:

    vector<FeeRecord> feeRecords;
    priority_queue<FeeRecord> pendingPayments; // Use a priority queue for pending payments

public:
    // Function to add a new fee record
    void addFeeRecord(int studentId, double amount) {

        FeeRecord newFeeRecord(studentId, amount);

        feeRecords.push_back(newFeeRecord);

        pendingPayments.push(newFeeRecord);
    }

    // Function to process fee payment for the student with the highest pending payment
    void processFeePayment() {

        if (!pendingPayments.empty()) {

            FeeRecord highestPendingPayment = pendingPayments.top();

            pendingPayments.pop();

            // Implement logic to mark the payment as processed and update the fee record

            cout << "Processed payment of $" << highestPendingPayment.getAmount()
                      << " for Student ID: " << highestPendingPayment.getStudentId() << endl;
        } else {

            cout << "No pending payments." << endl;

        }
    }
    const priority_queue<FeeRecord>& getPendingPayments() const {

        return pendingPayments;

    }


};





// Class representing a complaint
class Complaint {

private:

    string text;


public:

    // Constructor to initialize complaint text
    Complaint(string msg) : text(msg) {}

    // Getter for complaint text
    string getText() const {

        return text;

    }
};

// Class managing complaints
class ComplaintManager {

private:

    queue<Complaint> complaints;


public:

    // Add a new complaint to the queue
    void addComplaint(string message) {

        Complaint newComplaint(message);

        complaints.push(newComplaint);

    }


    // Process all complaints in the queue
    void processComplaints() {

        while (!complaints.empty()) {

            Complaint currentComplaint = complaints.front();

            complaints.pop();

            cout << "Processing Complaint: " << currentComplaint.getText() << endl;

        }

        if (complaints.empty()) {

            cout << "No more complaints to process." << endl;
        }
    }
};

// Class representing a visitor
class Visitor {

private:

    int visitorId;

    string name;

public:

    // Constructor to initialize visitor details
    Visitor(int id, string n) : visitorId(id), name(n) {}

    // Getters for visitor details
    int getVisitorId() const {

        return visitorId;

    }

    string getName() const {

        return name;

    }

};

// Class managing visitors
class VisitorManager {

private:

    vector<Visitor> visitors;

public:
    // Add a new visitor
    void addVisitor(int id, string name) {

        Visitor newVisitor(id, name);

        visitors.push_back(newVisitor);

    }

    // Search for a visitor by ID
    Visitor* searchVisitorById(int id) {

        for (auto& visitor : visitors) {

            if (visitor.getVisitorId() == id) {

                return &visitor;

            }
        }

        return nullptr;
    }

    // Search for a visitor by name
    Visitor* searchVisitorByName(string name) {

        for (auto& visitor : visitors) {

            if (visitor.getName() == name) {

                return &visitor;
            }
        }

        return nullptr;
    }
};

// Class representing an attendance record
class AttendanceRecord {

private:
    int studentId;
    string date;
    bool isInTime;

public:
    // Constructor to initialize attendance record
    AttendanceRecord(int id, string d, bool isIn) : studentId(id), date(d), isInTime(isIn) {}

    // Getters for attendance record details
    int getStudentId() const {

        return studentId;

    }

    string getDate() const {

        return date;

    }


    bool isInTimeRecord() const {

        return isInTime;
    }
};

// Class managing attendance records
class AttendanceTracker {

private:
    vector<AttendanceRecord> attendanceRecords;

    priority_queue<string> inTimeQueue;

    priority_queue<string> outTimeQueue;

public:
    // Record attendance for a student
    void recordAttendance(int studentId, string date, bool isInTime) {

        AttendanceRecord record(studentId, date, isInTime);

        attendanceRecords.push_back(record);

        if (isInTime) {

            inTimeQueue.push(date);

        }

        else {

            outTimeQueue.push(date);
        }

    }



    // Get the latest in-time for a student
    string getLatestInTime(int studentId) {

        for (int i = attendanceRecords.size() - 1; i >= 0; --i) {

            if (attendanceRecords[i].getStudentId() == studentId && attendanceRecords[i].isInTimeRecord()) {

                return attendanceRecords[i].getDate();

            }

        }

        return "No in-time record found.";

    }

    // Get the latest out-time for a student
    string getLatestOutTime(int studentId) {

        for (int i = attendanceRecords.size() - 1; i >= 0; --i) {

            if (attendanceRecords[i].getStudentId() == studentId && !attendanceRecords[i].isInTimeRecord()) {

                return attendanceRecords[i].getDate();


            }

        }

        return "No out-time record found.";
    }

};


// Class for generating reports and analytics
class ReportAndAnalytics {
public:
    // Function to generate a report on the number of occupied rooms
    void generateOccupancyReport(const RoomAllocator& roomAllocator) {
        int occupiedRooms = 0;
        for (const auto& room : roomAllocator.getRooms()) {
            if (room.isOccupied()) {
                occupiedRooms++;
            }
        }

        cout << "Occupancy Report: " << occupiedRooms << " out of " << roomAllocator.getRooms().size() << " rooms are occupied." << endl;
    }

    // Function to generate a report on pending fee payments
    void generateFeePaymentReport(const FeeManager& feeManager) {
        cout << "Pending Fee Payments Report: " << endl;

        priority_queue<FeeRecord> pendingPayments = feeManager.getPendingPayments();
        while (!pendingPayments.empty()) {
            FeeRecord pendingPayment = pendingPayments.top();
            pendingPayments.pop();

            cout << "Student ID: " << pendingPayment.getStudentId() << ", Amount: $" << pendingPayment.getAmount() << endl;
        }

        if (feeManager.getPendingPayments().empty()) {
            cout << "No pending fee payments." << endl;
        }
    }

    // Add more functions for additional reports and analytics as needed
};





// Class representing a hostel
class Hostel {

public:
        AccessControl accessControl;

    StaffManager staffManager;

    RoomAllocator roomAllocator;

    FacilityManager facilityManager;

    FeeManager feeManager;

    ComplaintManager complaintManager;

    VisitorManager visitorManager;

    AttendanceTracker attendanceTracker;


    // Default constructor
Hostel() : accessControl("AccessControl.txt"), roomAllocator(10) {
        initializeHostel();
    }


    // Initialize the hostel with default data
    void initializeHostel() {


        //accessControl.addUser("user1", "password1");

        //accessControl.addUser("user2", "password2");


        // Staff Management Initialization
        staffManager.addStaff(1, "Asif");

        staffManager.addStaff(2, "Jawad");

        staffManager.addStaff(3, "Suvo");


        // Facility Management Initialization

        facilityManager.addFacility("Window sided room");

        facilityManager.addFacility("Reading");

        facilityManager.addFacility("Library");

        facilityManager.addFacility("common room");


        // Fee Management Initialization

        // Adding fee records
        feeManager.addFeeRecord(1, 100.0);
        feeManager.addFeeRecord(2, 150.0);
        feeManager.addFeeRecord(3, 75.0);

        // Complaint Management Initialization
        complaintManager.addComplaint("Water leakage in room 101.");
        complaintManager.addComplaint("Broken window in the common area.");

        // Visitor Management Initialization
        visitorManager.addVisitor(1, "Rahim");
        visitorManager.addVisitor(2, "Karim");
        visitorManager.addVisitor(3, "Akash");

        // Attendance Tracker Initialization
        attendanceTracker.recordAttendance(1, "2023-09-07 09:00 AM", true);
        attendanceTracker.recordAttendance(2, "2023-09-07 09:30 AM", true);
        attendanceTracker.recordAttendance(1, "2023-09-07 04:00 PM", false);
    }
};





// Main function
int main() {
    Hostel hostel;
    hostel.initializeHostel();


    // Access Control Initialization

    string complaint;
    int choice;
    do {
        cout << "1. Create a new user\n";
        cout << "2. Authenticate an existing user\n";
        cout << "0 0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Create a new user
                string username, password;
                cout << "Enter username: ";
                cin >> username;

                // Check if the username already exists
                while (hostel.accessControl.authenticateUser(username, "dummy")) {
                    cout << "Username '" << username << "' already exists. Please choose a different username: ";
                    cin >> username;
                }

                cout << "Enter password: ";
                cin >> password;

                // Add a new user and save to the file
                hostel.accessControl.addUser(username, password);
                cout << "User created successfully.\n";
                break;
            }
            case 2: {

        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        // Authenticate the user


        if (hostel.accessControl.authenticateUser(username, password)) {
            cout << "User authenticated successfully.\n";

            // Additional functionality for authenticated user
            int userType;
            cout << "\n\nSelect user type:\n";
            cout << "1. Admin\n";
            cout << "2. Regular User\n";
            cout << "Enter your choice: ";
            cin >> userType;

            switch (userType) {
                case 1:
                    // Admin functionality (access to all facilities)
                    cout << "Admin functionality: Access to all facilities.\n";
                    break;
                case 2:
                    // Regular User functionality
                    cout << "\n\nRegular User functionality:\n";
                    int userOption;
                    do {
                        cout << "1. View Remaining Payments\n";
                        cout << "2. Submit Complaint\n";
                        cout << "3. Search for Room Facility\n";
                        cout << "4. Book a Room\n";
                        cout << "0. Back to Main Menu\n";
                        cout << "Enter your choice: ";
                        cin >> userOption;

                        switch (userOption) {
                            case 1:
                                // View Remaining Payments
                                // Implement as needed
                                cout << "Viewing remaining payments...\n";
                                // For example:
                                // cout << "Remaining Payments: $" << getRemainingPayments(authenticatedUser) << endl;
                                break;
                            case 2:
                                // Submit Complaint
                                // Implement as needed

                                cin >> complaint;
                                hostel.complaintManager.addComplaint(complaint);
                                cout << "Submitting complaint...\n";
                                // For example:
                                // submitComplaint(authenticatedUser);
                                break;
                            case 3:
                                // Search for Room Facility
                                // Implement as needed
                                cout << "Searching for room facilities...\n";
                                // For example:
                                // searchRoomFacility(authenticatedUser);
                                break;
                            case 4:
                                // Book a Room
                                // Implement as needed
                                cout << "Booking a room...\n";
                                // For example:
                                // bookRoom(authenticatedUser);
                                break;
                            case 0:
                                cout << "Returning to the main menu...\n";
                                break;
                            default:
                                cout << "Invalid choice. Please enter a valid option.\n";
                        }
                    } while (userOption != 0);

                    break;
                default:
                    cout << "Invalid user type. Returning to the main menu.\n";
            }
        } else {
            cout << "User authentication failed.\n";
        }
    }

    // Example functions (replace with your actual implementations)
    // int getRemainingPayments(User* user) { /* Implement logic */ return 0; }
    // void submitComplaint(User* user) { /* Implement logic */ }
    // void searchRoomFacility(User* user) { /* Implement logic */ }
    // void bookRoom(User* user) { /* Implement logic */ }

    // .

// ...

            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);



    // Staff Management
    Staff* staff = hostel.staffManager.getStaffById(2);
    if (staff) {
        cout << "Staff ID: " << staff->getStaffId() << ", Name: " << staff->getName() << endl;
    } else {
        cout << "Staff member not found." << endl;
    }

    // Room Allocation
    Student student1("Karim", "Sheikh", 20, 1);
    Room* allocatedRoom1 = hostel.roomAllocator.allocateRoom(&student1);

    if (allocatedRoom1) {
        student1.displayDetails();
        cout << "allocated to Room " << allocatedRoom1->getRoomNumber() << endl << endl;
    } else {
        cout << "No rooms available for " << endl;
        student1.displayDetails();
    }

    // Facility Management
    Facility* facility = hostel.facilityManager.getFacilityByName("common room");
    if (facility) {
        cout << "Facility found." << endl;
        cout << "Facility Name: " << facility->getFacilityName() << endl;
    } else {
        cout << "Facility not found." << endl;
    }

    // Fee Management
    hostel.feeManager.processFeePayment();
    hostel.feeManager.processFeePayment();
    hostel.feeManager.processFeePayment();
    hostel.feeManager.processFeePayment();

    // Complaint Management
    hostel.complaintManager.processComplaints();
    hostel.complaintManager.processComplaints();

    // Visitor Management
    Visitor* visitorById = hostel.visitorManager.searchVisitorById(2);
    if (visitorById) {
        cout << "Visitor ID: " << visitorById->getVisitorId() << ", Name: " << visitorById->getName() << endl;
    } else {
        cout << "Visitor not found by ID." << endl;
    }

    Visitor* visitorByName = hostel.visitorManager.searchVisitorByName("Akash");
    if (visitorByName) {
        cout << "Visitor ID: " << visitorByName->getVisitorId() << ", Name: " << visitorByName->getName() << endl;
    } else {
        cout << "Visitor not found by name." << endl;
    }

    // Attendance Tracker
    string latestInTime = hostel.attendanceTracker.getLatestInTime(1);
    string latestOutTime = hostel.attendanceTracker.getLatestOutTime(1);

    cout << "Latest In-Time for Student 1: " << latestInTime << endl;
    cout << "Latest Out-Time for Student 1: " << latestOutTime << endl;


    ReportAndAnalytics reportAndAnalytics;

    // Generate and display reports
    reportAndAnalytics.generateOccupancyReport(hostel.roomAllocator);
    reportAndAnalytics.generateFeePaymentReport(hostel.feeManager);

    return 0;
}







