#include <iostream>
#include <stack>
#include <array>

using namespace std;

void moveSingleDisk(array<stack<int>, 3>& towers, int base, int destination)
{
    if(towers[destination].empty() || towers[destination].top() > towers[base].top())
    {
        towers[destination].push(towers[base].top());
        towers[base].pop();
    }
}

//Time complexity: O(m^n)
void solveHanoiProblem(array<stack<int>, 3>& towers, int numberOfDisks, int baseIndex, int bufferIndex, int destinationIndex)
{

    if(numberOfDisks == 1) 
    {
        moveSingleDisk(towers, baseIndex, destinationIndex);
        return;
    }

    solveHanoiProblem(towers, numberOfDisks - 1, baseIndex, destinationIndex, bufferIndex);
    moveSingleDisk(towers, baseIndex, destinationIndex);
    solveHanoiProblem(towers, numberOfDisks - 1, bufferIndex, baseIndex, destinationIndex);

}

void printTower(array<stack<int>, 3>& towers, int towerIndex)
{
    cout << "Tower " << towerIndex << endl;
    while(!towers[towerIndex].empty())
    {
        cout << towers[towerIndex].top() << endl;
        towers[towerIndex].pop();
    }
}

int main()
{

    array<stack<int>, 3> towers;
    int numberOfDisks;

    cout << "Enter the number of disks: ";
    cin >> numberOfDisks;

    for(int disk = numberOfDisks; disk >= 1; disk--) towers[0].push(disk);
    solveHanoiProblem(towers, numberOfDisks, 0, 1, 2);
    for(int towerIndex = 0; towerIndex < 3; towerIndex++) printTower(towers, towerIndex);

    return 0;

}