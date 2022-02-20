#include <iostream>
#include <vector>

using namespace std;

void loadSequence(vector<int>& sequence)
{

    int size;
    cout << "Enter the size of the sequence: ";
    cin >> size;
    sequence.resize(size);

    cout << "Enter the elements of the sequence: ";
    for(auto& element : sequence) cin >> element;

}

int getMaxSum(const vector<int>& sequence)
{

    int maxSum = 0;
    int sum = 0;
    for(int i = 0; i < sequence.size(); i++)
    {
        sum += sequence[i];
        if(maxSum < sum) maxSum = sum;
        else if(sum < 0) sum = 0;
    }
    return maxSum;
}

int main()
{

    vector<int> sequence;
    loadSequence(sequence);
    cout << getMaxSum(sequence) << endl;
    return 0;

}