#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Box
{
    int width;
    int height;
    int depth;
};

void loadBoxes(vector<Box>& boxes, int numberOfBoxes)
{

    boxes.resize(numberOfBoxes);
    cout << "Enter the boxes description: (width, height, depth) ";
    for(auto& box : boxes) cin >> box.width >> box.height >> box.depth;

}

int getHeight(const stack<Box>& boxStack)
{
    stack<Box> tempStack(boxStack);
    int height = 0;
    while(!tempStack.empty())
    {
        height += tempStack.top().height;
        tempStack.pop();
    }
    return height;
}

void tryToAddBox(Box box, stack<Box>& stack)
{

    bool boxToBeAddedIsSmaller;
    if(!stack.empty())
    {
        Box topBox = stack.top();
        boxToBeAddedIsSmaller = topBox.width > box.width && topBox.height > box.height && topBox.depth > box.depth;
    }
    if(stack.empty() || boxToBeAddedIsSmaller) stack.push(box);

}


int estimateTallestStack(const vector<Box>& boxes, stack<Box>& boxStack)
{

    if(boxes.empty()) return getHeight(boxStack);

    int tallestStackHeight = 0;
    for(int boxIndex = 0; boxIndex < boxes.size(); boxIndex++) 
    {
        vector<Box> tempBoxes(boxes);
        stack<Box> tempStack(boxStack);
        tryToAddBox(tempBoxes[boxIndex], tempStack); 
        tempBoxes.erase(tempBoxes.begin() + boxIndex);
        tallestStackHeight = max(tallestStackHeight, estimateTallestStack(tempBoxes, tempStack));
    }
    return tallestStackHeight;

}

int main()
{

    vector<Box> boxes;
    int numberOfBoxes;
    cout << "Enter the number of boxes: ";
    cin >> numberOfBoxes;

    loadBoxes(boxes, numberOfBoxes);

    stack<Box> boxStack;
    cout << "The size of the tallest stack is: " << estimateTallestStack(boxes, boxStack) << endl;
    return 0;

}