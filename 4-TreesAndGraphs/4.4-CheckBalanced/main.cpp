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
int getHeight(const shared_ptr<Node>& node, int depth, bool& isBalanced)
{

    if(!node) return depth;
    int leftHeight = getHeight(node->children[0], depth + 1, isBalanced);
    int rightHeight = getHeight(node->children[1], depth + 1, isBalanced);
    if(abs(leftHeight - rightHeight) > 1) isBalanced = false;
    return max(leftHeight, rightHeight);

}

int main()
{

    shared_ptr<Node> unbalancedTree = make_shared<Node>();
    shared_ptr<Node> balancedTree = make_shared<Node>();
    
    unbalancedTree->value = 1;
    unbalancedTree->children[1] = make_shared<Node>();
    unbalancedTree->children[1]->value = 2;
    unbalancedTree->children[1]->children[1] = make_shared<Node>();
    unbalancedTree->children[1]->children[1]->value = 3;

    balancedTree->value = 2;
    balancedTree->children[0] = make_shared<Node>();
    balancedTree->children[0]->value = 1;
    balancedTree->children[1] = make_shared<Node>();
    balancedTree->children[1]->value = 3;

    bool isBalanced = true;
    getHeight(unbalancedTree, 0, isBalanced);
    if(isBalanced) cout << "First tree is balanced" << endl;
    else cout << "First tree is not balanced" << endl;

    isBalanced = true;
    getHeight(balancedTree, 0, isBalanced);
    if(isBalanced) cout << "Second tree is balanced" << endl;
    else cout << "Second tree is not balanced" << endl;
    return 0;

}