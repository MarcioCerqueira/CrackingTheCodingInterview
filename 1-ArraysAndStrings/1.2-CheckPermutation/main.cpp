#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

//Time complexity: O(N)
bool isPermutation(const string& firstWord, const string& secondWord)
{

    unordered_map<char, int> hashMap;
    for(auto character : firstWord) hashMap[character]++;
    for(auto character : secondWord) hashMap[character]--;
    for(auto character : firstWord) if(hashMap[character] != 0) return false;
    for(auto character : secondWord) if(hashMap[character] != 0) return false;
    return true;

}

int main()
{

    string firstWord, secondWord;
    cout << "Write two words: ";
    cin >> firstWord >> secondWord;

    if(isPermutation(firstWord, secondWord)) cout << "Is one permutation of the other? True" << endl;
    else cout << "Is one permutation of the other? False" << endl;
    return 0;
    
}