#include "Card.h"

Card::Card(CardValue cardValue, CardSymbol cardSymbol) : value(cardValue), symbol(cardSymbol)
{

}

const string Card::toString() const noexcept
{
    string result;
    switch(value)
    {
        case CardValue::N2:
            result = "2";
            break;
        case CardValue::N3:
            result = "3";
            break;
        case CardValue::N4:
            result = "4";
            break;
        case CardValue::N5:
            result = "5";
            break;
        case CardValue::N6:
            result = "6";
            break;
        case CardValue::N7:
            result = "7";
            break;
        case CardValue::N8:
            result = "8";
            break;
        case CardValue::N9:
            result = "9";
            break;
        case CardValue::N10:
            result = "10";
            break;
        case CardValue::J:
            result = "J";
            break;
        case CardValue::Q:
            result = "Q";
            break;
        case CardValue::K:
            result = "K";
            break;
        case CardValue::A:
            result = "A";
            break;
    }
    switch(symbol)
    {
        case CardSymbol::Club:
            result += " of club";
            break;
        case CardSymbol::Diamond:
            result += " of diamond";
            break;
        case CardSymbol::Heart:
            result += " of heart";
            break;
        case CardSymbol::Spade:
            result += " of spade";
            break;
    }
    return result;
    
}
    