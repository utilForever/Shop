#include <iostream>
#include <string>

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

void Player::AddItemToInventory(std::shared_ptr<Item> item, int numItems)
{
	auto iter = m_inventory.find(item->GetName());
	if (iter != m_inventory.end())
	{
		iter->second += numItems;
	}
	else
	{
		m_inventory.insert(std::pair<std::string, int>(item->GetName(), numItems));
	}
}

void Player::ShowInventory() const
{
	if (m_inventory.empty())
	{
		std::cout << "Inventory is empty!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		int itemIdx = 0;

		std::cout << "- Item List in Inventory -" << std::endl;
		for (auto item : m_inventory)
		{
			std::cout << "No. " << (itemIdx++) + 1 << ": ";
			std::cout << item.second << " " << item.first << std::endl;
		}
		std::cout << std::endl;
	}
}