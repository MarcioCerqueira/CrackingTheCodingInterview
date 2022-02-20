#include <iostream>
#include <string>
using namespace std;

//Time complexity: O(b)
string binaryToString(double number)
{

    string result;
    while(number && result.size() <= 32) 
    {
        number *= 2;
        result += (number >= 1) ? "1" : "0";
        if(number >= 1) number--;
    }
    
    if(result.size() >= 32) return "ERROR";
    else return "0," + result;

}

int main()
{

    cout << "Write a real number between 0 and 1" << endl;
    double number;
    cin >> number;

    if(number <= 0 || number >= 1) return 0;
    
    cout << binaryToString(number) << endl;
    return 0;

}