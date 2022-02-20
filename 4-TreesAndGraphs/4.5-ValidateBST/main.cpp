#include <iostream>
#include <memory>
#include <array>
#include <cmath>

using namespace std;

struct Node
{
    int value;
    array<shared_ptr<Node>, 2> children;
};

//Time complexity: O(N)
bool isBinarySearchTree(const shared_ptr<Node>& node, int minValue = -1, int maxValue = -1)
{

    if(!node) return true;
    if(node->children[0] && node->value < node->children[0]->value) return false;
    if(node->children[0] && minValue != -1 && minValue > node->children[0]->value) return false;
    if(node->children[0] && maxValue != -1 && maxValue < node->children[0]->value) return false;
    if(node->children[1] && node->value > node->children[1]->value) return false;
    if(node->children[1] && minValue != -1 && minValue > node->children[1]->value) return false;
    if(node->children[1] && maxValue != -1 && maxValue < node->children[1]->value) return false;
    return (isBinarySearchTree(node->children[0], minValue, node->value)
            && isBinarySearchTree(node->children[1], node->value, maxValue));

}

int main()
{

    shared_ptr<Node> binaryTree = make_shared<Node>();
    shared_ptr<Node> binarySearchTree = make_shared<Node>();
    
    binaryTree->value = 20;
    binaryTree->children[0] = make_shared<Node>();
    binaryTree->children[0]->value = 10;
    binaryTree->children[1] = make_shared<Node>();
    binaryTree->children[1]->value = 30;
    binaryTree->children[0]->children[0] = make_shared<Node>();
    binaryTree->children[0]->children[0]->value = 5;
    binaryTree->children[0]->children[1] = make_shared<Node>();
    binaryTree->children[0]->children[1]->value = 25;

    binarySearchTree->value = 2;
    binarySearchTree->children[0] = make_shared<Node>();
    binarySearchTree->children[0]->value = 0;
    binarySearchTree->children[1] = make_shared<Node>();
    binarySearchTree->children[1]->value = 3;
    binarySearchTree->children[0]->children[0] = make_shared<Node>();
    binarySearchTree->children[0]->children[0]->value = -1;
    binarySearchTree->children[0]->children[1] = make_shared<Node>();
    binarySearchTree->children[0]->children[1]->value = 1;

    if(isBinarySearchTree(binaryTree)) cout << "First tree is a binary search tree" << endl;
    else cout << "First tree is not a binary search tree" << endl;

    if(isBinarySearchTree(binarySearchTree)) cout << "Second tree is a binary search tree" << endl;
    else cout << "Second tree is not a binary search tree" << endl;
    return 0;

}