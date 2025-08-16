//Given an array of n-1 distinct integers in the range of 1 to n, find the missing numbe in it in a Sorted Array  (a) Linear time 
#include <iostream>
using namespace std;

int missL(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (a[i] != i + 1) return i + 1;
    return n;
}

int main() {
    int a[] = {1, 2, 3, 5, 6};
    int n = 6;
    cout << missL(a, n);
}



