template<typename T>
CardGame<T>::CardGame(int numberOfPlayers)
{

    static_assert(is_base_of<Card, T>::value, "Template class must be derived from Card");
    if(numberOfPlayers <= 0) return;

    players.resize(numberOfPlayers);
    string name;
    for(int player = 0; player < numberOfPlayers; player++)
    {
        cout << "Enter the name of player " << player + 1 << endl;
        cin >> name;
        players[player] = make_shared<Player>(name);
    }

}