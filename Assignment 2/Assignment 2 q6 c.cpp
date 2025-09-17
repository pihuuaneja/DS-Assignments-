//(c) Multiplication of two matrices.

#include <iostream>
using namespace std;

void inputMatrix(int mat[][3], int &noofnonzero)
{
    int rows, columns;
    cout << "Enter rows, columns, non-zero elements: ";
    cin >> rows >> columns >> noofnonzero;

    mat[0][0] = rows;
    mat[0][1] = columns;
    mat[0][2] = noofnonzero;

    cout << "Enter row, column, value for each non-zero element:\n";
    for (int i = 1; i <= noofnonzero; i++)
    {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

void transpose(int mat2[][3], int trans[][3])
{
    trans[0][0] = mat2[0][1];
    trans[0][1] = mat2[0][0];
    trans[0][2] = mat2[0][2];

    int k = 1;
    for (int col = 0; col < mat2[0][1]; col++)
    {
        for (int i = 1; i <= mat2[0][2]; i++)
        {
            if (mat2[i][1] == col)
            {
                trans[k][0] = mat2[i][1];
                trans[k][1] = mat2[i][0];
                trans[k][2] = mat2[i][2];
                k++;
            }
        }
    }
}

void multiSparse(int mat1[][3], int trans[][3], int result[][3])
{
    int k = 1;
    result[0][0] = mat1[0][0];
    result[0][1] = trans[0][0];
    result[0][2] = 0;

    for (int i = 1; i <= mat1[0][2]; i++)
    {
        for (int j = 1; j <= trans[0][2]; j++)
        {
            if (mat1[i][1] == trans[j][1])
            {

                int found = -1;
                for (int x = 1; x < k; x++)
                {
                    if (result[x][0] == mat1[i][0] && result[x][1] == trans[j][0])
                    {
                        found = x;
                        break;
                    }
                }
                if (found != -1)
                {
                    result[found][2] += mat1[i][2] * trans[j][2];
                }
                else
                {
                    result[k][0] = mat1[i][0];
                    result[k][1] = trans[j][0];
                    result[k][2] = mat1[i][2] * trans[j][2];
                    k++;
                }
            }
        }
    }
    result[0][2] = k - 1;
}

void printSparse(int mat[][3])
{
    int n = mat[0][2];
    cout << "Row\tCol\tVal\n";
    for (int i = 0; i <= n; i++)
    {
        cout << mat[i][0] << "\t" << mat[i][1] << "\t" << mat[i][2] << "\n";
    }
}

int main()
{
    int mat1[100][3];
    int mat2[100][3];
    int n1 = 5;
    int n2 = 5;

    inputMatrix(mat1, n1);
    inputMatrix(mat2, n2);

    int trans[100][3];
    int result[200][3];

    cout << "Matrix 1:\n";
    printSparse(mat1);
    cout << "\nMatrix 2:\n";
    printSparse(mat2);

    transpose(mat2, trans);
    cout << "\nTranspose of Matrix 2:\n";
    printSparse(trans);

    multiSparse(mat1, trans, result);
    cout << "\nResult Matrix:\n";
    printSparse(result);

    return 0;
}
