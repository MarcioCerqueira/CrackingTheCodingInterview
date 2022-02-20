#include <iostream>

using namespace std;

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    int count = 0;
    for(int i = 5; n / i > 0; i *= 5) count += n / i;
    cout << n << "! has " << count << " trailing zeros " << endl;
    return 0;

}