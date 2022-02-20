#include <iostream>

using namespace std;

int pairwiseSwap(int N)
{
    int mask = -1431655766; //101010...10
    return (mask & (N << 1)) | (~mask & (N >> 1)); 
}

int main()
{

    cout << "Write an integer: ";
    int N;
    cin >> N;
    cout << pairwiseSwap(N) << endl;
    return 0;

}