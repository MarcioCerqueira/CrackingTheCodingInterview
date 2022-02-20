#include <iostream>
#include <vector>

using namespace std;

//Average time complexity: O(M * N)
void zero(vector<vector<int>>& matrix)
{

    vector<bool> zeroRows;
    vector<bool> zeroCols;
    
    zeroRows.resize(matrix.size());
    zeroCols.resize(matrix[0].size());
    
    for(int row = 0; row < zeroRows.size(); row++) {
        for(int col = 0; col < zeroCols.size(); col++) {
            if(matrix[row][col] == 0) {
                zeroRows[row] = true;
                zeroCols[col] = true;
            }
        }
    }
    
    for(int col = 0; col < zeroCols.size(); col++)
        if(zeroCols[col]) 
            for(int row = 0; row < zeroRows.size(); row++)
                matrix[row][col] = 0;
    
    for(int row = 0; row < zeroRows.size(); row++) 
        if(zeroRows[row]) 
            for(int col = 0; col < zeroCols.size(); col++) 
                matrix[row][col] = 0;

}

int main()
{

    int M, N;
    vector<vector<int>> matrix;
    
    cout << "Write the matrix dimensions: " << endl;
    cin >> M >> N;
    matrix.resize(M);  
    
    for(auto& row : matrix) 
        row.resize(N);
    
    cout << "Write the matrix elements" << endl;
    for(int row = 0; row < M; row++)
        for(int col = 0; col < N; col++) 
            cin >> matrix[row][col];
            
    zero(matrix);

    cout << "Updated matrix:" << endl;
    for(int row = 0; row < M; row++)
    {
        for(int col = 0; col < N - 1; col++)
            cout << matrix[row][col] << " ";
        cout << matrix[row][N - 1] << endl;
    }

    return 0;

}