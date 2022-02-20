#include <cmath>
#include "CardGame.h"

class BlackjackCardGame : public CardGame<BlackjackCard>
{

public:
    explicit BlackjackCardGame(int numberOfPlayers);
    virtual bool play() override;

private:
    void checkFinalWinner() const noexcept;
    void checkRoundWinner();
    void clearHands() noexcept;
    int estimateValue(const vector<shared_ptr<Card>>& cards) const noexcept;
    void playRound();
};