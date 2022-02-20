#include <iostream>
#include <memory>
#include <array>
#include <vector>
#include <forward_list>
#include <cmath>
using namespace std;

struct Node
{
    int value;
    int depth;
    array<shared_ptr<Node>, 2> children;
};

vector<int> loadElements(int N)
{

    vector<int> elements;
    int value;

    cout << "Write each value: ";
    for(int count = 0; count < N; count++)
    {
        cin >> value;
        elements.push_back(value);
    }

    return elements;

}

//Time complexity: O(N)
shared_ptr<Node> buildBinaryTree(const vector<int>& elements, int a, int b, int depth)
{

    if(a == b) return nullptr;
    shared_ptr<Node> node = make_shared<Node>();
    int mid = (a + b)/2;
    node->value = elements[mid];
    node->depth = depth;
    node->children[0] = buildBinaryTree(elements, a, mid, depth + 1);
    node->children[1] = buildBinaryTree(elements, mid + 1, b, depth + 1);
    return node;

}

//Time complexity: O(N)
void createLinkedLists(const shared_ptr<Node>& node, vector<forward_list<shared_ptr<Node>>>& linkedLists)
{

    if(!node) return;
    linkedLists[node->depth].push_front(node);
    createLinkedLists(node->children[1], linkedLists);
    createLinkedLists(node->children[0], linkedLists);

}

void printLinkedLists(const vector<forward_list<shared_ptr<Node>>>& linkedLists)
{


    cout << "Final linked lists: " << endl;
    int depth = 0;
    for(auto &list : linkedLists)
    {
        cout << "Depth " << depth << ": ";
        int count = 0;
        for(auto &item : list) 
        {
            if(count == 0) cout << item->value;
            else cout << " -> " << item->value;
            count++;
        }
        cout << endl;
        depth++;
    }

}

int main()
{

    int N;
    cout << "Write the number of elements: ";
    cin >> N;

    vector<int> elements = loadElements(N);
    shared_ptr<Node> root = buildBinaryTree(elements, 0, N, 0);

    vector<forward_list<shared_ptr<Node>>> linkedLists(log2<int>(N) + 1);
    createLinkedLists(root, linkedLists);
    printLinkedLists(linkedLists);
    return 0;

}