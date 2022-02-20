#include <iostream>

using namespace std;

int sum(int A, int B)
{

    while(true)
    {
        int a = A ^ B;
        int b = (A & B) << 1;
        if(a == 0 || b == 0) return a | b;
        else 
        {
            A = a;
            B = b;
        }
    }

}

int main()
{

    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Sum: " << sum(a, b) << endl;
    return 0;

}