//Write a program to find sum of every row and every column in a two-dimensional array

#include <iostream>
using namespace std;

void read(int a[100][100], int r, int c) {
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
}

void rowSum(int a[100][100], int r, int c) {
    cout << "\nRow sums:\n";
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++)
            sum += a[i][j];
        cout << "Row " << i + 1 << ": " << sum << "\n";
    }
}

void colSum(int a[100][100], int r, int c) {
    cout << "\nCol sums:\n";
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += a[i][j];
        cout << "Col " << j + 1 << ": " << sum << "\n";
    }
}

int main() {
    int a[100][100], r, c;
    cout << "Rows: ";
    cin >> r;
    cout << "Cols: ";
    cin >> c;

    read(a, r, c);
    rowSum(a, r, c);
    colSum(a, r, c);

    return 0;
}

