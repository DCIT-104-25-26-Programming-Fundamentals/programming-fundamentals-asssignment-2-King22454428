#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose a matrix
void transposeMatrix(int matrix[10][10], int rows, int columns) {
    int transpose[10][10];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transpose, columns, rows);
}

// Part B: Add two matrices
void addMatrices(int matrixA[10][10], int matrixB[10][10],
                 int result[10][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Part C: Multiply two matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10],
                       int result[10][10], int rowsA, int columnsA,
                       int columnsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            result[i][j] = 0;

            for (int k = 0; k < columnsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrix[10][10];
    int matrixA[10][10];
    int matrixB[10][10];
    int result[10][10];

    int rows, columns;

    // =========================
    // PART A: TRANSPOSE
    // =========================

    cout << "PART A - Matrix Transpose" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    if (rows <= 0 || rows > MAX_SIZE ||
        columns <= 0 || columns > MAX_SIZE) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    cout << "\nEnter matrix elements:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, columns);

    transposeMatrix(matrix, rows, columns);


    // =========================
    // PART B: MATRIX ADDITION
    // =========================

    cout << "\n\nPART B - Matrix Addition" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    if (rows <= 0 || rows > MAX_SIZE ||
        columns <= 0 || columns > MAX_SIZE) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    cout << "\nEnter elements for Matrix A:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    cout << "\nEnter elements for Matrix B:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    addMatrices(matrixA, matrixB, result, rows, columns);

    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rows, columns);

    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, rows, columns);

    cout << "\nSum of Matrix A + Matrix B:" << endl;
    displayMatrix(result, rows, columns);


    // =========================
    // PART C: MATRIX MULTIPLICATION
    // =========================

    int rowsA, columnsA, rowsB, columnsB;

    cout << "\n\nPART C - Matrix Multiplication" << endl;

    cout << "Enter number of rows for Matrix A: ";
    cin >> rowsA;

    cout << "Enter number of columns for Matrix A: ";
    cin >> columnsA;

    cout << "Enter number of rows for Matrix B: ";
    cin >> rowsB;

    cout << "Enter number of columns for Matrix B: ";
    cin >> columnsB;

    if (rowsA <= 0 || rowsA > MAX_SIZE ||
        columnsA <= 0 || columnsA > MAX_SIZE ||
        rowsB <= 0 || rowsB > MAX_SIZE ||
        columnsB <= 0 || columnsB > MAX_SIZE) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    if (columnsA != rowsB) {
        cout << "Error: Number of columns in Matrix A must equal "
             << "number of rows in Matrix B." << endl;
        return 0;
    }

    cout << "\nEnter elements for Matrix A:" << endl;

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsA; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    cout << "\nEnter elements for Matrix B:" << endl;

    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < columnsB; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    multiplyMatrices(matrixA, matrixB, result,
                     rowsA, columnsA, columnsB);

    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rowsA, columnsA);

    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, rowsB, columnsB);

    cout << "\nProduct of Matrix A x Matrix B:" << endl;
    displayMatrix(result, rowsA, columnsB);

    return 0;
}