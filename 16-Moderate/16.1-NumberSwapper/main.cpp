#include <iostream>

using namespace std;


void swapInPlace(int& a, int& b)
{

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

}

int main()
{

    int a, b;
    cout << "Enter two integer numbers: ";
    cin >> a >> b;
    swapInPlace(a, b);
    cout << "Swapped numbers: " << a << " " << b << endl;
    return 0;

}