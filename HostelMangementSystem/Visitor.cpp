#include <bits/stdc++.h>
using namespace std;
class Visitor {
private:
    int visitorId;
    string name;

public:
    Visitor(int id, string n) : visitorId(id), name(n) {}

    int getVisitorId() const {
        return visitorId;
    }

    string getName() const {
        return name;
    }

};

class VisitorManager {
private:
    vector<Visitor> visitors; // Use a vector to store visitor records

public:
    // Function to add a new visitor
    void addVisitor(int id, string name) {
        Visitor newVisitor(id, name);
        visitors.push_back(newVisitor);
    }

    // Function to search for a visitor by ID
    Visitor* searchVisitorById(int id) {
        for (auto& visitor : visitors) {
            if (visitor.getVisitorId() == id) {
                return &visitor;
            }
        }
        return nullptr; // Visitor not found
    }

    // Function to search for a visitor by name
    Visitor* searchVisitorByName(string name) {
        for (auto& visitor : visitors) {
            if (visitor.getName() == name) {
                return &visitor;
            }
        }
        return nullptr; // Visitor not found
    }

};

int main() {
    VisitorManager visitorManager;

    // Adding visitors
    visitorManager.addVisitor(1, "Rahim");
    visitorManager.addVisitor(2, "Karim");
    visitorManager.addVisitor(3, "Akash");

    // Search for a visitor by ID
    Visitor* visitorById = visitorManager.searchVisitorById(2);
    if (visitorById) {
        cout << "Visitor ID: " << visitorById->getVisitorId() << ", Name: " << visitorById->getName() << endl;
    } else {
        cout << "Visitor not found by ID." << endl;
    }

    // Search for a visitor by name
    Visitor* visitorByName = visitorManager.searchVisitorByName("Akash");
    if (visitorByName) {
        cout << "Visitor ID: " << visitorByName->getVisitorId() << ", Name: " << visitorByName->getName() << endl;
    } else {
        cout << "Visitor not found by name." << endl;
    }

    return 0;
}
