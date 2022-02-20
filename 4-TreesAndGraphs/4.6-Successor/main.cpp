#include <iostream>
#include <memory>
#include <array>
#include <vector>
using namespace std;

struct Node
{
    int value;
    shared_ptr<Node> parent;
    array<shared_ptr<Node>, 2> children;
};

void loadSortedArray(vector<int>& sortedArray, int N)
{

    cout << "Write each value (sorted in an increasing order): ";
    for(int count = 0; count < N; count++)
    {
        int value;
        cin >> value;
        sortedArray.push_back(value);
    }

}

shared_ptr<Node> getLeftMostNode(const shared_ptr<Node>& root)
{

    shared_ptr<Node> node = root;
    while(node->children[0]) node = node->children[0];
    return node;

}

//Time complexity: O(N)
shared_ptr<Node> buildBinarySearchTree(const vector<int>& sortedArray, int a, int b)
{

    if(a == b) return nullptr;
    shared_ptr<Node> node = make_shared<Node>();
    int mid = (a + b)/2;
    node->value = sortedArray[mid];
    node->children[0] = buildBinarySearchTree(sortedArray, a, mid);
    node->children[1] = buildBinarySearchTree(sortedArray, mid + 1, b);
    if(node->children[0]) node->children[0]->parent = node;
    if(node->children[1]) node->children[1]->parent = node;
    return node;

}

void printBinarySearchTree(const shared_ptr<Node>& node)
{

    if(!node) return;
    cout << node->value << " ";
    
    if(node->children[1])
    {
        shared_ptr<Node> nextNode = node->children[1];
        while(nextNode->children[0]) nextNode = nextNode->children[0];
        printBinarySearchTree(nextNode);
    } else 
    {
        shared_ptr<Node> q = node;
        shared_ptr<Node> x = q->parent;
        while(x && x->children[0] != q)
        {
            q = x;
            x = x->parent;
        }
        printBinarySearchTree(x);
    }
    
}

int main()
{

    int N;
    cout << "Write the number of elements: ";
    cin >> N;

    vector<int> sortedArray;
    loadSortedArray(sortedArray, N);

    shared_ptr<Node> root = buildBinarySearchTree(sortedArray, 0, N);
    shared_ptr<Node> leftMostNode = getLeftMostNode(root);

    cout << "Resulting binary search tree: ";
    printBinarySearchTree(leftMostNode);
    return 0;

}