#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int calculateModulus(int a, int b) {
    return a % b;
}

double exponent(double base, double power) {
    return pow(base, power);
}

void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice. Please select a number from 1 to 7."
                 << endl;
            continue;
        }

        double firstNumber;
        double secondNumber;

        cout << "Enter first number: ";
        cin >> firstNumber;

        cout << "Enter second number: ";
        cin >> secondNumber;

        cout << fixed << setprecision(2);

        switch (choice) {
            case 1:
                cout << "Result: " << firstNumber << " + "
                     << secondNumber << " = "
                     << add(firstNumber, secondNumber) << endl;
                break;

            case 2:
                cout << "Result: " << firstNumber << " - "
                     << secondNumber << " = "
                     << subtract(firstNumber, secondNumber) << endl;
                break;

            case 3:
                cout << "Result: " << firstNumber << " * "
                     << secondNumber << " = "
                     << multiply(firstNumber, secondNumber) << endl;
                break;

            case 4:
                if (secondNumber == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    cout << "Result: " << firstNumber << " / "
                         << secondNumber << " = "
                         << divide(firstNumber, secondNumber) << endl;
                }
                break;

            case 5:
                if (secondNumber == 0) {
                    cout << "Error: Cannot calculate modulus with zero."
                         << endl;
                } else {
                    int firstInt = static_cast<int>(firstNumber);
                    int secondInt = static_cast<int>(secondNumber);

                    cout << "Result: " << firstInt << " % "
                         << secondInt << " = "
                         << calculateModulus(firstInt, secondInt) << endl;
                }
                break;

            case 6:
                cout << "Result: " << firstNumber << " ^ "
                     << secondNumber << " = "
                     << exponent(firstNumber, secondNumber) << endl;
                break;
        }

    } while (choice != 7);

    return 0;
}