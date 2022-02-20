#include <iostream>
#include <vector>
#include <array>

using namespace std;

void push(vector<int>& stacks, array<int, 3>& lasts, int value, int stackIndex)
{

    if(stackIndex < 0 || stackIndex > 2) return;
    if(lasts[stackIndex] == (stackIndex + 1) * stacks.size()/3) return;
    stacks[lasts[stackIndex]] = value;
    lasts[stackIndex]++;

}

int pop(vector<int>& stacks, array<int, 3>& lasts, int stackIndex)
{

    lasts[stackIndex]--;
    return stacks[lasts[stackIndex]];

}

void loadStacks(vector<int>& stacks, array<int, 3>& lasts)
{

    cout << "Write the number of elements to insert in the stacks: ";
    int N;
    cin >> N;

    int value, stackIndex;
    for(int count = 0; count < N; count++)
    {

        cout << "Write the element to be inserted: ";
        cin >> value;
        cout << "Write the stack index (0, 1, or 2): ";
        cin >> stackIndex;
        push(stacks, lasts, value, stackIndex);

    }

}

void printStacks(vector<int>& stacks, array<int, 3>& lasts)
{

    for(int stackIndex = 0; stackIndex < 3; stackIndex++)
    {
        cout << "Stack: " << stackIndex << endl;
        while(lasts[stackIndex] != stackIndex * stacks.size() / 3) 
            cout << pop(stacks, lasts, stackIndex) << " ";
        cout << endl;
    }

}

//Time complexity: O(N)
int main()
{

    cout << "Write the array size: ";
    int N;
    cin >> N;

    vector<int> stacks;
    stacks.resize(N);
    
    array<int, 3> lasts;
    lasts[0] = 0; //[0, N/3[
    lasts[1] = N/3; //[N/3, 2N/3[
    lasts[2] = 2*N/3;//[2N/3, N[

    loadStacks(stacks, lasts);
    printStacks(stacks, lasts);
    return 0;

}