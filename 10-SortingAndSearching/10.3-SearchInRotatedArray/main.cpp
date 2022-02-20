#include <iostream>
#include <vector>

using namespace std;

void loadRotatedVector(vector<int>& v)
{

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    v.resize(size);

    cout << "Enter the rotated array: ";
    for(auto& elem : v) cin >> elem;

}

//Time complexity: O(log N)
//Yes, yes, that solution only works for distinct elements inside the array :-(
int searchElement(const vector<int>& v)
{

    int element;
    cout << "Enter the element to be searched: ";
    cin >> element;

    int begin = 0;
    int end = v.size() - 1;
    
    while(begin <= end)
    {
        int middle = (begin + end)/2;
        if(v[middle] == element) {
            return middle;
        } else if(v[begin] < v[middle]) {
            if(element >= v[begin] && element < v[middle]) end = middle - 1;
            else begin = middle + 1;
        } else if(v[middle] < v[end]) {
            if(element > v[middle] && element <= v[end]) begin = middle + 1;
            else end = middle - 1;
        } else if(begin == end) {
            return -1;
        }
    }

    return -1;

}

int main()
{

    vector<int> v;
    loadRotatedVector(v);
    int index = searchElement(v);
    if(index == -1) cout << "Element not found." << endl;
    else cout << "Element found at position: " << index << endl;
    return 0;

}