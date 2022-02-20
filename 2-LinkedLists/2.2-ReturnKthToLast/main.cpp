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

//Time complexity: O(N)
int findKthToLastElement(const forward_list<int>& linkedList, int K)
{

    auto currentPointer = linkedList.begin();
    auto runnerPointer = currentPointer;
    
    for(auto step = 0; step < K && runnerPointer != linkedList.end(); step++) 
        runnerPointer++;
    
    while(runnerPointer != linkedList.end())
    {
        runnerPointer++;
        currentPointer++;
    }

    return (*currentPointer);

}

int main()
{

    forward_list<int> linkedList;
    
    cout << "Write the number of elements to be added in the list: ";
    int N;
    cin >> N;
    
    loadList(linkedList, N);

    cout << "Write the Kth to last element that should be found: ";
    int K;
    cin >> K;
    if(K > N) return 0;

    cout << "Element found: " << findKthToLastElement(linkedList, K) << endl;
    return 0;

}