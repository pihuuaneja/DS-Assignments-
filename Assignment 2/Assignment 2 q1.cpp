// Implement the Binary search algorithm regarded as a fast search algorithm with run-time complexity of ?(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int binSearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid; 
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}

int main() {
    int n, key;
    cout << "Enter size: ";
    cin >> n;
    int a[n];

    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter value to search: ";
    cin >> key;

    int pos = binSearch(a, n, key);

    if (pos != -1)
        cout << "Found at position " << pos + 1;
    else
        cout << "Not found";

    return 0;
}


