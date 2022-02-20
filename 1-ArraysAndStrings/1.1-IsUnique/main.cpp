#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

//Time complexity: O(N)
bool isUnique(const string& word)
{

    unordered_map<char, bool> hashMap;
    for(auto character : word)
    {
        if(hashMap[character]) return false;
        hashMap[character] = true;
    }
    return true;

}

int main()
{

    string word;
    cout << "Write a word: ";
    cin >> word;
    
    if(isUnique(word)) cout << "Has all unique characters? True" << endl;
    else cout << "Has all unique characters? False" << endl;
    return 0;

}