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

//Time complexity: O(N^2)
void removeDuplicates(forward_list<int>& linkedList)
{

    for(auto currentPointer = linkedList.begin(); currentPointer != linkedList.end(); currentPointer++)
    {
        auto runnerPointer = currentPointer;
        auto nextRunnerPointer = currentPointer;
        while(nextRunnerPointer != linkedList.end())
        {
            nextRunnerPointer = runnerPointer;
            nextRunnerPointer++;
            if(nextRunnerPointer != linkedList.end()) 
            {
                if((*nextRunnerPointer) == (*currentPointer)) linkedList.erase_after(runnerPointer);
                else runnerPointer++;
            }
        }
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

int main()
{
    
    forward_list<int> linkedList;
    int N;
    
    cout << "Write the number of elements to be added in the list: ";
    cin >> N;
    
    loadList(linkedList, N);
    removeDuplicates(linkedList);
    printList(linkedList);
    return 0;

}