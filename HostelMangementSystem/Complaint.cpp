#include <bits/stdc++.h>
using namespace std;

class Complaint {
private:
    string text;

public:
    Complaint(string msg) : text(msg) {}

    string getText() const {
        return text;
    }

    
};

class ComplaintManager {
private:
    queue<Complaint> complaints; // Use a queue to store complaints

public:
    // Function to add a new complaint
    void addComplaint(string message) {
        Complaint newComplaint(message);
        complaints.push(newComplaint);
    }

    // Function to process complaints in FIFO order
    void processComplaints() {
        while (!complaints.empty()) {
            Complaint currentComplaint = complaints.front();
            complaints.pop();

            // Implement logic to handle the complaint (e.g., print or take action)
            cout << "Processing Complaint: " << currentComplaint.getText() << endl;
        }

        if (complaints.empty()) {
            cout << "No more complaints to process." << endl;
        }
    }


};

int main() {
    ComplaintManager complaintManager;

    // Adding complaints
    complaintManager.addComplaint("Water leakage in room 101.");

    complaintManager.addComplaint("Broken window in the common area.");

    // Process complaints
    complaintManager.processComplaints();
    complaintManager.processComplaints();

    return 0;
}
