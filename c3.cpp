#include <iostream>
#include <string>
using namespace std;

// Tier 1: Base Class
class Student {
protected:
    int studentID;
    string name;
public:
    void setStudent(int id, string n) {
        studentID = id;
        name = n;
    }
};

// Tier 2: Intermediate Derived Class
class AcademicRecord : public Student {
protected:
    float cgpa;
public:
    void setCGPA(float c) {
        cgpa = c;
    }
};

// Tier 3: Final Derived Class (Multi-level Inheritance)
class GraduationResult : public AcademicRecord {
public:
    void determineHonors() {
        cout << "[Graduation Honors Report]" << endl;
        cout << "Student: " << name << " (ID: " << studentID << ")" << endl;
        cout << "CGPA: " << cgpa << endl;
        
        if (cgpa >= 9.0) cout << "Honors: Summa Cum Laude\n" << endl;
        else if (cgpa >= 8.0) cout << "Honors: Magna Cum Laude\n" << endl;
        else cout << "Honors: Graduated\n" << endl;
    }
};

int main() {
    GraduationResult student;
    student.setStudent(325036, "Alice");
    student.setCGPA(9.2);
    student.determineHonors();
    return 0;
}