#include <bits/stdc++.h>
using namespace std;
class FeeRecord {
private:
    int studentId;
    double amount;
    
public:
    FeeRecord(int id, double amt) : studentId(id), amount(amt) {}

    int getStudentId() const {
        return studentId;
    }

    double getAmount() const {
        return amount;
    }
};

class FeeManager {
private:
    vector<FeeRecord> feeRecords; // Use a vector to store fee records
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
            cout << "Processed payment of $" << highestPendingPayment.getAmount() << " for Student ID: " << highestPendingPayment.getStudentId() << endl;
        } else {
            cout << "No pending payments." << endl;
        }
    }

    // Add other functions to manage fee payments and pending payments as needed
};

int main() {
    FeeManager feeManager;

    // Adding fee records
    feeManager.addFeeRecord(1, 100.0);
    feeManager.addFeeRecord(2, 150.0);
    feeManager.addFeeRecord(3, 75.0);

    // Process fee payments
    feeManager.processFeePayment();
    feeManager.processFeePayment();
    feeManager.processFeePayment();
    feeManager.processFeePayment();

    return 0;
}
