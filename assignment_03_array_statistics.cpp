#include <iostream>
using namespace std;

int calculateSum(int numbers[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    return sum;
}

double calculateAverage(int numbers[], int n) {
    int sum = calculateSum(numbers, n);

    return static_cast<double>(sum) / n;
}

int findMaximum(int numbers[], int n) {
    int maximum = numbers[0];

    for (int i = 1; i < n; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    return maximum;
}

int findMinimum(int numbers[], int n) {
    int minimum = numbers[0];

    for (int i = 1; i < n; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }

    return minimum;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Number of values must be positive." << endl;
        return 0;
    }

    int numbers[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers, n) << endl;
    cout << "Average: " << calculateAverage(numbers, n) << endl;
    cout << "Maximum: " << findMaximum(numbers, n) << endl;
    cout << "Minimum: " << findMinimum(numbers, n) << endl;

    return 0;
}