#include <iostream>
#include <memory>
#include <unordered_map>
#include <array>

using namespace std;

struct Node
{
    int value;
    array<shared_ptr<Node>, 2> children;
};

int countPathsWithSum(const shared_ptr<Node>& node, int desiredSum, int runningSum, unordered_map<int, int>& hashMap)
{

    if(!node) return 0;

    runningSum += node->value;
    int sum = runningSum - desiredSum;
    int totalPaths = hashMap[sum];
    if(runningSum == desiredSum) totalPaths++;

    hashMap[runningSum]++;
    totalPaths += countPathsWithSum(node->children[0], desiredSum, runningSum, hashMap);
    totalPaths += countPathsWithSum(node->children[1], desiredSum, runningSum, hashMap);
    hashMap[runningSum]--;
    return totalPaths;
    
}

int countPathsWithSum(const shared_ptr<Node>& node, int desiredSum)
{
    unordered_map<int, int> hashMap;
    return countPathsWithSum(node, desiredSum, 0, hashMap);
}

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
    shared_ptr<Node> n3 = make_shared<Node>();
    
    n10->value = 10;
    n30->value = 30;
    n5->value = 5;
    n25->value = 25;
    n18->value = 18;
    n22->value = 22;
    n33->value = 33;
    n27->value = 27;
    n3->value = 3;

    binaryTree->value = 20;
    binaryTree->children[0] = n10;
    binaryTree->children[1] = n30;
    n10->children[0] = n5;
    n10->children[1] = n25;
    n30->children[1] = n18;
    n18->children[0] = n22;
    n18->children[1] = n33;
    n5->children[0] = n27;
    n27->children[0] = n3;

    cout << "There are " << countPathsWithSum(binaryTree, 30) << " paths that sum to 30" << endl;
    return 0;

}