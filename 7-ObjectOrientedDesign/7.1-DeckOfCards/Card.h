#include <string>
#include "CardSymbol.h"
#include "CardValue.h"

using namespace std;

class Card
{

public:
    Card(CardValue cardValue, CardSymbol cardSymbol);
    const string toString() const noexcept;
    virtual int getValue() const noexcept = 0;
    virtual ~Card() {};

protected:
    CardValue value;
    CardSymbol symbol;

};