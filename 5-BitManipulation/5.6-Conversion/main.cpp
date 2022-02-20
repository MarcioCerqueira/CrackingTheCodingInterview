#include <iostream>

using namespace std;

//Time complexity: O(b)
int diff(int A, int B)
{

    int C = A ^ B;
    int count = 0;
    while(C) 
    {
        if(C & 1) count++;
        C = C >> 1;
    }
    return count;
}

int main()
{

    cout << "Write two integers: ";
    int A, B;
    cin >> A >> B;
    cout << diff(A, B) << endl;
    return 0;

}