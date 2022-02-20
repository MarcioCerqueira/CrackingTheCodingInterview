#include <iostream>

using namespace std;

int flip(int bit)
{
    return 1^bit;
}

int sign(int a)
{
    return flip((a >> 31) & 0x1);
}

int estimateMax(int a, int b)
{
    int c = a - b;
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    int use_sign_of_a = sa ^ sb;
    int use_sign_of_c = flip(sa ^ sb);
    int k = use_sign_of_a * sa + use_sign_of_c * sc;
    int q = flip(k);
    return a * k + b * q;
}

int main()
{

    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Max number: " << estimateMax(a, b) << endl;
    return 0;

}