#include <iostream>
#include <array>

using namespace std;

//Time complexity: O(N^2)
int countCombinations(const array<int, 4>& coins, int N, int sum = 0, int coinIndex = 0)
{

    if(sum > N) return 0;
    if(sum == N) return 1;

    int possibleCombinations = 0;
    for(int coin = coinIndex; coin < coins.size(); coin++)
        possibleCombinations += countCombinations(coins, N, coins[coin] + sum, coin);
    return possibleCombinations;

}

int main()
{

    array<int, 4> coins;
    coins[0] = 1;
    coins[1] = 5;
    coins[2] = 10;
    coins[3] = 25;

    int N;
    cout << "Write a positive integer representing the number of cents: ";
    cin >> N;

    if(N > 0) cout << "Number of combinations: " << countCombinations(coins, N) << endl;
    return 0;

}