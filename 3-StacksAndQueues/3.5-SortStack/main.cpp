#include <iostream>
#include <stack>

using namespace std;

void loadStack(stack<int>& stack, int N)
{

    cout << "Write the elements to be added in the stack: ";
    int value;
    for(int count = 0; count < N; count++)
    {
        cin >> value;
        stack.push(value);
    }

}

void swapTops(stack<int>& s1, stack<int>& s2)
{

    int a = s1.top();
    int b = s2.top();
    s1.pop();
    s2.pop();
    s1.push(b);
    s2.push(a);

}

//Time complexity: O(N^2)
void sortStack(stack<int>& baseStack)
{
    
    stack<int> tempStack;
    while(true)
    {

        tempStack.push(baseStack.top());
        baseStack.pop();

        //Temp stack has all the elements sorted in a reverse order
        if(baseStack.empty())
        {
            while(!tempStack.empty())
            {
                baseStack.push(tempStack.top());
                tempStack.pop();
            }
            break;
        }

        if(baseStack.top() < tempStack.top()) swapTops(baseStack, tempStack);

        bool inOrder = false;
        while(!inOrder)
        {
            baseStack.push(tempStack.top());
            tempStack.pop();
            if(tempStack.empty() || baseStack.top() >= tempStack.top())
            {
                tempStack.push(baseStack.top());
                baseStack.pop();
                inOrder = true;
            } 
            else
            {
                swapTops(baseStack, tempStack);
            } 
        }

    }

}

void printStack(stack<int>& stack)
{

    cout << "Stack: " << endl;
    while(!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }

}

int main()
{

    stack<int> stack;
    
    cout << "Write the number of elements to be added in the stack: ";
    int N;
    cin >> N;

    loadStack(stack, N);
    sortStack(stack);
    printStack(stack);
    return 0;

}