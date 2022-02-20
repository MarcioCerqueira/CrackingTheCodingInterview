#include <iostream>
#include <memory>
using namespace std;

struct Node
{
    int value;
    shared_ptr<Node> leftChild;
    shared_ptr<Node> rightChild;
};

void track(shared_ptr<Node>& node, int value)
{

    if(!node) 
    {
        node = make_shared<Node>();
        node->value = value;
    }
    else
    {
        if(value > node->value) track(node->rightChild, value);
        else track(node->leftChild, value);
    }

}

//Time complexity: Worst case O(N)
int getRankOfNumber(shared_ptr<Node>& node, int value, int rank = 0, bool numberHasBeenFound = false)
{

    if(!node) 
    {
        return rank;
    }
    else if(node->value > value) 
    {
        return getRankOfNumber(node->leftChild, value, rank, numberHasBeenFound);
    } 
    else
    {
        if(node->value == value && !numberHasBeenFound) numberHasBeenFound = true;
        else rank++;
        rank = getRankOfNumber(node->leftChild, value, rank, numberHasBeenFound);
        rank = getRankOfNumber(node->rightChild, value, rank, numberHasBeenFound);
        return rank;
    }

}

void loadStream(shared_ptr<Node>& root)
{

    bool readNumber = true;
    int value;
    do
    {
        cout << "Enter a integer value: ";
        cin >> value;
        track(root, value);
        cout << "Do you want to continue? (0 - No, 1 - Yes)" << endl;
        cin >> readNumber;
    } while (readNumber);   

}

void getRankOfNumbers(shared_ptr<Node>& root)
{

    bool readNumber = true;
    int value;
    do
    {
        cout << "Enter a integer value: ";
        cin >> value;
        cout << "Rank: " << getRankOfNumber(root, value) << endl;
        cout << "Do you want to continue? (0 - No, 1 - Yes)" << endl;
        cin >> readNumber;
    } while (readNumber);   

}

int main()
{

    shared_ptr<Node> root;
    loadStream(root);
    getRankOfNumbers(root);
    return 0;

}