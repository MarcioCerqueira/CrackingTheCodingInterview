#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void loadVector(vector<int>& A, int size)
{

    A.resize(size);
    cout << "Enter the elements: ";
    for(auto& element : A) cin >> element;

}

//Time complexity: O(log n)
int detectMagicIndex(const vector<int>& A, int begin, int end)
{

    if(begin > end) return -1;
    int middle = (begin + end)/2;
    if(A[middle] == middle) return middle;
    else if(A[middle] > middle) return detectMagicIndex(A, begin, middle - 1);
    else return detectMagicIndex(A, middle + 1, end);

}

int main()
{

    vector<int> A;
    int N;
    cout << "Enter the size of the vector: ";
    cin >> N;

    loadVector(A, N);
    sort(A.begin(), A.end());

    int magicIndex = detectMagicIndex(A, 0, A.size() - 1);
    if(magicIndex == -1) cout << "No magic index has been found." << endl;
    else cout << "Magic index: " << magicIndex << endl;

    return 0; 
}