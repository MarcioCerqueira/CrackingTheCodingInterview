#include <iostream>
#include <vector>
using namespace std;

//Time complexity: O(N^2)
void rotate(vector<vector<int>>& matrix)
{

    for(int row = 0; row < matrix.size() / 2; row++)
    {
        int first = row;
        int last = matrix.size() - 1 - row;
        for(int col = first; col < last; col++)
        {
            int offset = col - first;
            int top = matrix[first][col];
            matrix[first][col] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last - offset];
            matrix[last][last-offset] = matrix[col][last];
            matrix[col][last] = top;
        }
    }

}

int main()
{

    int N;
    vector<vector<int>> matrix;

    cout << "Write the matrix order: ";
    cin >> N;
    matrix.resize(N);
    for(auto& row : matrix) 
        row.resize(N);
    
    cout << "Write the matrix elements: " << endl;
    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++)
            cin >> matrix[row][col];

    rotate(matrix);

    cout << "Rotated matrix: " << endl;
    for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < N - 1; col++)
            cout << matrix[row][col] << " ";
        cout << matrix[row][N - 1] << endl;
    }
    return 0;

}