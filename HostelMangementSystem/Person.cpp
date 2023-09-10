#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    Person(const string& firstName, const string& lastName, int age)
        : firstName(firstName), lastName(lastName), age(age) {}

    void setFirstName(const string& fName) {
        firstName = fName;
    }

    void setLastName(const string& lName) {
        lastName = lName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    int getAge() const {
        return age;
    }

    void displayDetails() const {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << " years old" << endl;
    }

private:
    string firstName;
    string lastName;
    int age;
};
