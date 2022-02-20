#include <iostream>
#include <array>
using namespace std;

void printChessboard(const array<array<int, 8>, 8>& chessboard)
{

    cout << endl;
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            cout << chessboard[row][col] << " ";
        }
        cout << endl;
    }

}

void clearChessboard(array<array<int, 8>, 8>& chessboard)
{
    for(int col = 0; col < 8; col++)
        for(int row = 0; row < 8; row++)
            chessboard[row][col] = -1;
}

void locateNextAvailablePosition(const array<array<int, 8>, 8>& chessboard, int startRow, int startCol, 
int& nextRow, int& nextCol)
{

    for(int row = startRow; row < 8; row++)
    {
        for(int col = startCol; col < 8; col++)
        {
            if(chessboard[row][col] == -1) 
            {
                nextRow = row;
                nextCol = col;
                return;
            }
        }
    }

}

void fillRow(array<array<int, 8>, 8>& chessboard, int row)
{
    for(int c = 0; c < 8; c++) if(chessboard[row][c] == -1) chessboard[row][c] = 0;
}

void fillCol(array<array<int, 8>, 8>& chessboard, int col)
{
    for(int r = 0; r < 8; r++) if(chessboard[r][col] == -1) chessboard[r][col] = 0;
}

void fillDiag(array<array<int, 8>, 8>& chessboard, int row, int col)
{

    int dRow = row;
    int dCol = col;
    while(dRow >= 0 && dCol >= 0) 
    {
        if(chessboard[dRow][dCol] == -1) chessboard[dRow][dCol] = 0;
        dRow--;
        dCol--;
    }

    dRow = row;
    dCol = col;
    while(dRow < 8 && dCol < 8) 
    {
        if(chessboard[dRow][dCol] == -1) chessboard[dRow][dCol] = 0;
        dRow++;
        dCol++;
    }

    dRow = row;
    dCol = col;
    while(dRow >= 0 && dCol < 8) 
    {
        if(chessboard[dRow][dCol] == -1) chessboard[dRow][dCol] = 0;
        dRow--;
        dCol++;
    }

    dRow = row;
    dCol = col;
    while(dRow < 8 && dCol >= 0) 
    {
        if(chessboard[dRow][dCol] == -1) chessboard[dRow][dCol] = 0;
        dRow++;
        dCol--;
    }

}

bool placeQueens(array<array<int, 8>, 8>& chessboard, int startRow = 0, int startCol = 0, int queen = 1)
{

    if(queen == 9)
    {
        printChessboard(chessboard);
        return true;
    }

    int nextRow = -1;
    int nextCol = -1;
    locateNextAvailablePosition(chessboard, startRow, startCol, nextRow, nextCol);
    if(nextRow == -1 || nextCol == -1) return false;

    chessboard[nextRow][nextCol] = queen;
    fillRow(chessboard, nextRow);
    fillCol(chessboard, nextCol);
    fillDiag(chessboard, nextRow, nextCol);
    for(int possibleCol = 0; possibleCol < 8; possibleCol++)
    {
        array<array<int, 8>, 8> chessboardClone(chessboard);
        if(placeQueens(chessboardClone, nextRow + 1, possibleCol, queen + 1)) return true;
    }
    return false;
    
}

int main()
{

    array<array<int, 8>, 8> chessboard;
    for(int col = 0; col < 8; col++) 
    {
        clearChessboard(chessboard);
        placeQueens(chessboard, 0, col);
    }

    return 0;

}