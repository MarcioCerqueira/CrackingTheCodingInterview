#include "BlackjackCard.h"

BlackjackCard::BlackjackCard(CardValue cardValue, CardSymbol cardSymbol) : Card(cardValue, cardSymbol)
{
}
    
int BlackjackCard::getValue() const noexcept
{
    if(value == CardValue::A) return static_cast<int>(value);
    else return min<int>(static_cast<int>(value), 10);
}