#include <iostream>

using namespace std;

int negative(int a)
{
    int negativeA = 0;
    int sign = (a > 0) ? -1 : 1;
    while(a != 0)
    {
        negativeA += sign;
        a += sign;
    }
    return negativeA;
}

int subtract(int a, int b)
{
    return a + negative(b);
}

int multiply(int a, int b)
{
    int result = 0;
    if(b > 0) 
    {
        for(int i = 0; i < b; i++) result += a;
    }
    else 
    {
        int negateA = negative(a);
        for(int i = 0; i > b; i+=-1) result += negateA;
    }
    return result;
}


int divide(int a, int b)
{
    if(b == 0) return 0; //Yeah, I know this is an exception
    int absa = abs(a);
    int absb = abs(b);
    int product = 0;
    int x = 0;
    while(product + absb <= absa)
    {
        product += absb;
        x++;
    }
    if((a < 0 && b < 0) || (a > 0 && b > 0)) return x;
    else return negative(x);
}

int main()
{

    int a, b;
    cout << "Enter two integer numbers: ";
    cin >> a >> b;
    cout << "a - b: " << subtract(a, b) << endl;
    cout << "a * b: " << multiply(a, b) << endl;
    cout << "a / b: " << divide(a, b) << endl;
    return 0;

}