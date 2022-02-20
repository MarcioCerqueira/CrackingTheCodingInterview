#include "Player.h"

Player::Player(const string& playerName) noexcept : name(playerName), score(0)
{
}

void Player::discardCards() noexcept
{
    cards.clear();
}

const vector<shared_ptr<Card>>& Player::getCards() const noexcept
{
    return cards;
}

const string& Player::getName() const noexcept
{
    return name;
}

int Player::getScore() const noexcept
{
    return score;
}

void Player::increaseScore(int valueToBeAdded) noexcept
{
    score += valueToBeAdded;
}