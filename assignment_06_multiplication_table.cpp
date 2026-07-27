#include <iostream>
using namespace std;

// Part A: Print the multiplication table for one number
void printSingleTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;

    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}

// Part B: Print multiplication tables from 1 to N
void printTablesUpToN(int n) {
    for (int number = 1; number <= n; number++) {
        cout << "Multiplication Table for " << number << ":" << endl;

        for (int i = 1; i <= 12; i++) {
            cout << number << " x " << i
                 << " = " << number * i << endl;
        }

        if (number < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int number;

    // Part A
    cout << "Enter a number for the multiplication table: ";
    cin >> number;

    if (number <= 0) {
        cout << "Error: Number must be positive." << endl;
        return 0;
    }

    printSingleTable(number);

    // Part B
    int n;

    cout << "\nEnter N to print tables from 1 to N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be positive." << endl;
        return 0;
    }

    printTablesUpToN(n);

    return 0;
}