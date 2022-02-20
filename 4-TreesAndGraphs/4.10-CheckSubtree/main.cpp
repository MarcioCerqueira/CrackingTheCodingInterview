#include <iostream>
#include <memory>
#include <array>

using namespace std;

struct Node
{
    int value;
    array<shared_ptr<Node>, 2> children;
};

//Time complexity: O(NM), being N the size of T1 and M the size of T2 
bool checkSubtree(const shared_ptr<Node>& T1, const shared_ptr<Node>& T2)
{

    if(T1 == T2)
    {
        
        if(!T1 && !T2) return true;
        
        bool leftResult = false;
        bool rightResult = false;
        leftResult = checkSubtree(T1->children[0], T2->children[0]);
        rightResult = checkSubtree(T1->children[1], T2->children[1]);
        return leftResult && rightResult;

    } 
    else
    {

        if(T1->children[0]) if(checkSubtree(T1->children[0], T2)) return true;
        if(T1->children[1]) if(checkSubtree(T1->children[1], T2)) return true;
        return false;
    
    }

}

int main()
{

    shared_ptr<Node> T1 = make_shared<Node>();
    shared_ptr<Node> T2 = make_shared<Node>();
    shared_ptr<Node> T3 = make_shared<Node>();
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

    T1->value = 20;
    T1->children[0] = n10;
    T1->children[1] = n30;
    n10->children[0] = n5;
    n10->children[1] = n25;
    n30->children[1] = n18;
    n18->children[0] = n22;
    n18->children[1] = n33;
    n5->children[0] = n27;
    n27->children[0] = n44;

    T2 = n5;
    T3->value = 100;
    T3->children[0] = make_shared<Node>();
    T3->children[0]->value = 20;
    T3->children[1] = make_shared<Node>();
    T3->children[1]->value = 40;
    
    if(checkSubtree(T1, T2)) cout << "Tree with root node " << T2->value << " is subtree of tree with root node " << T1->value << endl;
    else cout << "Tree with root node " << T2->value << " is not subtree of tree with root node " << T1->value << endl;
    
    if(checkSubtree(T1, T3)) cout << "Tree with root node " << T3->value << " is subtree of tree with root node " << T1->value << endl;
    else cout << "Tree with root node " << T3->value << " is not subtree of tree with root node " << T1->value << endl;
    
    return 0;

}