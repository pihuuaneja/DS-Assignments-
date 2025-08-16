// Given an array of n-1 distinct integers in the range of 1 to n, find the missing number  in it in a Sorted Array(b) Using binary search. 

#include <iostream>
using namespace std;

int missB(int a[], int n) {
    int l = 0, h = n - 2;
    while (l <= h) {
        int m = (l + h) / 2;
        if (a[m] == m + 1) l = m + 1;
        else h = m - 1;
    }
    return l + 1;
}

int main() {
    int a[] = {1, 2, 3, 5, 6};
    int n = 6;
    cout << missB(a, n);
}

