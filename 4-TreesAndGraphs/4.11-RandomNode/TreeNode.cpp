#include "TreeNode.h"

TreeNode::TreeNode(int d)
{

    this->data = d;
    this->size = 1;

}

shared_ptr<TreeNode> TreeNode::getRandomNode()
{

    int leftSize = (left) ? left->getSize() : 0;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> distribution(0, size - 1);
    
    int index = distribution(rng);
    if(index < leftSize) return left->getRandomNode();
    else if(index == leftSize) return shared_from_this();
    else return right->getRandomNode();

}

void TreeNode::insertInOrder(int d)
{

    if(d <= data) 
    {
        if(!left) left = make_shared<TreeNode>(d);
        else left->insertInOrder(d);
    } else 
    {
        if(!right) right = make_shared<TreeNode>(d);
        else right->insertInOrder(d);
    }
    ++size;

}

shared_ptr<TreeNode> TreeNode::find(int d)
{

    if(d == data) return shared_from_this();
    else if(d <= data) return (left) ? left->find(d) : nullptr;
    else if(d > data) return (right) ? right->find(d) : nullptr;
    else return nullptr;
    
}

int TreeNode::getSize()
{
    return size;
}

int TreeNode::getData()
{
    return data;
}