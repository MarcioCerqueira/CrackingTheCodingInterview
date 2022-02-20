#include <iostream>
#include <string>

using namespace std;

//Time complexity: O(n!)
void printPermutations(string word, string prefix = "")
{

    if(word.empty()) 
    {
        cout << prefix << endl;
        return;
    }

    for(int character = 0; character < word.size(); character++) {
        string temp = word;
        printPermutations(temp.erase(character, 1), prefix + word[character]);
    }

}

int main()
{

    string word;
    cout << "Enter a word with unique characters: ";
    cin >> word;

    printPermutations(word);
    return 0;
}