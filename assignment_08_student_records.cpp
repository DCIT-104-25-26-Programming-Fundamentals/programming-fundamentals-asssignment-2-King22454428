#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Student structure
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Calculate the average score of a student
double calculateAverage(const Student& student) {
    if (student.scores.empty()) {
        return 0.0;
    }

    double total = 0.0;

    for (double score : student.scores) {
        total += score;
    }

    return total / student.scores.size();
}

// Display the menu
void displayMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Feature 1: Add a student
void addStudent(vector<Student>& students) {
    Student student;
    int numberOfScores;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    cout << "How many scores? ";
    cin >> numberOfScores;

    if (numberOfScores < 0) {
        cout << "Error: Number of scores cannot be negative." << endl;
        return;
    }

    for (int i = 0; i < numberOfScores; i++) {
        double score;

        cout << "Enter score " << i + 1 << ": ";
        cin >> score;

        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student \"" << student.name
         << "\" added successfully." << endl;
}

// Feature 2: Display all students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records have been added yet." << endl;
        return;
    }

    cout << "\nStudent Records:" << endl;
    cout << "----------------------------------------" << endl;

    for (const Student& student : students) {
        cout << "Name: " << student.name << endl;
        cout << "ID: " << student.id << endl;

        cout << "Scores: ";

        for (double score : student.scores) {
            cout << score << " ";
        }

        cout << endl;

        cout << fixed << setprecision(2);
        cout << "Average: " << calculateAverage(student) << endl;

        cout << "----------------------------------------" << endl;
    }
}

// Feature 3: Calculate average score for a specific student
void findStudentAverage(const vector<Student>& students) {
    int searchID;

    cout << "Enter student ID: ";
    cin >> searchID;

    for (const Student& student : students) {
        if (student.id == searchID) {
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: "
                 << calculateAverage(student) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

int main() {
    vector<Student> students;

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayAllStudents(students);
                break;

            case 3:
                findStudentAverage(students);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Error: Invalid choice. Please choose between 1 and 4."
                     << endl;
        }

    } while (choice != 4);

    return 0;
}