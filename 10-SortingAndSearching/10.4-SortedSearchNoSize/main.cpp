#include <iostream>
#include <vector>

using namespace std;

//Let us pretend that our vector is a "Listy" structure
void loadListy(vector<int>& v)
{

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    v.resize(size);

    cout << "Enter the sorted elements: ";
    for(auto& elem : v) cin >> elem;

}

//Time complexity: O(log N)
int searchElement(const vector<int>& listy)
{

    int element;
    cout << "Enter the element to be searched: ";
    cin >> element;

    int position = 0;
    int begin = -1, end = -1;

    while(listy.size() > position) 
    {
        if(listy[position] == element) return position;
        else if(listy[position] < element) position = (position == 0) ? 1 : position * 2;
        else break;
    }

    begin = position/2;
    end = position;
    
    while(begin <= end)
    {
        int middle = (begin + end)/2;
        if(middle >= listy.size()) end = middle - 1;
        else if(listy[middle] == element) return middle;
        else if(listy[middle] > element) end = middle - 1;
        else begin = middle + 1;
    }

    return -1;

}

int main()
{

    vector<int> listy;
    loadListy(listy);
    int index = searchElement(listy);
    if(index == -1) cout << "Element not found." << endl;
    else cout << "Element found at position: " << index << endl;
    return 0;

}