/*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping 
the adjacent elements if they are in wrong order. Code the Bubble sort with the 
following elements: 
64 
34 
25 
12 
22 
11 
90 */


#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    bubbleSort(a, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}



