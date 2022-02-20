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

//Time complexity: O(N1 + N2)
bool findIntersection(const forward_list<int>& firstList, const forward_list<int>& secondList, int N1, int N2, 
int& result)
{
  
    auto firstPointer = firstList.begin();
    auto secondPointer = secondList.begin();
    
    for(int count = 0; count < (N1 - N2); count++) firstPointer++;
    for(int count = 0; count < (N2 - N1); count++) secondPointer++;
    
    while(firstPointer != firstList.end() && secondPointer != secondList.end())
    {
        if((*firstPointer) == (*secondPointer)) 
        {
            result = *firstPointer;
            return true;
        }
        firstPointer++;
        secondPointer++;
    }
    return false;

}

int main()
{
    
    forward_list<int> firstList;
    forward_list<int> secondList;
    int N1, N2;

    cout << "Write the number of elements in the first list: ";
    cin >> N1;
    loadList(firstList, N1);

    cout << "Write the number of elements in the second list: ";
    cin >> N2;
    loadList(secondList, N2);

    int result;
    if(findIntersection(firstList, secondList, N1, N2, result)) cout << "Intersection at: " << result << endl;
    else cout << "No intersection has been found" << endl;
    return 0;
    
}