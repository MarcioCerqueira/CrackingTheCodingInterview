#include <iostream>
#include <string>
#include <vector>
using namespace std;

double solve(const string& arithmeticExpression)
{
    
    string operators{"*+-/"};
    vector<double> numbers;
    vector<char> operations;
    
    size_t beg, pos = 0;
    while((beg = arithmeticExpression.find_first_not_of(operators, pos)) != string::npos)
    {
        pos = arithmeticExpression.find_first_of(operators, beg + 1);
        numbers.push_back(atoi(arithmeticExpression.substr(beg, pos - beg).c_str()));
    }

    for(const auto character : arithmeticExpression)
        if(character == '+' || character == '-' || character == '*' || character == '/')
            operations.push_back(character);

    
    for(int op = 0; op < operations.size(); op++)
    {
        bool validOperation = false;
        if(operations[op] == '*') 
        {
            numbers[op] *= numbers[op + 1];
            validOperation = true;
        }
        if(operations[op] == '/') 
        {
            numbers[op] /= numbers[op + 1];
            validOperation = true;
        }
        if(validOperation)
        {
            operations.erase(operations.begin() + op);
            numbers.erase(numbers.begin() + op + 1);
            op--;
        }
        
    }

    for(int op = 0; op < operations.size(); op++)
    {
        bool validOperation = false;
        if(operations[op] == '+') 
        {
            numbers[op] += numbers[op + 1];
            validOperation = true;
        }
        if(operations[op] == '-') 
        {
            numbers[op] -= numbers[op + 1];
            validOperation = true;
        }
        if(validOperation)
        {
            operations.erase(operations.begin() + op);
            numbers.erase(numbers.begin() + op + 1);
            op--;
        }

    }
    
    return numbers[0];
}

int main()
{

    string arithmeticExpression;
    cout << "Enter the arithmetic expression: "; 
    cin >> arithmeticExpression;
    cout << "Result: " << solve(arithmeticExpression) << endl;
    return 0;

}