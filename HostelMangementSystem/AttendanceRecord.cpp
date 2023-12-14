#include <bits/stdc++.h>
using namespace std;
class AttendanceRecord {
private:
    int studentId;
    string date;
    bool isInTime; 

public:
    AttendanceRecord(int id, string d, bool isIn) : studentId(id), date(d), isInTime(isIn) {}

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

class AttendanceTracker {
private:
    vector<AttendanceRecord> attendanceRecords; // Use a vector to store attendance records
    priority_queue<string> inTimeQueue; // Use a priority queue for in-time tracking
    priority_queue<string> outTimeQueue; // Use a priority queue for out-time tracking

public:
    // Function to record attendance (in-time or out-time)
    void recordAttendance(int studentId, string date, bool isInTime) {
        AttendanceRecord record(studentId, date, isInTime);
        attendanceRecords.push_back(record);

        // Update the in-time or out-time tracking queues based on the record
        if (isInTime) {
            inTimeQueue.push(date);
        } else {
            outTimeQueue.push(date);
        }
    }

    // Function to get the latest in-time record for a student
    string getLatestInTime(int studentId) {
        for (int i = attendanceRecords.size() - 1; i >= 0; --i) {
            if (attendanceRecords[i].getStudentId() == studentId && attendanceRecords[i].isInTimeRecord()) {
                return attendanceRecords[i].getDate();
            }
        }
        return "No in-time record found.";
    }

    // Function to get the latest out-time record for a student
    string getLatestOutTime(int studentId) {
        for (int i = attendanceRecords.size() - 1; i >= 0; --i) {
            if (attendanceRecords[i].getStudentId() == studentId && !attendanceRecords[i].isInTimeRecord()) {
                return attendanceRecords[i].getDate();
            }
        }
        return "No out-time record found.";
    }

};

int main() {
    AttendanceTracker attendanceTracker;
    attendanceTracker.recordAttendance(1, "2023-09-07 09:00 AM", true);
    attendanceTracker.recordAttendance(2, "2023-09-07 09:30 AM", true);
    attendanceTracker.recordAttendance(1, "2023-09-07 04:00 PM", false);

    // Get the latest in-time and out-time records for a student
    string latestInTime = attendanceTracker.getLatestInTime(1);
    string latestOutTime = attendanceTracker.getLatestOutTime(1);

    cout << "Latest In-Time for Student 1: " << latestInTime << endl;
    cout << "Latest Out-Time for Student 1: " << latestOutTime << endl;

    return 0;
}
