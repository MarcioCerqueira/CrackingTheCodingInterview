#include <iostream>
#include <string>

using namespace std;

string buildFromPattern(const string& pattern, const string& main, const string& alt)
{
    string output;
    char first = pattern.at(0);
    for(const auto& character : pattern)
    {
        if(character == first) output += main;
        else output += alt;
    }
    return output;
}

int countOf(const string& pattern, char c)
{
    int count = 0;
    for(const auto& character : pattern) if(character == c) count++;
    return count;
}

bool doesMatch(const string& pattern, const string& value)
{

    if(pattern.size() == 0) return value.size() == 0;
    char mainChar = pattern.at(0);
    char altChar = mainChar == 'a' ? 'b' : 'a';
    int countOfMain = countOf(pattern, mainChar);
    int countOfAlt = pattern.size() - countOfMain;
    int firstAlt = pattern.find_first_of(altChar);
    int maxMainSize = value.size() / countOfMain;

    for(int mainSize = 0; mainSize <= maxMainSize; mainSize++) 
    {
        int remainingSize = value.size() - mainSize * countOfMain;
        string first = value.substr(0, mainSize);
        if(countOfAlt == 0 || remainingSize % countOfAlt == 0)
        {
            int altIndex = firstAlt * mainSize;
            int altSize = countOfAlt == 0 ? 0 : remainingSize / countOfAlt;
            string second = countOfAlt == 0 ? "" : value.substr(altIndex, altSize);
            string cand = countOfAlt == 0 ? "" : buildFromPattern(pattern, first, second);
            if(cand == value) return true;
        }
    }
    return false;

}

int main()
{

    string pattern, value;
    cout << "Enter the pattern string: ";
    cin >> pattern;
    cout << "Enter the value string: ";
    cin >> value;    

    if(doesMatch(pattern, value)) cout << "Value matches pattern" << endl;
    else cout << "Value does not match pattern" << endl;
    return 0;

}