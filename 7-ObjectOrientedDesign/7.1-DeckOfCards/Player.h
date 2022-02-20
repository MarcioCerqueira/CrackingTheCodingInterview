#include <string>
#include <vector>
#include <iostream>
#include "Deck.h"

using namespace std;

class Player
{

public:
    explicit Player(const string& playerName) noexcept;
    void discardCards() noexcept;
    const vector<shared_ptr<Card>>& getCards() const noexcept;
    const string& getName() const noexcept;
    int getScore() const noexcept;
    void increaseScore(int valueToBeAdded) noexcept;
    template<typename T> bool drawCard(Deck<T>& deck)
    {

        static_assert(is_base_of<Card, T>::value, "Template class must be derived from Card");
        shared_ptr<Card> card;
        if(deck.drawCard(card)) 
        {
            cout << "Card drawn by player " << name << " is " << card->toString() << endl;
            cards.push_back(card);
            return true;
        }
        return false;
    }

private:
    const string name;
    int score;
    vector<shared_ptr<Card>> cards;

};
