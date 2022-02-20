#include <iostream>
#include <vector>

using namespace std;

void loadSequence(vector<int>& sequence)
{

    int size;
    cout << "Enter the size of the sequence: ";
    cin >> size;
    sequence.resize(size);

    cout << "Enter the sequence elements: ";
    for(auto& element : sequence) cin >> element;

}

//Time complexity: O(N)
void generatePeakAndValleySequence(vector<int>& sequence)
{

    int left, middle, right;
    for(int index = 0; index < sequence.size(); index++)
    {

        if(index - 1 < 0) left = INT_MIN;
        else left = sequence[index - 1];

        if(index + 1 >= sequence.size() && sequence.size() % 2 == 0) right = INT_MAX;
        else if(index + 1 >= sequence.size() && sequence.size() % 2 != 0) right = INT_MIN;
        else right = sequence[index + 1];

        middle = sequence[index];
        if(index % 2 == 0 && max(middle, max(left, right)) != middle) swap(sequence[index], sequence[index + 1]);
        else if(index % 2 != 0 && min(middle, min(left, right)) != middle) swap(sequence[index], sequence[index + 1]);
       
    }

}

void printSequence(const vector<int>& sequence)
{

    cout << "Output sequence: ";
    for(auto& element : sequence) cout << element << " ";

}

int main()
{

    vector<int> sequence;
    loadSequence(sequence);
    generatePeakAndValleySequence(sequence);
    printSequence(sequence);
    return 0;

}