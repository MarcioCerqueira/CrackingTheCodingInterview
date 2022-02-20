#include "Card.h"

class BlackjackCard : public Card
{

public:
    BlackjackCard(CardValue cardValue, CardSymbol cardSymbol);
    virtual int getValue() const noexcept override;
    
};