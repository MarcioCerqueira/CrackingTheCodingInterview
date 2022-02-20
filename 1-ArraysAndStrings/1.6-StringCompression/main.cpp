#include <string>
#include <iostream>

using namespace std;

//Time complexity: O(N)
string compress(const string& word)
{

    string compressedWord;
    compressedWord += word[0];
    int characterCount = 1;
    
    for(int characterIndex = 1; characterIndex < word.size(); characterIndex++)
    {
        if(word[characterIndex] == word[characterIndex - 1]) 
        {
            characterCount++;
        }
        else 
        {
            compressedWord += to_string(characterCount);
            compressedWord += word[characterIndex];
            characterCount = 1;
        }
    }
    compressedWord += to_string(characterCount);

    if(word.size() <= compressedWord.size()) return word;
    else return compressedWord;

}

int main()
{

    string word;
    cout << "Write a word: ";
    cin >> word;

    cout << "Compressed word: " << compress(word) << endl;
    return 0;

}