#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void loadVector(vector<int>& integerVector, const string& order)
{

    int size;
    cout << "What is the size of the " << order << " vector?" << endl;
    cin >> size;
    integerVector.resize(size);

    cout << "Enter the " << size << " elements of this vector" << endl;
    for(auto& element : integerVector) cin >> element;
    
}

int estimateSmallestDifference(const vector<int>& firstVector, const vector<int>& secondVector)
{

    int a = 0;
    int b = 0;
    int smallestDifference = INT_MAX;
    while(a < firstVector.size() && b < secondVector.size())
    {

        int currentDifference = abs(firstVector[a] - secondVector[b]);
        if(currentDifference < smallestDifference) smallestDifference = currentDifference;
              
        if(firstVector[a] < secondVector[b]) a++;
        else b++;

    }

    return smallestDifference;
    
}

//Year, I know that an array of integers can be sorted using radix sort with O(n) time complexity.
//In this case, I have used the built-in functionality of C++ just to ... use it. ;-)
int main()
{

    vector<int> firstVector;
    vector<int> secondVector;

    loadVector(firstVector, "first");
    loadVector(secondVector, "second");

    sort(firstVector.begin(), firstVector.end());
    sort(secondVector.begin(), secondVector.end());
    
    int smallestDifference = estimateSmallestDifference(firstVector, secondVector);
    cout << "The smallest non-negative difference is: " << smallestDifference << endl; 
    return 0;

}