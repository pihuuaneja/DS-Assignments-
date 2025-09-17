//(b) Addition of two matrices. 

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

void printMatrix(int mat[][3])
{
    int count = mat[0][2];
    for (int i = 0; i <= count; i++)
    {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << "\n";
    }
}

void addSparse(int mat1[][3], int mat2[][3], int result[][3])
{
    int m1 = mat1[0][2];
    int m2 = mat2[0][2];

    int i = 1, j = 1, k = 1;

    result[0][0] = mat1[0][0];
    result[0][1] = mat1[0][1];

    while (i <= m1 && j <= m2)
    {
        if (mat1[i][0] < mat2[j][0] ||
            (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1]))
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
        }
        else if (mat2[j][0] < mat1[i][0] ||
                 (mat2[j][0] == mat1[i][0] && mat2[j][1] < mat1[i][1]))
        {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++;
        }
        else
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] + mat2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= m1)
    {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++;
        k++;
    }
    while (j <= m2)
    {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;
}

int main()
{
    int mat1[100][3], mat2[100][3], sum[100][3];
    int n1, n2;

    cout << "First matrix:\n";
    inputMatrix(mat1, n1);

    cout << "Second matrix:\n";
    inputMatrix(mat2, n2);

    addSparse(mat1, mat2, sum);

    cout << "\nSum matrix:\n";
    printMatrix(sum);

    return 0;
}