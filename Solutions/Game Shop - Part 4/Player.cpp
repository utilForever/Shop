#include "Player.h"

Player::Player()
	: m_gold(0)
{
	
}

Player::Player(int gold)
	: m_gold(gold)
{
	
}

int Player::GetGold() const
{
	return m_gold;
}

void Player::SetGold(int gold)
{
	m_gold = gold;
}