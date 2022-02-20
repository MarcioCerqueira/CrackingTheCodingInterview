#include <iostream>

using namespace std;

//Time complexity: O(1)
int main()
{

    cout << "Write a number: ";
    int N;
    cin >> N;
    cout << static_cast<int>(((N & N - 1)) == 0) << endl;
    return 0;
    
}