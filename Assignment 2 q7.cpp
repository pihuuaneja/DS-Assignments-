//Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an  inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number of inversions in an array

#include <iostream>
using namespace std;

void inversion(int arr[], int n)
{
    int i = 0;
    int j = i + 1;
    int count = 0;

    while (i < j && j < n && i < n)
    {
        if (arr[i] > arr[j])
        {
            count++;
            cout << arr[i] << "," << arr[j] << endl;
            i++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    cout << "the number of inversion are :" << count << endl;
}
int main()
{
    int arr[] = {5, 9, 3, 2, 1};

    inversion(arr, 5);
}
