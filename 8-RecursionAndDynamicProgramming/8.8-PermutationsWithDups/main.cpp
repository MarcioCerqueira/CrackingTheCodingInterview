#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//Time complexity: O(n!)
void printPermutations(unordered_map<char, int>& charFrequency, string prefix = "")
{

    if(charFrequency.empty()) 
    {
        cout << prefix << endl;
        return;
    }

    for(auto& element : charFrequency) 
    {
        unordered_map<char, int> charFrequencyClone = charFrequency;
        charFrequencyClone[element.first]--;
        if(charFrequencyClone[element.first] == 0) charFrequencyClone.erase(element.first);
        printPermutations(charFrequencyClone, prefix + element.first);
    }

}

void countCharFrequency(const string& word, unordered_map<char, int>& charFrequency)
{

    for(int character = 0; character < word.size(); character++) 
        charFrequency[word[character]]++;

}

int main()
{

    string word;
    cout << "Enter a word with unique characters: ";
    cin >> word;

    unordered_map<char, int> charFrequency{};
    countCharFrequency(word, charFrequency);
    printPermutations(charFrequency);
    return 0;

}