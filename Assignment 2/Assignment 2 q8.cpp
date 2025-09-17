 //Write a program to count the total number of distinct elements in an array of length n.
 
 #include <iostream>
using namespace std;

void elementcount(int arr[], int n)
{
    if (n == 0)
    {
        cout << "distinct elements are: 0" << endl;
        return;
    }

    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            count++;
        }
    }

    cout << "distinct elements are: " << count << endl;
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    elementcount(arr, n);
}
