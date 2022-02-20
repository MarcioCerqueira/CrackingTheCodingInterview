#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void loadVector(vector<int>& a)
{

    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    a.resize(size);

    cout << "Enter the elements of the vector: ";
    for(auto& element : a) cin >> element;

}

int computeSum(const vector<int>& a)
{

    int sum = 0;
    for(const auto& element : a) sum += element;
    return sum;

}

void findPair(const vector<int>& a, const vector<int>& b)
{

    int sumDifference = computeSum(a) - computeSum(b);

    unordered_map<int, bool> sortedDifference;
    for(const auto& element : b) 
    {
        sortedDifference[sumDifference + 2 * element] = true;
    }

    for(const auto& element : a) 
    {
        if(sortedDifference[2 * element])
        {
            cout << "A valid pair (" << element << "," << -(sumDifference - 2 * element)/2 << ") has been found." << endl;
            return;
        }
    }

    cout << "No valid pair has been found" << endl;

}

int main()
{

    vector<int> a, b;
    loadVector(a);
    loadVector(b);
    findPair(a, b);
    return 0;

}