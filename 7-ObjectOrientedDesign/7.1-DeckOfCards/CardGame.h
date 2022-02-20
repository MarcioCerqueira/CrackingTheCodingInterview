#include <vector>
#include <iostream>
#include <memory>
#include "Player.h"

using namespace std;

template <typename T>
class CardGame
{

public:
    explicit CardGame(int numberOfPlayers);
    virtual bool play() = 0;
    virtual ~CardGame() {};

protected:
    Deck<T> deck;
    vector<shared_ptr<Player>> players;
    
};

#include "CardGame_impl.h"