#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector<vector<bool>> grid;
vector<vector<bool>> failedPath;
stack<string> path;
int rows, cols;

void buildGrid()
{

    grid.resize(cols);
    failedPath.resize(cols);
    for(auto& element : grid) element.resize(rows);
    for(auto& element : failedPath) element.resize(rows);
    
    for(int x = 0; x < cols; x++) {
        for(int y = 0; y < rows; y++) {
            grid[x][y] = true;
            failedPath[x][y] = false;
        }
    }       

}

void loadOffLimits()
{

    bool markCellAsOffLimits = true;
    while(markCellAsOffLimits)
    {
        cout << "Do you want to mark a cell as off-limits? (0 - No; Other number - Yes)" << endl;
        cin >> markCellAsOffLimits;
        if(markCellAsOffLimits)
        {
            int offLimitCellX, offLimitCellY;
            cout << "Enter the x and y coordinates of the off-limit cell: " << endl;
            cin >> offLimitCellX >> offLimitCellY;
            if(offLimitCellX >= 0 && offLimitCellX < cols && offLimitCellY >= 0 && offLimitCellY < cols)
                grid[offLimitCellX][offLimitCellY] = false;
        }
    }

}

//Time complexity: O(N)
bool addPath(int x, int y)
{

    string cell = "(" + to_string(x) + ", " + to_string(y) + ")";
    path.push(cell);
    return true;

}

void printPath()
{

    cout << "Path traversed by the robot: " << endl;
    while(!path.empty())
    {
        cout << path.top() << endl;
        path.pop();
    }

}

//Time complexity: O(RC)
bool traverseGrid(int x, int y)
{

    if(x < 0 || x >= cols || y < 0 || y >= rows || !grid[x][y]) return false;
    if(failedPath[x][y]) return false;
    if(x == cols - 1 && y == rows - 1) return addPath(x, y);
    if(traverseGrid(x + 1, y)) return addPath(x, y); 
    if(traverseGrid(x, y + 1)) return addPath(x, y);

    failedPath[x][y] = true;
    return false;
    
}

int main()
{

    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of columns: " << endl;
    cin >> cols;

    buildGrid();
    loadOffLimits();
            
    if(traverseGrid(0, 0)) printPath();
    else cout << "Invalid path" << endl;

    return 0;

}