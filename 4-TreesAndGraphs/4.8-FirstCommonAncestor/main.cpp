#include <iostream>
#include <memory>
#include <array>

using namespace std;

struct Node
{
    int value;
    array<shared_ptr<Node>, 2> children;
};

//Time complexity: O(N)
shared_ptr<Node> getCommonAncestorNode(const shared_ptr<Node>& traversalNode, const shared_ptr<Node>& a, 
const shared_ptr<Node>& b)
{

    if(!traversalNode) return nullptr;

    shared_ptr<Node> leftAncestor = nullptr;
    shared_ptr<Node> rightAncestor = nullptr;
    if(traversalNode->children[0] == a) leftAncestor = traversalNode;
    if(traversalNode->children[0] == b) leftAncestor = traversalNode;
    if(traversalNode->children[1] == a) rightAncestor = traversalNode; 
    if(traversalNode->children[1] == b) rightAncestor = traversalNode;

    if(!leftAncestor) leftAncestor = getCommonAncestorNode(traversalNode->children[0], a, b);
    if(!rightAncestor) rightAncestor = getCommonAncestorNode(traversalNode->children[1], a, b);

    if(leftAncestor && rightAncestor) return traversalNode;
    else if(leftAncestor && !rightAncestor) return leftAncestor;
    else if(!leftAncestor && rightAncestor) return rightAncestor;
    else return nullptr;

}

//This code assumes that the nodes are located in the tree. 
//We could check if that is a valid condition prior to the search.
int main()
{

    shared_ptr<Node> binaryTree = make_shared<Node>();
    shared_ptr<Node> n10 = make_shared<Node>();
    shared_ptr<Node> n30 = make_shared<Node>();
    shared_ptr<Node> n5 = make_shared<Node>();
    shared_ptr<Node> n25 = make_shared<Node>();
    shared_ptr<Node> n18 = make_shared<Node>();
    shared_ptr<Node> n22 = make_shared<Node>();
    shared_ptr<Node> n33 = make_shared<Node>();
    shared_ptr<Node> n27 = make_shared<Node>();
    shared_ptr<Node> n44 = make_shared<Node>();
    
    n10->value = 10;
    n30->value = 30;
    n5->value = 5;
    n25->value = 25;
    n18->value = 18;
    n22->value = 22;
    n33->value = 33;
    n27->value = 27;
    n44->value = 44;

    binaryTree->value = 20;
    binaryTree->children[0] = n10;
    binaryTree->children[1] = n30;
    n10->children[0] = n5;
    n10->children[1] = n25;
    n30->children[1] = n18;
    n18->children[0] = n22;
    n18->children[1] = n33;
    n5->children[0] = n27;
    n27->children[0] = n44;
    
    cout << "The first common ancestor of nodes " << n10->value << " and " << n30->value << " is " << getCommonAncestorNode(binaryTree, n10, n30)->value << endl;
    cout << "The first common ancestor of nodes " << n5->value << " and " << n18->value << " is " << getCommonAncestorNode(binaryTree, n5, n18)->value << endl;
    cout << "The first common ancestor of nodes " << n27->value << " and " << n25->value << " is " << getCommonAncestorNode(binaryTree, n27, n25)->value << endl;
    cout << "The first common ancestor of nodes " << n44->value << " and " << n33->value << " is " << getCommonAncestorNode(binaryTree, n44, n33)->value << endl;
    cout << "The first common ancestor of nodes " << n30->value << " and " << n18->value << " is " << getCommonAncestorNode(binaryTree, n30, n18)->value << endl;
    cout << "The first common ancestor of nodes " << n5->value << " and " << n25->value << " is " << getCommonAncestorNode(binaryTree, n5, n25)->value << endl;
    cout << "The first common ancestor of nodes " << n22->value << " and " << n33->value << " is " << getCommonAncestorNode(binaryTree, n22, n33)->value << endl;
    cout << "The first common ancestor of nodes " << n27->value << " and " << n44->value << " is " << getCommonAncestorNode(binaryTree, n27, n44)->value << endl;
    return 0;

}