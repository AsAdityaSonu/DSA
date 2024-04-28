#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int RollNo;
    string Name;
public:
    void GetDetails() {
        cout << "Enter student roll number: ";
        cin >> RollNo;
        cout << "Enter name of the student: ";
        cin.ignore();
        getline(cin, Name);
    }
    void DisplayDetails() {
        cout << "Roll number: " << RollNo << endl;
        cout << "Name: " << Name << endl;
    }
};

class Marks : public Student {
protected:
    int Subject;
    int Subject2;
public:
    void GetMarks() {
        cout << "Enter the marks of subject 1: ";
        cin >> Subject;
        cout << "Enter the marks of subject 2: ";
        cin >> Subject2;
    }
    void DisplayMarks() {
        cout << "Subject 1 marks: " << Subject << endl;
        cout << "Subject 2 marks: " << Subject2 << endl;
    }
};

class Result : public Marks {
private:
    int TotalMarks;
public:
    void CalculateResult() {
        TotalMarks = Subject + Subject2;
    }
    void DisplayResult() {
        cout << "Total marks: " << TotalMarks << endl;
        if (TotalMarks >= 50) {
            cout << "Status: PASSED" << endl;
        }
        else {
            cout << "Status: FAILED" << endl;
        }
    }
};

int main() {
    int num_students;
    cout << "Enter the number of students: ";
    cin >> num_students;

    Result* students[num_students];
    for (int i = 0; i < num_students; i++) {
        students[i] = new Result();
        students[i]->GetDetails();
        students[i]->GetMarks();
        students[i]->CalculateResult();
    }

    cout << endl;
    for (int i = 0; i < num_students; i++) {
        cout << "Student " << i+1 << ":" << endl;
        students[i]->DisplayDetails();
        students[i]->DisplayMarks();
        students[i]->DisplayResult();
        cout << endl;
    }

    for (int i = 0; i < num_students; i++) {
        delete students[i];
    }

    return 0;
}