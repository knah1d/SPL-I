class Complaint {
private:
    string text;
    // Add other complaint attributes

public:
    Complaint(string msg) : text(msg) {}

    string getText() const {
        return text;
    }

    // Add other getters and setters as needed
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

    // Implement functions to handle complaints (e.g., process in FIFO order)
};
