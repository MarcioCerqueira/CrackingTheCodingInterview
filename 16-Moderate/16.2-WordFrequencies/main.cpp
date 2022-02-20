#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> buildWordFrequencyMap(const string& text)
{

    unordered_map<string, int> wordFrequency;
    string word;
    for(auto character : text)
    {
        if(character != ' ') 
        {
            word += character;
        }
        else 
        {
            wordFrequency[word]++;
            word.clear();
        }
    }
    if(!word.empty()) wordFrequency[word]++;
    return wordFrequency;

}

void searchWords(unordered_map<string, int> wordFrequency)
{

    string searchWord;
    int frequency;
    do 
    {
        
        cout << "Enter a search word or 'exit' to stop the application" << endl;
        cin >> searchWord;
        frequency = 0;
        if(wordFrequency.find(searchWord) != wordFrequency.end()) 
            frequency = wordFrequency[searchWord];
        cout << "Word frequency: " << frequency << endl;
        
    } while(searchWord != "exit");

}

int main()
{

    string text;
    cout << "Write the original text: ";
    getline(cin, text);

    unordered_map<string, int> wordFrequency = buildWordFrequencyMap(text);
    searchWords(wordFrequency);
    
    return 0;

}