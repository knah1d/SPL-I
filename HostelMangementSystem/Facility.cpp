#include <bits/stdc++.h>
using namespace std;
class Facility {
private:
    string facilityName;
    // Add other facility attributes as needed

public:
    Facility(string name) : facilityName(name) {}

    string getFacilityName() const {
        return facilityName;
    }

    // Add other getters and setters as needed
};

class FacilityManager {
private:
    vector<Facility> facilities; // Use a vector to store facility records
    unordered_map<string, Facility*> facilityMap; // Use a hash table for quick facility lookups

public:
    // Function to add a new facility
    void addFacility(string name) {
        Facility newFacility(name);
        facilities.push_back(newFacility);
        facilityMap[name] = &facilities.back();
    }

    // Function to retrieve a facility by name
    Facility* getFacilityByName(string name) {
        if (facilityMap.find(name) != facilityMap.end()) {
            return facilityMap[name];
        }
        return nullptr; // Facility not found
    }

    // Add other facility management functions as needed

    // Function to print all facility names
    void printAllFacilities() {
        for (const auto& facility : facilities) {
            cout << "Facility Name: " << facility.getFacilityName() << endl;
        }
    }
};

int main() {
    FacilityManager facilityManager;

    // Adding facilities
    facilityManager.addFacility("Window sided room");
    facilityManager.addFacility("Reading");
    facilityManager.addFacility("Library");

    // Retrieve and print a facility
    Facility* facility = facilityManager.getFacilityByName("Readingh");
    if (facility) {
        cout << "Facility Name: " << facility->getFacilityName() << endl;
    } else {
        cout << "Facility not found." << endl;
    }

    // Print all facilities
    facilityManager.printAllFacilities();

    return 0;
}
