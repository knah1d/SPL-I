#include <bits/stdc++.h>
#include "Person.cpp"
using namespace std;
class Student : public Person {
public:
    Student(const string& firstName, const string& lastName, int age, int studentId)
        : Person(firstName, lastName, age), studentId(studentId) {}

    void setStudentId(int id) {
        studentId = id;
    }

    int getStudentId() const {
        return studentId;
    }

    void displayDetails() const {
        Person::displayDetails();
        cout << "Student ID: " << studentId << endl;
    }

private:
    int studentId;
};

