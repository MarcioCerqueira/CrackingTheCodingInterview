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

void findAllPairsWithSum(const vector<int>& elements, int sum)
{

    unordered_map<int, bool> pairsWithSum;
    for(const auto& element : elements) pairsWithSum[sum - element] = true;
    
    for(const auto& element : elements) 
        if(pairsWithSum[element])
            cout << "Pair (" << element << "," << sum - element << ") has been found." << endl;
    
}

int main()
{

    vector<int> elements;
    loadVector(elements);

    int sum;
    cout << "Enter the desired sum: ";
    cin >> sum;

    findAllPairsWithSum(elements, sum);
    return 0;

}