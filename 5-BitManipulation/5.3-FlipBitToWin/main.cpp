#include <iostream>
#include <cmath>

using namespace std;

bool getBit(int N, int i)
{
    return N & (1 << i);
}

//Time complexity: O(b)
int longestSequence(int N)
{

    int previousSequenceSize = 0;
    int currentSequenceSize = 0;
    int longestSequenceSize = 0;
    int numberOfBits = log2(N) + 1;
    for(int bit = 0; bit < numberOfBits; bit++)
    {

        if(getBit(N, bit)) 
        {
            currentSequenceSize++;
        }
        else 
        {
            longestSequenceSize = max<int>(longestSequenceSize, currentSequenceSize + previousSequenceSize + 1);
            previousSequenceSize = currentSequenceSize;
            currentSequenceSize = 0;
        }

    }

    return longestSequenceSize;
}

int main()
{

    cout << "Write an integer number: " << endl;
    int N;
    cin >> N;

    if(N > 0) cout << longestSequence(N) << endl;
    return 0;

}