#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& V)
{
    cout << "Sorted vector: " << endl;
    for(const auto& elem : V) cout << elem << " ";
}

void loadSortedVector(vector<int>& V, int size, char identifier)
{

    cout << "Enter the " << identifier << " vector elements in ascending order: " << endl;
    for(int index = 0; index < size; index++) cin >> V[index];
        
}

//Time complexity: O(N)
void sortedMerge(vector<int>& A, const vector<int>& B)
{

    int ALastEmptyIndex = A.size() - 1;
    int ALastNonEmptyIndex = A.size() - B.size() - 1;
    int BLastNonEmptyIndex = B.size() - 1;

    while(ALastNonEmptyIndex >= 0 && BLastNonEmptyIndex >= 0)
    {
        if(A[ALastNonEmptyIndex] > B[BLastNonEmptyIndex]) 
        {
            A[ALastEmptyIndex] = A[ALastNonEmptyIndex];
            ALastNonEmptyIndex--;
        } 
        else
        {
            A[ALastEmptyIndex] = B[BLastNonEmptyIndex];
            BLastNonEmptyIndex--;
        }
        ALastEmptyIndex--;
    }
    
    if(ALastNonEmptyIndex < 0)
        for(int Index = 0; Index <= BLastNonEmptyIndex; Index++)
            A[Index] = B[Index];

}

int main()
{

    vector<int> A, B;
    int size;
    
    cout << "Enter the size of A: " << endl;
    cin >> size;
    A.resize(size);

    cout << "Enter the size of B: " << endl;
    cin >> size;
    A.resize(A.size() + size);
    B.resize(size);

    loadSortedVector(A, A.size() - size, 'A');
    loadSortedVector(B, B.size(), 'B');
    sortedMerge(A, B);
    printVector(A);
    return 0;

}