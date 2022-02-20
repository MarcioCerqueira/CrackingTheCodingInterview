#include <iostream>

using namespace std;

//Time complexity: O(K)
int main()
{

    int S, L;
    cout << "Enter the size of the shorter and longer planks: ";
    cin >> S >> L;

    int K;
    cout << "Enter the maximum number of planks of wood that must be used: "; 
    cin >> K;

    if(S == L) 
    {
        cout << "Possible length for the diving board: " << S * K << endl;
        return 0;
    }

    cout << "Possible lengths for the diving board: ";
    for(int length = S * K; length <= L * K; length += (L - S))
        cout << length << " ";
    cout << endl;
    return 0;

}