#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.cpp"
#include "Staff.cpp"
#include "Facility.cpp"
using namespace std;

class HostelAnalytics {
private:
    vector<Student> students;
    vector<Staff> staffMembers;
    vector<Facility> facilities;

public:
    HostelAnalytics(const vector<Student>& studentsVec, const vector<Staff>& staffVec, const vector<Facility>& facilitiesVec)
        : students(studentsVec), staffMembers(staffVec), facilities(facilitiesVec) {}

    // Method to generate a report of all students
    void generateStudentReport() const {
        cout << "Student Report:\n";
        cout << setw(15) << "Name" << setw(10) << "Age" << setw(20) << "Course" << setw(15) << "Room Number" << endl;
        cout << "---------------------------------------------\n";

        for (const auto& student : students) {
            cout << setw(15) << student.name << setw(10) << student.age << setw(20) << student.course;

            if (student.roomNumber != -1) {
                cout << setw(15) << student.roomNumber;
            } else {
                cout << setw(15) << "Not Assigned";
            }

            cout << endl;
        }
    }

    // Method to generate a report of all staff members
    void generateStaffReport() const {
        cout << "Staff Report:\n";
        for (const auto& staff : staffMembers) {
            cout << "Staff ID: " << staff.getStaffId() << ", Name: " << staff.getName() << endl;
        }
    }

    // Method to generate a report of all facilities
    void generateFacilityReport() const {
        cout << "Facility Report:\n";
        for (const auto& facility : facilities) {
            cout << "Facility Name: " << facility.getFacilityName() << endl;
        }
    }

    // Method to perform analytics on student ages
    void analyzeStudentAges() const {
        vector<int> ages;

        for (const auto& student : students) {
            ages.push_back(student.age);
        }

        if (!ages.empty()) {
            int minAge = *min_element(ages.begin(), ages.end());
            int maxAge = *max_element(ages.begin(), ages.end());
            double averageAge = accumulate(ages.begin(), ages.end(), 0.0) / ages.size();

            cout << "Student Age Analytics:\n";
            cout << "Minimum Age: " << minAge << "\n";
            cout << "Maximum Age: " << maxAge << "\n";
            cout << "Average Age: " << averageAge << "\n";
        } else {
            cout << "No student data available for age analysis.\n";
        }
    }
};

int main() {
    // Assuming you have the vectors of students, staff, and facilities from the hostel management system

    vector<Student> students = { /* populate with student data */ };
    vector<Staff> staffMembers = { /* populate with staff data */ };
    vector<Facility> facilities = { /* populate with facility data */ };

    HostelAnalytics analytics(students, staffMembers, facilities);

    // Generate reports and perform analytics
    analytics.generateStudentReport();
    analytics.generateStaffReport();
    analytics.generateFacilityReport();
    analytics.analyzeStudentAges();

    return 0;
}
