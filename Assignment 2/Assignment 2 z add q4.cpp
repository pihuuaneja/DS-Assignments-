/*4) Sort an array of 0s, 1s and 2s - Dutch National Flag Problem 
Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e., 
put all 0s first, then all 1s and all 2s in last.*/

#include <iostream>   
using namespace std;

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { 
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int arr[] = {0, 2, 1, 2, 0, 1, 1, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
