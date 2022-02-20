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
bool isPalindrome(const forward_list<int>& linkedList)
{

    forward_list<int> reverseLinkedList = linkedList;
    reverseLinkedList.reverse();

    auto linkedListPointer = linkedList.begin();
    auto reverseLinkedListPointer = reverseLinkedList.begin();

    while(linkedListPointer != linkedList.end() && reverseLinkedListPointer != reverseLinkedList.end())
    {
        if((*linkedListPointer) != (*reverseLinkedListPointer)) return false;
        linkedListPointer++;
        reverseLinkedListPointer++;
    }

    return true;

}

int main()
{
    
    forward_list<int> linkedList;
    
    cout << "Write the number of elements to be added in the list: ";
    int N;
    cin >> N;
    loadList(linkedList, N);

    if(isPalindrome(linkedList)) cout << "Is palindrome? True" << endl;
    else cout << "Is palindrome? False" << endl;
    return 0;

}