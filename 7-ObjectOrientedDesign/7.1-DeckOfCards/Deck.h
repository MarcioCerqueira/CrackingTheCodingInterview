#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <memory>
#include "BlackjackCard.h"

using namespace std;

template<typename T>
class Deck
{

public:
    Deck();
    void init();
    void shuffle();
    bool drawCard(shared_ptr<Card>& card) noexcept;
    bool isEmpty() const noexcept;
    int size() const noexcept;

private:
    void init(CardSymbol baseSymbol);
    vector<T> cards;
    
};

#include "Deck_impl.h"