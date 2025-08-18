// Tri-diagonal Matrix. 

#include <iostream>
using namespace std;

int n = 0;
int arr[100];

void matrix()
{
    cout << "Enter size of matrix: ";
    cin >> n;
    int i;
    for (i = 0; i < 3 * n - 2; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }
}

void display()
{
    int i, j;
    int k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i - j == 1)
                cout << arr[k++] << " ";
            else if (i == j)
                cout << arr[k++] << " ";
            else if (j - i == 1)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

int main()
{
    matrix();
    display();
    return 0;
}
