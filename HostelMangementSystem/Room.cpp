#include <iostream>
#include <bits/stdc++.h>
#include "Student.cpp"

using namespace std;
class Room {
private:
    int roomNumber;
    bool occupied;

public:
    Room(int number) : roomNumber(number), occupied(false) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool isOccupied() const {
        return occupied;
    }

    void occupy() {
        occupied = true;
    }

    void vacate() {
        occupied = false;
    }
};

class RoomAllocator {
private:
    vector<Room> rooms;

public:
    RoomAllocator(int numRooms) {
        // Initialize rooms
        for (int i = 1; i <= numRooms; ++i) {
            rooms.push_back(Room(i));
        }
    }

    // Implement First Fit room allocation algorithm
    Room* allocateRoom(Student* student, int preferredRoomNumber = -1) {
        for (auto& room : rooms) {
            if (!room.isOccupied()) {
                room.occupy();
                return &room;
            }
        }
        return nullptr; // No available rooms
    }

    // Function to deallocate a room
    void deallocateRoom(Room* room) {
        if (room) {
            room->vacate();
        }
    }

};

int main() {
    RoomAllocator roomAllocator(1); // Create a room allocator with 1 room

    // Allocate rooms to students
    Student student1("Karim", "Sheikh", 20, 1);
    Room* allocatedRoom1 = roomAllocator.allocateRoom(&student1);

    Student student2("Rahim", "Sheikh", 18, 2);
    Room* allocatedRoom2 = roomAllocator.allocateRoom(&student2);

    if (allocatedRoom1) {
        student1.displayDetails();
        cout << "allocated to Room " << allocatedRoom1->getRoomNumber() << endl<<endl;
    } else {
        cout << "No rooms available for " << endl;
        student1.displayDetails();
    }

    if (allocatedRoom2) {
        student2.displayDetails();
        cout << "is allocated to Room " << allocatedRoom2->getRoomNumber() << endl<<endl;
    } else {
        cout << "No rooms available for " << endl;
        student2.displayDetails();
    }

    // Deallocate rooms when students leave
    roomAllocator.deallocateRoom(allocatedRoom1);
    roomAllocator.deallocateRoom(allocatedRoom2);

    return 0;
}
