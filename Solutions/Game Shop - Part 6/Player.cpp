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
	bool isItemFound = false;
	for (auto itemInInventory : m_inventory)
	{
		if (itemInInventory.first->GetName() == item->GetName())
		{
			itemInInventory.second += numItems;
		}
	}

	if (!isItemFound)
	{
		m_inventory.emplace_back(make_pair(item, numItems));
	}
}

void Player::RemoveItemFromInventory(size_t index, int numItems)
{
	if (m_inventory[index].second - numItems <= 0)
	{
		m_inventory.erase(m_inventory.begin() + index);
	}
	else
	{
		m_inventory[index].second -= numItems;
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
			std::cout << item.second << " " << item.first->GetName() << std::endl;
			item.first->Describe();
		}
		std::cout << std::endl;
	}
}

size_t Player::GetNumItemsInInventory() const
{
	return m_inventory.size();
}

size_t Player::GetNumItemsWithIndex(size_t index) const
{
	return m_inventory[index].second;
}

std::shared_ptr<Item> Player::GetItemWithIndex(size_t index) const
{
	return m_inventory[index].first;
}