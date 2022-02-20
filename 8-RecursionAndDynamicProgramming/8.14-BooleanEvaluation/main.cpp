#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int countEval(string& expression, bool result, unordered_map<string, int>& memo)
{

    if(expression.size() == 0) return 0;
    if(expression.size() == 1) return expression == to_string(result);
    if(memo.find(to_string(result) + expression) != memo.end()) return memo[to_string(result) + expression];

    int ways = 0;
    for(int index = 1; index < expression.size(); index += 2)
    {
        char c = expression[index];
        string left = expression.substr(0, index);
        string right = expression.substr(index + 1);
        int leftTrue = countEval(left, true, memo);
        int leftFalse = countEval(left, false, memo);
        int rightTrue = countEval(right, true, memo);
        int rightFalse = countEval(right, false, memo);
        int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);

        int totalTrue = 0;
        if(c == '^') totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
        else if(c == '&') totalTrue = leftTrue * rightTrue;
        else if(c == '|') totalTrue = leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse;

        int subways = result ? totalTrue : total - totalTrue;
        ways += subways;
    }

    memo[to_string(result) + expression] = ways;
    return ways;

}

int main()
{

    string expression;
    cout << "Enter the boolean expression: ";
    cin >> expression;

    bool result;
    cout << "Enter the desired result (0 or 1): ";
    cin >> result;

    unordered_map<string, int> memo;
    cout << "Possible combinations: " << countEval(expression, result, memo) << endl;
    return 0;

}