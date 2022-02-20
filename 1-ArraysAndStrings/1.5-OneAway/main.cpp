#include <string>
#include <iostream>

using namespace std;

//Time complexity: O(N)
bool isZeroOrOneEditAway(const string& firstWord, const string& secondWord)
{

    //Zero edits  
    if(firstWord == secondWord) return true;

    //One edit - Character replaced
    if(firstWord.size() == secondWord.size())
    {

        int equalCharacters = 0;
        for(int characterIndex = 0; characterIndex < firstWord.size(); characterIndex++)
            if(firstWord[characterIndex] == secondWord[characterIndex])
                equalCharacters++;  
        if(equalCharacters == firstWord.size() - 1) return true;
        else return false;

    } 
    else
    {

        string biggestSentence = (firstWord.size() > secondWord.size()) ? firstWord : secondWord;
        string smallestSentence = (firstWord.size() < secondWord.size()) ? firstWord : secondWord; 
            
        //One edit - Character added or deleted
        if((biggestSentence.size() - smallestSentence.size()) != 1) return false;

        int equalCharacters = 0;
        bool editedCharacterHasBeenRemoved = false;
        for(int characterIndex = 0; characterIndex < smallestSentence.size(); characterIndex++)
        {

            if(!editedCharacterHasBeenRemoved && smallestSentence[characterIndex] != biggestSentence[characterIndex]) 
            {
                biggestSentence.erase(characterIndex, 1);
                editedCharacterHasBeenRemoved = true;
            }
            if(smallestSentence[characterIndex] == biggestSentence[characterIndex]) equalCharacters++;
                
        }
        if(equalCharacters == smallestSentence.size()) return true;
        else return false;
        
    }  

}

int main()
{
    
    string firstWord, secondWord;
    cout << "Write two words: ";
    cin >> firstWord >> secondWord;

    if(isZeroOrOneEditAway(firstWord, secondWord)) cout << "Is zero or one edit away: True" << endl;
    else cout << "Is zero or one edit away: False" << endl;
    return 0;

}