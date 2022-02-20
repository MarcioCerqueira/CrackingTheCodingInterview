#include <iostream>

using namespace std;

//Time complexity: O(1)
int insert(int N, int M, int i, int j)
{
    M <<= i;
    N = N & (~((1 << (j + 1)) - 1) | ((1 << (i + 1)) - 1));
    return N | M;
}

int main()
{

    int N, M, i, j;
    cout << "Write two integer numbers: ";
    cin >> N >> M;
    cout << "Write two bit positions: ";
    cin >> i >> j;
    
    cout << "Result: " << insert(N, M, i, j) << endl;
    return 0;

}