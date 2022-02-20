#include <iostream>
#include <memory>

using namespace std;

struct Node
{
    shared_ptr<Node> next;
    int value;
};

void loadList(shared_ptr<Node>& head, int N)
{

    cout << "Write the list elements: ";
    cin >> head->value;
    for(int count = 1; count < N; count++)
    {
        shared_ptr<Node> traversalPointer = head;
        shared_ptr<Node> node = make_shared<Node>();
        cin >> node->value;
        while(traversalPointer->next) traversalPointer = traversalPointer->next;
        traversalPointer->next = node;
    }

}

void createCircularList(shared_ptr<Node>& head, int corruptedIndex)
{

    shared_ptr<Node> corruptedNode = make_shared<Node>();
    shared_ptr<Node> traversalPointer = head;
    int count = 0;

    if(corruptedIndex == 0) 
    {
        corruptedNode = head;
    } 
    else 
    {
        while(traversalPointer->next) 
        {
            traversalPointer = traversalPointer->next;
            count++;
            if(count == corruptedIndex) corruptedNode = traversalPointer;
        }    
    } 
    traversalPointer->next = corruptedNode;

}

shared_ptr<Node> detectCorruptedNode(const shared_ptr<Node>& head)
{

    shared_ptr<Node> slowPointer = make_shared<Node>();
    shared_ptr<Node> fastPointer = make_shared<Node>();
    
    slowPointer = head;
    fastPointer = head;

    while(fastPointer->next && fastPointer->next->next)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if(slowPointer == fastPointer) break;
    }
    
    if(!fastPointer) return make_shared<Node>();
    
    slowPointer = head;
    while(slowPointer != fastPointer)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
    }
    return fastPointer;
    
}

//Time complexity: O(N)
int main()
{

    shared_ptr<Node> head = make_shared<Node>();
    cout << "Write the number of elements in the list: ";
    int N;
    cin >> N;
    loadList(head, N);

    cout << "Write the index of the corrupted node (beginning of the circular list): ";
    int corruptedIndex;
    cin >> corruptedIndex;
    if(corruptedIndex >= N) return 0;
    createCircularList(head, corruptedIndex);

    //Detect corrupted node
    shared_ptr<Node> corruptedNode = detectCorruptedNode(head);
    if(corruptedNode) cout << "Loop detected at value: " << corruptedNode->value << endl;
    else cout << "No loop has been detected" << endl;
    return 0;

}