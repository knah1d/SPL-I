class Room {
private:
    int roomNumber;
    bool isOccupied;

public:
    Room(int number) : roomNumber(number), isOccupied(false) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool isOccupied() const {
        return isOccupied;
    }

};

class RoomAllocator {
private:
    vector<Room> rooms; 

public:
    void allocateRoom(Student* student, int preferredRoomNumber) {
    }

};
