#include <iostream>
#include <memory>
#include <array>
#include <vector>
using namespace std;

struct Node
{
    int value;
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

//Time complexity: O(N)
shared_ptr<Node> buildBinarySearchTree(const vector<int>& sortedArray, int a, int b)
{

    if(a == b) return nullptr;
    shared_ptr<Node> node = make_shared<Node>();
    int mid = (a + b)/2;
    node->value = sortedArray[mid];
    node->children[0] = buildBinarySearchTree(sortedArray, a, mid);
    node->children[1] = buildBinarySearchTree(sortedArray, mid + 1, b);
    return node;

}

void printBinarySearchTree(const shared_ptr<Node>& node)
{

    if(!node) return;
    printBinarySearchTree(node->children[0]);
    cout << node->value << " ";
    printBinarySearchTree(node->children[1]);
    
}

int main()
{

    int N;
    cout << "Write the number of elements: ";
    cin >> N;

    vector<int> sortedArray;
    loadSortedArray(sortedArray, N);

    shared_ptr<Node> root = buildBinarySearchTree(sortedArray, 0, N);
    
    cout << "Resulting binary search tree: ";
    printBinarySearchTree(root);
    return 0;

}