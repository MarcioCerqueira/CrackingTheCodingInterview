#include "BlackjackCardGame.h"

int main()
{

    try
    {
        
        int numberOfPlayers;
        cout << "Enter the number of players:" << endl;
        cin >> numberOfPlayers;

        BlackjackCardGame blackjackCardGame(numberOfPlayers);
        while(blackjackCardGame.play()) {}
        
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
    
    return 0;

}