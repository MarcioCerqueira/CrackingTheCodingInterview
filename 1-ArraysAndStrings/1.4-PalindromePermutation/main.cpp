#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//Time complexity: O(N)
bool isPalindromePermutation(const string& word)
{

    unordered_map<char, int> hashMap;

    for(auto character : word)
        hashMap[character]++;

    int pairsFound = 0;
    for(auto character : word) 
    {
        pairsFound += hashMap[character] / 2;
        hashMap[character] = 0;
    }
    
    if(word.size() % 2 == 0 && pairsFound * 2 == word.size()) return true;
    else if(word.size() % 2 == 1 && pairsFound * 2 == word.size() - 1) return true;
    else return false;

}

int main()
{

    string word;
    cout << "Write a word: ";
    cin >> word;
    
    if(isPalindromePermutation(word)) cout << "Is a palindrome permutation? True" << endl;
    else cout << "Is a palindrome permutation? False" << endl;   
    return 0;

}