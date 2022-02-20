#include <iostream>
#include <array>

using namespace std;

void loadGame(array<array<char, 3>, 3>& matrix)
{
    cout << "Please fill in the tic-tac-toe matrix with 'X' and 'O' characters" << endl;
    for(int row = 0; row < 3; row++)
        for(int col = 0; col < 3; col++)
            cin >> matrix[row][col];
}

void checkWinner(array<array<char, 3>, 3>& matrix)
{
    if(matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2]) cout << "Winner: " << matrix[0][0] << endl;
    else if(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]) cout << "Winner: " << matrix[0][0] << endl;
    else if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) cout << "Winner: " << matrix[0][0] << endl;
    else if(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1]) cout << "Winner: " << matrix[0][1] << endl;
    else if(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]) cout << "Winner: " << matrix[0][2] << endl;
    else if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) cout << "Winner: " << matrix[0][2] << endl;
    else if(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2]) cout << "Winner: " << matrix[1][0] << endl;
    else if(matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2]) cout << "Winner: " << matrix[2][0] << endl;
    else cout << "No winner" << endl;
}

int main()
{

    array<array<char, 3>, 3> matrix;
    loadGame(matrix);
    checkWinner(matrix);
    return 0;

}