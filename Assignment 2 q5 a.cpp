//(a) Diagonal Matrix. 

#include <iostream>
using namespace std;

int n = 0;
int arr[100];

void matrix()
{
    cout << "Enter size of matrix: ";
    cin >> n;
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }
}

void display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                cout << arr[i] << " ";
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
