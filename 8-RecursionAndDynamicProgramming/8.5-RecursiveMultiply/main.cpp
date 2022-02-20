#include <iostream>

using namespace std;

bool getLastBit(int n)
{
    return n & 1;
}

//Time complexity: O(log n)
int multiply(int a, int b, int digit = 0)
{
    if(b == 0) return 0;
    int partialProduct = (getLastBit(b) ? a : 0) << digit;
    return partialProduct + multiply(a, b >> 1, digit + 1);
}

int main()
{

    int a, b;
    cout << "Enter the two positive integers to be multiplied: " << endl;
    cin >> a >> b;
    cout << "The result of a * b is: " << multiply(a, b) << endl;
    return 0;

}