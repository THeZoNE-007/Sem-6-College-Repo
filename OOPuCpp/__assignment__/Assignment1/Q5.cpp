#include <iostream>

using namespace std;

void readMatrix(int **matrix, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int **matrix, int m, int n)
{
    cout << "Matrix:\n";
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    int **matrix = new int *[m];
    for (int i = 0; i < m; ++i)
    {
        matrix[i] = new int[n];
    }

    readMatrix(matrix, m, n);
    displayMatrix(matrix, m, n);

    for (int i = 0; i < m; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
