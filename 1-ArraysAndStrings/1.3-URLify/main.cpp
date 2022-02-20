#include <string>
#include <iostream>

using namespace std;

//Time complexity: O(N)
void urlify(string& sentence)
{

    bool endHasBeenFound = false;
    int endIndex = sentence.size() - 1;
    for(int index = sentence.size() - 1; index >= 0; index--)
    {
        if(sentence[index] != ' ')
        {
            endHasBeenFound = true;
            swap(sentence[index], sentence[endIndex]);
            endIndex--;
        }
        else if(sentence[index] == ' ' && endHasBeenFound)
        {
            sentence[endIndex] = '0';
            sentence[endIndex - 1] = '2';
            sentence[endIndex - 2] = '%';
            endIndex -= 3;
        }
    }

}

int main()
{

    string sentence;
    cout << "Write a sentence: ";
    getline(cin, sentence);
    
    urlify(sentence);
    cout << "URL version of the sentence: " << sentence << endl;
    return 0;

}