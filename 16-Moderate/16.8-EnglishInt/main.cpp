#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

string toString(int number)
{

    unordered_map<int, string> numerals;
    numerals[0] = "";
    numerals[1] = "One";
    numerals[2] = "Two";
    numerals[3] = "Three";
    numerals[4] = "Four";
    numerals[5] = "Five";
    numerals[6] = "Six";
    numerals[7] = "Seven";
    numerals[8] = "Eight";
    numerals[9] = "Nine";

    unordered_map<int, string> teens;
    teens[0] = "Ten";
    teens[1] = "Eleven";
    teens[2] = "Twelve";
    teens[3] = "Thirteen";
    teens[4] = "Fourteen";
    teens[5] = "Fifteen";
    teens[6] = "Sixteen";
    teens[7] = "Seventeen";
    teens[8] = "Eighteen";
    teens[9] = "Nineteen";
    
    unordered_map<int, string> tenths;
    tenths[2] = "Twenty";
    tenths[3] = "Thirty";
    tenths[4] = "Forty";
    tenths[5] = "Fifty";
    tenths[6] = "Sixty";
    tenths[7] = "Seventy";
    tenths[8] = "Eighty";
    tenths[9] = "Ninety";

    if(number == 0) return "Zero";
    
    stack<int> digits;
    while(number > 0)
    {
        digits.push(number % 10);
        number /= 10;
    }

    string result;
    while(!digits.empty())
    {

        if(digits.top() == 0) 
        {
            digits.pop();
            continue;
        }

        if(!result.empty()) result += " ";

        if(digits.size() % 3 == 2)
        {
            if(digits.top() == 1)
            {
                digits.pop();
                result += teens[digits.top()];
                digits.pop();
            } 
            else
            {
                result += tenths[digits.top()];
            }
        } 
        else 
        {
            result += numerals[digits.top()];
        }

        if(digits.size() == 10) result += " Billion";
        if(digits.size() == 7) result += " Million";
        if(digits.size() == 4) result += " Thousand";
        if(digits.size() % 3 == 0) result += " Hundred";
        if(digits.size() > 0) digits.pop();

    }
    
    return result;

}

int main()
{

    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << toString(number) << endl;
    return 0;

}