#include "BlackjackCardGame.h"

BlackjackCardGame::BlackjackCardGame(int numberOfPlayers) : CardGame(numberOfPlayers)
{
}

bool BlackjackCardGame::play()
{

    if(players.size() == 0) 
    {
        cout << "No player has been found. Ending game..." << endl;
        return false;
    } 
    else if(players.size() == 1)
    {
        cout << "Player " << players[0]->getName() << " is the winner." << endl;
        return false;
    } 
    else 
    {
        if(deck.isEmpty())
        {
            checkFinalWinner();
            return false;
        } 
        else 
        {
            playRound();
            checkRoundWinner();
            clearHands();
            return true;   
        }
    }

}

void BlackjackCardGame::checkFinalWinner() const noexcept
{

    cout << "Deck is empty. Game is finished." << endl;
    int maxScore = -1;
    string winner;
    for(const auto& player : players)
        if(player->getScore() > maxScore) 
            maxScore = player->getScore();
    
    for(const auto& player : players)
    {
        if(player->getScore() == maxScore) 
        {
            if(winner.empty()) winner = player->getName();
            else winner += " and " + player->getName();
        }
    }
    cout << "Winner(s) is(are): " << winner << endl;
    cout << "Max Score: " << maxScore << endl;
            
}

void BlackjackCardGame::checkRoundWinner()
{

    cout << "Round has ended." << endl;            
            
    int maxScore = -1;
    vector<int> sums(players.size()); 
    for(int player = 0; player < players.size(); player++)
    {
        sums[player] = estimateValue(players[player]->getCards());
        if(sums[player] > maxScore && sums[player] <= 21) maxScore = sums[player];
    }    
    cout << "Max score of the round: " << maxScore << endl;
    
    if(maxScore == -1) 
    {
        cout << "No one is the winner of the round!" << endl;
    }
    else
    { 
        for(int player = 0; player < players.size(); player++)
        {
            if(sums[player] == maxScore)
            {
                cout << players[player]->getName() << " is the winner of the round!" << endl;
                players[player]->increaseScore(1);
            }
        }
    }

}

void BlackjackCardGame::clearHands() noexcept
{

    for(auto& player : players)
        player->discardCards();

}

int BlackjackCardGame::estimateValue(const vector<shared_ptr<Card>>& cards) const noexcept
{

    int sum = 0;
    for(const shared_ptr<Card>& card : cards) sum += card->getValue();
    return sum;

}

void BlackjackCardGame::playRound()
{

    for(int player = 0; player < players.size(); player++)
    {
        cout << "Cards remaining: " << deck.size() << endl;
        if(players[player]->drawCard(deck))
        {
            if(estimateValue(players[player]->getCards()) <= 21)
            {
                bool drawAgain = false;
                cout << "Do you want to take another card? 0 - No / Other number - Yes" << endl;
                cin >> drawAgain;
                if(drawAgain) player--;
            }
        } 
        else
        {
            break;
        }
    }
            
}