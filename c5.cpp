#include <iostream>
#include <string>
using namespace std;

// Root Class
class Person {
protected:
    string name;
public:
    void setName(string n) {
        name = n;
    }
    void displayPerson() {
        cout << "Name: " << name << endl;
    }
};

// Derived Class 1 (Virtual Inheritance)
class Teacher : virtual public Person {
protected:
    string department;
public:
    void setDepartment(string dept) {
        department = dept;
    }
};

// Derived Class 2 (Virtual Inheritance)
class Student : virtual public Person {
protected:
    string major;
public:
    void setMajor(string m) {
        major = m;
    }
};

// Final Derived Class (Hybrid Inheritance)
class TeachingAssistant : public Teacher, public Student {
private:
    int hoursPerWeek;
public:
    void setTADetails(string n, string dept, string maj, int hours) {
        // Because of virtual inheritance, setName is unambiguous
        setName(n); 
        setDepartment(dept);
        setMajor(maj);
        hoursPerWeek = hours;
    }
    
    void displayTARecord() {
        cout << "[Teaching Assistant Record]" << endl;
        displayPerson();
        cout << "Department (Teacher Role): " << department << endl;
        cout << "Major (Student Role): " << major << endl;
        cout << "Assigned Hours: " << hoursPerWeek << "/week" << endl;
    }
};

int main() {
    TeachingAssistant ta;
    ta.setTADetails("John Doe", "Computer Science", "Data Science", 15);
    ta.displayTARecord();
    return 0;
}