#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void loadArrayOfStrings(vector<string>& strings)
{

    int size;
    cout << "Enter the size of the array of strings: ";
    cin >> size;
    strings.resize(size);

    cout << "Enter each string: ";
    for(auto& sentence : strings) cin >> sentence;

}

//Time complexity: O(sclog(c))
void sortArrayOfStrings(vector<string>& strings)
{

    map<string, vector<string>> anagramToString;
    for(const auto& sentence : strings)
    {

        vector<char> characters;
        string sortedCharacters;
        
        for(const auto& character : sentence) characters.push_back(character);
        sort(characters.begin(), characters.end());
        
        for(const auto& character : characters) sortedCharacters.push_back(character);
        anagramToString[sortedCharacters].push_back(sentence);

    }

    strings.clear();
    for(auto& element : anagramToString) 
    {
        sort(element.second.begin(), element.second.end());
        for(auto& sentence : element.second) strings.push_back(sentence);
    }

}

void printArrayOfStrings(const vector<string>& strings)
{

    cout << "Sorted array of strings: " << endl;
    for(auto& sentence : strings) cout << sentence << endl;

}

int main()
{
    
    vector<string> strings;
    loadArrayOfStrings(strings);
    sortArrayOfStrings(strings);
    printArrayOfStrings(strings);
    return 0;

}