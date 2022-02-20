#include <iostream>
#include <array>
#include <memory>
#include <list>
#include <vector>

using namespace std;

struct Node
{
    int value;
    array<shared_ptr<Node>, 2> children;
};

void addBST(shared_ptr<Node>& BST, int value)
{

    if(!BST)
    {
        BST = make_shared<Node>();
        BST->value = value;
    } else
    {
        if(value < BST->value) addBST(BST->children[0], value);
        else addBST(BST->children[1], value);
    }

}

void loadBST(shared_ptr<Node>& BST, int N)
{

    cout << "Write each value to be added in the BST: ";
    int value;
    for(int count = 0; count < N; count++)
    {
        cin >> value;
        addBST(BST, value);
    }

}

void weaveLists(list<int>& first, list<int>& second, vector<list<int>>& results, 
list<int>& prefix)
{

    if(first.empty() || second.empty())
    {
        list<int> result(prefix);
        result.insert(result.end(), first.begin(), first.end());
        result.insert(result.end(), second.begin(), second.end());
        results.push_back(result);
        return;
    }

    int headFirst = first.front();
    first.pop_front();
    prefix.emplace_back(headFirst);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    first.emplace_front(headFirst);

    int headSecond = second.front();
    second.pop_front();
    prefix.emplace_back(headSecond);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    second.emplace_front(headSecond);

}

vector<list<int>> allSequences(const shared_ptr<Node>& node)
{

    vector<list<int>> result;
    if(!node) 
    {
        result.push_back(list<int>());
        return result;
    }
    
    list<int> prefix;
    prefix.emplace_back(node->value);

    vector<list<int>> leftSeq = allSequences(node->children[0]);
    vector<list<int>> rightSeq = allSequences(node->children[1]);

    for(auto &left : leftSeq)
    {
        for(auto &right : rightSeq)
        {
            vector<list<int>> weaved;
            weaveLists(left, right, weaved, prefix);
            for(auto &weavedElem : weaved)
                result.push_back(weavedElem);
        }
    }
    return result;

}

int main()
{

    cout << "Write the number of elements: ";
    int N;
    cin >> N;

    shared_ptr<Node> binarySearchTree;
    loadBST(binarySearchTree, N);
    vector<list<int>> sequences = allSequences(binarySearchTree);
    for(auto& list : sequences)
    {
        for(auto& element : list)
            cout << element << " ";
        cout << endl;
    }
    return 0;
}