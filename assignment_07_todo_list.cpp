#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Display the menu
void displayMenu() {
    cout << "\n============================" << endl;
    cout << "       TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Part 1: Add a task
void addTask(vector<string>& tasks) {
    string task;

    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);

    tasks.push_back(task);

    cout << "Task added: \"" << task << "\"" << endl;
}

// Part 2: View all tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    cout << "\nYour Tasks:" << endl;

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Part 3: Delete a task
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);

    int taskNumber;

    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string deletedTask = tasks[taskNumber - 1];

    tasks.erase(tasks.begin() + (taskNumber - 1));

    cout << "Task \"" << deletedTask << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                deleteTask(tasks);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Error: Invalid choice. Please choose between 1 and 4." << endl;
        }

    } while (choice != 4);

    return 0;
}