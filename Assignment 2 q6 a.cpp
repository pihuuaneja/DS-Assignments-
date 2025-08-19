//(a) Transpose of a matrix. 


#include <iostream>
using namespace std;

void transpose(int mat[][3], int trans[][3])
{

    trans[0][0] = mat[0][1];
    trans[0][1] = mat[0][0];
    trans[0][2] = mat[0][2];

    int k = 1;
    for (int i = 0; i < mat[0][1]; i++)
    {
        for (int j = 1; j <= mat[0][2]; j++)
        {
            if (mat[j][1] == i)
            {
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}

int main()
{
    int rows, columns, noofnonzero;
    cout << "Enter no. of rows, columns and no. of non-zero elements: ";
    cin >> rows >> columns >> noofnonzero;

    int mat[100][3];
    int trans[100][3];

    mat[0][0] = rows;
    mat[0][1] = columns;
    mat[0][2] = noofnonzero;

    cout << "Enter row, column, value for each non-zero element:";
    for (int i = 1; i <= noofnonzero; i++)
    {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    cout << "Original :";
    for (int i = 0; i <= noofnonzero; i++)
    {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << "\n";
    }

    transpose(mat, trans);

    cout << "Transposed :";
    for (int i = 0; i <= noofnonzero; i++)
    {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << "\n";
    }

    return 0;
}