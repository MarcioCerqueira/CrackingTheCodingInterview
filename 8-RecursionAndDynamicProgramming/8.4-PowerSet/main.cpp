#include <iostream>
#include <string>
#include <vector>

using namespace std;

//We are not printing the empty subset intentionally
//Time complexity: O(2^n)
void printSubsets(const vector<int>& set, string prefix = "", int begin = 0)
{

    for(int index = begin; index < set.size(); index++)
    {
        string subset = prefix + to_string(set[index]);
        cout << subset << endl;
        printSubsets(set, subset + ",", index + 1);
    }

}

int main()
{

    vector<int> set;
    int size;
    cout << "Enter the number of elements in the set: ";
    cin >> size;

    set.resize(size);
    cout << "Enter the set elements: ";
    for(auto& element : set) cin >> element;
    
    printSubsets(set);
    return 0;

}