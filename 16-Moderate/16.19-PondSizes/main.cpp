#include <iostream>
#include <vector>
using namespace std;

void loadLand(vector<vector<int>>& land)
{

    int width;
    cout << "Enter the width of the land: ";
    cin >> width;
    
    cout << "Enter the values: ";
    land.resize(width);
    for(auto& col : land) 
    {
        col.resize(width);
        for(auto& element : col)
            cin >> element;
    }

}

int estimatePondSize(vector<vector<int>>& land, int col, int row, int width, int size)
{

    if(col < 0 || row < 0 || col >= width || row >= width) return size;
    if(land[col][row] != 0) return size;
    
    land[col][row] = -1;
    size++;
    int a = estimatePondSize(land, col + 1, row, width, 0);
    int b = estimatePondSize(land, col - 1, row, width, 0);
    int c = estimatePondSize(land, col, row + 1, width, 0);
    int d = estimatePondSize(land, col, row - 1, width, 0);
    int e = estimatePondSize(land, col + 1, row + 1, width, 0);
    int f = estimatePondSize(land, col - 1, row - 1, width, 0);
    int g = estimatePondSize(land, col - 1, row + 1, width, 0);
    int h = estimatePondSize(land, col + 1, row - 1, width, 0);
    return a + b + c + d + e + f + g + h + size;

}

void computePondSizes(vector<vector<int>>& land)
{

    cout << "Pond sizes: " << endl;
    for(int col = 0; col < land.size(); col++)
    {
        for(int row = 0; row < land[col].size(); row++)
        {
            if(land[col][row] == 0) 
            {
                cout << estimatePondSize(land, col, row, land.size(), 0) << endl;
            }
        }
    }

}

int main()
{

    vector<vector<int>> land;
    loadLand(land);
    computePondSizes(land);
    return 0;

}