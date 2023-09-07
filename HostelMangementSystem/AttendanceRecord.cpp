class AttendanceRecord {
private:
    int studentId;
    string date;
    bool isInTime; // True for in-time, false for out-time
    // Add other attendance-related attributes

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

    // Add other getters and setters as needed
};

class AttendanceTracker {
private:
    vector<AttendanceRecord> attendanceRecords; // Use a vector to store attendance records
    // Use a data structure (e.g., priority queue) for efficient tracking

public:
    // Function to record attendance (in-time or out-time)
    void recordAttendance(int studentId, string date, bool isInTime) {
        AttendanceRecord record(studentId, date, isInTime);
        attendanceRecords.push_back(record);
        // Add logic to update the data structure for efficient tracking
    }

    // Implement functions for attendance reporting and analysis
};
