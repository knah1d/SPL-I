class FeeRecord {
private:
    int studentId;
    double amount;
    // Add other fee-related attributes

public:
    FeeRecord(int id, double amt) : studentId(id), amount(amt) {}

    int getStudentId() const {
        return studentId;
    }

    double getAmount() const {
        return amount;
    }

    // Add other getters and setters as needed
};

class FeeManager {
private:
    vector<FeeRecord> feeRecords; // Use a vector to store fee records
    // Use a data structure (e.g., priority queue) for pending payments

public:
    // Function to add a new fee record
    void addFeeRecord(int studentId, double amount) {
        FeeRecord newFeeRecord(studentId, amount);
        feeRecords.push_back(newFeeRecord);
        // Add logic to update the data structure for pending payments
    }

    // Implement functions to manage fee payments and pending payments
};
