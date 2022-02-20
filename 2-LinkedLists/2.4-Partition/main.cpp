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

void partitionList(forward_list<int>& linkedList, int X)
{

    auto lowerThanXPointer = linkedList.begin();
    auto greaterThanOrEqualToXPointer = linkedList.begin();

    while(lowerThanXPointer != linkedList.end() && greaterThanOrEqualToXPointer != linkedList.end())
    {
        if((*lowerThanXPointer) < X) 
        {
            lowerThanXPointer++;
            greaterThanOrEqualToXPointer = lowerThanXPointer;
            continue;
        }
        if((*greaterThanOrEqualToXPointer) >= X)
        {
            greaterThanOrEqualToXPointer++;
            continue;
        }
        swap(*lowerThanXPointer, *greaterThanOrEqualToXPointer);
        greaterThanOrEqualToXPointer = lowerThanXPointer;
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
int main()
{
    
    forward_list<int> linkedList;
    
    cout << "Write the number of elements to be added in the list: ";
    int N;
    cin >> N;
    
    loadList(linkedList, N);

    cout << "Write the partition value: ";
    int X;
    cin >> X;
    partitionList(linkedList, X);

    printList(linkedList);
    return 0;

}