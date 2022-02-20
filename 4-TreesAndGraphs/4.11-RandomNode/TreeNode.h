#include <iostream>
#include <memory>
#include <random>

using namespace std;

class TreeNode : public enable_shared_from_this<TreeNode>
{

public:
    TreeNode(int d);
    shared_ptr<TreeNode> getRandomNode();
    void insertInOrder(int d);
    shared_ptr<TreeNode> find(int d);
    int getSize();
    int getData();

    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;

private:
    int data;
    int size;
};