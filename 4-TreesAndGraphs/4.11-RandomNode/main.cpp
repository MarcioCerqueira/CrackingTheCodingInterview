#include <iostream>
#include "TreeNode.h"

using namespace std;

void loadBST(shared_ptr<TreeNode>& BST, int N)
{

    cout << "Write each value to be added in the BST: ";
    int value;
    for(int count = 0; count < N; count++)
    {
        cin >> value;
        if(count == 0) BST = make_shared<TreeNode>(value);
        else BST->insertInOrder(value);
    }

}

void printRandomNodes(const shared_ptr<TreeNode>& BST)
{

    cout << "Printing some random node values..." << endl;
    for(int count = 0; count < 3; count++)
        cout << BST->getRandomNode()->getData() << endl;

}

int main()
{

    cout << "Write the number of elements: ";
    int N;
    cin >> N;

    shared_ptr<TreeNode> binarySearchTree;
    loadBST(binarySearchTree, N);
    printRandomNodes(binarySearchTree);
    return 0;
}