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

void findSubSequenceToBeSorted(const vector<int>& sequence)
{

    int sortedLeft = 0;
    int sortedRight = sequence.size() - 1;

    for(int position = 1; position < sequence.size(); position++) 
    {
        if(sequence[position] >= sequence[sortedLeft]) sortedLeft++;
        else break;
    }

    for(int position = sortedLeft + 1; position < sequence.size(); position++) 
        while(sortedLeft >= 0 && sequence[position] < sequence[sortedLeft])
            sortedLeft--;

    for(int position = sequence.size() - 2; position >= 0; position--) 
    {
        if(sequence[position] <= sequence[sortedRight]) sortedRight--;
        else break;
    }

    for(int position = sortedRight - 1; position >= 0; position--) 
        while(sortedRight < sequence.size() && sequence[position] > sequence[sortedRight])
            sortedRight++;

    if(sortedLeft == sequence.size() - 1 || sortedRight == 0) cout << "Array is sorted" << endl;
    else cout << "(" << sortedLeft + 1 << "," << sortedRight - 1 << ")" << endl;

}

int main()
{

    vector<int> sequence;
    loadSequence(sequence);
    findSubSequenceToBeSorted(sequence);
    return 0;

}