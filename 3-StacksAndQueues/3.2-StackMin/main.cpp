#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int value;
    int minimum;
};

void loadStack(stack<Node>& stack, int N)
{

    cout << "Write the elements to be added in the stack: ";
    for(int count = 0; count < N; count++)
    {
        Node node;
        cin >> node.value;
        if(stack.empty()) node.minimum = node.value;
        else node.minimum = (stack.top().minimum > node.value) ? node.value : stack.top().minimum;
        stack.push(node);
    }

}

void printStack(stack<Node>& stack)
{

    cout << "Stack: " << endl;
    while(!stack.empty())
    {
        Node node = stack.top();
        cout << "Value: " << node.value << ", Min: " << node.minimum << endl;
        stack.pop();
    }

}

//Time complexity: O(1) for push, pop, and min.
int main()
{

    cout << "Write the number of elements to be added in the stack: ";
    int N;
    cin >> N;

    stack<Node> stack;
    loadStack(stack, N);
    printStack(stack);
    return 0;

}