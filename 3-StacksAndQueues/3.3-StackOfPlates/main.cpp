#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void loadStack(vector<stack<int>>& setOfStacks, int N, int threshold)
{

    cout << "Write the stack elements: ";
    int value;
    int stackIndex = 0;
    for(int count = 0; count < N; count++)
    {
        cin >> value;
        if(setOfStacks[stackIndex].size() >= threshold) 
        {
            setOfStacks.push_back(stack<int>());
            stackIndex++;
        }
        setOfStacks[stackIndex].push(value);
    }

}

void printStack(vector<stack<int>>& setOfStacks)
{

    cout << "Stack: " << endl;
    int stackIndex = setOfStacks.size() - 1;
    while(stackIndex >= 0)
    {
        cout << setOfStacks[stackIndex].top() << " " << stackIndex << endl;
        setOfStacks[stackIndex].pop();
        if(setOfStacks[stackIndex].empty()) stackIndex--;
    }

}

//Time complexity: O(N)
int main()
{

    vector<stack<int>> setOfStacks(1);
    int threshold;

    cout << "Write the number of elements to be added in the stack: ";
    int N;
    cin >> N;

    cout << "Write the stack threshold: ";
    cin >> threshold;
    
    loadStack(setOfStacks, N, threshold);
    printStack(setOfStacks);
    return 0;

}