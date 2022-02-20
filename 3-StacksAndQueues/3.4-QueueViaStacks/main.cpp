#include <iostream>
#include <stack>

using namespace std;

void loadQueue(stack<int>& firstStack, int N)
{

    stack<int> secondStack;
    int value;
    
    cout << "Write the elements to be added in the queue: ";
    for(int count = 0; count < N; count++)
    {
        cin >> value;
        secondStack.push(value);
    }

    while(!secondStack.empty())
    {
        firstStack.push(secondStack.top());
        secondStack.pop();
    }

}

void printQueue(stack<int>& stack)
{

    cout << "Queue: " << endl;
    while(!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }

}

//Time complexity: O(N)
int main()
{

    stack<int> stack;
    
    cout << "Write the number of elements to be added in the queue: ";
    int N;
    cin >> N;

    loadQueue(stack, N);
    printQueue(stack);
    return 0;
}