#include <iostream>
#include <forward_list>

using namespace std;

void loadList(forward_list<int>& linkedList, int N)
{

    cout << "Write the list elements: ";
    int value;
    auto tail = linkedList.before_begin();
    for(int item = 0; item < N; item++)
    {
        cin >> value;
        tail = linkedList.emplace_after(tail, value);
    }

}

void printList(const forward_list<int>& linkedList)
{

    cout << "Final linked list: ";
    int count = 0;
    for(auto &item : linkedList) 
    {
        if(count == 0) cout << item;
        else cout << " -> " << item;
        count++;
    }
    cout << endl;

}

//Time complexity: O(N)
void removeNodeFromList(forward_list<int>& linkedList, int K)
{
    
    int count = 0;
    auto currentPointer = linkedList.begin();
    while(currentPointer != linkedList.end())
    {
        if(count == K)
        {
            auto nextPointer = currentPointer;
            nextPointer++;
            (*currentPointer) = (*nextPointer);
            linkedList.erase_after(currentPointer);
            break;
        }
        currentPointer++;
        count++;
    }

}

int main()
{
    
    forward_list<int> linkedList;
    
    cout << "Write the number of elements to be added in the list: ";
    int N;
    cin >> N;
    
    loadList(linkedList, N);

    cout << "Write the element index that should be removed: ";
    int K;
    cin >> K;
    if(K == 0 || K == N - 1) return 0;
    removeNodeFromList(linkedList, K);
    
    printList(linkedList);    
    return 0;

}