#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int countHits(const string& solution, const string& guess)
{

    int hits = 0;
    for(int position = 0; position < 4; position++)
        if(solution[position] == guess[position])
            hits++;
    return hits;

}

int countPseudoHits(const string& solution, const string& guess)
{

    unordered_map<char, int> colorFrequency;
    colorFrequency['R'] = 0;
    colorFrequency['G'] = 0;
    colorFrequency['B'] = 0;
    colorFrequency['Y'] = 0;
    
    for(const auto& character : solution) colorFrequency[character]++;
    
    int pseudoHits = 0;
    for(int position = 0; position < 4; position++) 
    {

        if(solution[position] == guess[position]) continue;
        if(colorFrequency[guess[position]] == 0) continue;

        for(int otherPosition = 0; otherPosition < 4; otherPosition++)
        {

            if(solution[otherPosition] == guess[otherPosition]) continue;

            if(solution[otherPosition] == guess[position]) 
            {
                pseudoHits++;
                break;
            }

        }

        colorFrequency[guess[position]]--;

    }

    return pseudoHits;

}

int main()
{

    string solution, guess;
    cout << "Enter the solution of the MasterMind game: ";
    cin >> solution;

    cout << "Enter the guess of the MasterMind game: ";
    cin >> guess;

    if(solution.size() != 4 || guess.size() != 4) 
    {
        cout << "Solution and guess must have only four characters." << endl;
        return 0;
    }

    cout << countHits(solution, guess) << " hit(s)." << endl;
    cout << countPseudoHits(solution, guess) << " pseudo-hit(s)." << endl;
    return 0;

}