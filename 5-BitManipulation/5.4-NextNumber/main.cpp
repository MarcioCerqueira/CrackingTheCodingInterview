#include <iostream>

using namespace std;

int setBit(int N, int i)
{
    return N | (1 << i);
}

int clearBit(int N, int i)
{
    return N & ~(1 << i);
}

bool getBit(int N, int i)
{
    return N & (1 << i);
}

//Time complexity: O(b)
int nextLargest(int N)
{

    bool setNextBit = false;
    int countOneBits = 0;
    int rightMostValidZeroBit = 0;
    for(int bit = 0; bit < 32; bit++)
    {
        if(getBit(N, bit))
        {
            countOneBits++;
            setNextBit = true;
        } else if(!getBit(N, bit) && setNextBit)
        {
            N = setBit(N, bit);
            rightMostValidZeroBit = bit;
            break;
        }
    }
    N &= ~((1 << rightMostValidZeroBit) - 1);
    N |= ((1 << (countOneBits - 1)) - 1);
    return N;

}

//Time complexity: O(b)
int nextSmallest(int N)
{

    int countOneBits = 0;
    int countZeroBits = 0;
    int rightMostValidOneBit = 0;
    bool breakIsAllowed = false;
    for(int bit = 0; bit < 32; bit++)
    {
        if(getBit(N, bit))
        {
            if(breakIsAllowed) break;
            countOneBits++;
        }
        if(!getBit(N, bit))
        {
            countZeroBits++;
            breakIsAllowed = true;
        }
    }
    N = clearBit(N, countOneBits + countZeroBits);
    N &= ~((1 << countOneBits + countZeroBits + 1) - 1);
    N |= (((1 << (countOneBits + 1)) - 1) << (countZeroBits - 1));
    return N;

}

int main()
{

    cout << "Write a positive number: ";
    int N;
    cin >> N;
    if(N <= 0) return 0;

    cout << "The next smallest number with the same number of 1 bits is: " << nextSmallest(N) << endl;
    cout << "The next largest number with the same number of 1 bits is: " << nextLargest(N) << endl;
    return 0;
}