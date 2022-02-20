template<typename T>
Deck<T>::Deck()
{
    static_assert(is_base_of<Card, T>::value, "Class must be derived from Card");
    init();
}

template<typename T>
void Deck<T>::init()
{

    init(CardSymbol::Club);
    init(CardSymbol::Diamond);
    init(CardSymbol::Heart);
    init(CardSymbol::Spade);
    shuffle();

}

template<typename T>
void Deck<T>::init(CardSymbol baseSymbol)
{

    cards.push_back(T(CardValue::N2, baseSymbol));
    cards.push_back(T(CardValue::N3, baseSymbol));
    cards.push_back(T(CardValue::N4, baseSymbol));
    cards.push_back(T(CardValue::N5, baseSymbol));
    cards.push_back(T(CardValue::N6, baseSymbol));
    cards.push_back(T(CardValue::N7, baseSymbol));
    cards.push_back(T(CardValue::N8, baseSymbol));
    cards.push_back(T(CardValue::N9, baseSymbol));
    cards.push_back(T(CardValue::N10, baseSymbol));
    cards.push_back(T(CardValue::J, baseSymbol));
    cards.push_back(T(CardValue::Q, baseSymbol));
    cards.push_back(T(CardValue::K, baseSymbol));
    cards.push_back(T(CardValue::A, baseSymbol));
    
}

template<typename T>
void Deck<T>::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), default_random_engine(seed));
}

template<typename T>
bool Deck<T>::drawCard(shared_ptr<Card>& card) noexcept
{

    if(cards.size() > 0)
    {
        card = make_shared<T>(cards.back());
        cards.pop_back();
        return true;
    }
    return false;

}

template<typename T>
bool Deck<T>::isEmpty() const noexcept
{
    return cards.empty();
}

template<typename T>
int Deck<T>::size() const noexcept
{
    return cards.size();
}