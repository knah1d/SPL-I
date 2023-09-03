#include <iostream>
#include <fstream>
using namespace std;

class StudentManagement
{
private:
    struct Student
    {
        int id;
        string name;
        int age;
    };

    const char *filename;

public:
    StudentManagement(const char *filename) : filename(filename) {}

    // Function to add a new student record
    void addStudent()
    {
        ofstream outFile(filename, ios::app);

        if (!outFile)
        {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        Student student;

        cout << "Enter student ID: ";
        cin >> student.id;

        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, student.name);

        cout << "Enter student age: ";
        cin >> student.age;

        outFile << student.id << ' ' << student.name << ' ' << student.age << '\n';

        outFile.close();
    }
// Function to display a specific student record by ID
void displayStudentById() {
    int searchId;
    cout<<"Enter Search Id: ";
    cin>>searchId;
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    Student student;
    bool found = false;

    while (inFile >> student.id) {
        inFile.ignore(); // Consume the newline character after ID
        std::getline(inFile, student.name);
        inFile >> student.age;

        if (student.id == searchId) {
            std::cout << "Student Record Found:\n";
            std::cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << '\n';
            found = true;
            break; // Stop searching after finding the record
        }

        inFile.ignore(); // Consume the newline character after age
    }

    inFile.close();

    if (!found) {
        std::cout << "Student with ID " << searchId << " not found.\n";
    }
}
};

int main()
{
    const char *filename = "student_records.txt";
    StudentManagement studentManager(filename);

    int choice;

    do
    {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentManager.addStudent();
            break;
        case 2:
            studentManager.displayStudentById();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
