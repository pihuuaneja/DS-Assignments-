/*4) Implement the logic to 
c. Find the Transpose of a Matrix */

#include <iostream>
using namespace std;

void transpose() {
    int rows, cols;
    cout << "Enter rows and columns of matrix: ";
    cin >> rows >> cols;

    int A[rows][cols], T[cols][rows];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }

    cout << "\nTranspose of the Matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    transpose();
    return 0;
}

