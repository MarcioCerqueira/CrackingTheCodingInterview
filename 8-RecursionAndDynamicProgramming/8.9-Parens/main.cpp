#include <iostream>
#include <string>

using namespace std;

//Time complexity: O(2^N)
void printParenthesesCombinations(int N, string prefix = "", int open = 0, int closed = 0)
{

    if(prefix.size() == N * 2)
    {
        cout << prefix << endl;
        return;
    }

    if(open < N) printParenthesesCombinations(N, prefix + "(", open + 1, closed);
    if(open > closed) printParenthesesCombinations(N, prefix + ")", open, closed + 1);

}

int main()
{

    int N;
    cout << "Write the desired number of pairs of parentheses: ";
    cin >> N;

    printParenthesesCombinations(N);
    return 0;
    
}