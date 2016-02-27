#include <iostream>
#include <string>

#include "Player.h"
#include "Shop.h"

Player::Player(std::string name, std::string fileName)
	: m_name(move(name)), m_gold(0), m_fileName(fileName)
{

}

Player::~Player()
{
	m_fileStream.close();
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

void Player::LoadPlayerInfoFromFile(Shop& weaponArmorShop, Shop& potionShop)
{
	m_fileStream.open(m_fileName, std::fstream::in);

	if (!m_fileStream.is_open())
	{
		m_name = "Anonymous";
		m_gold = 200;
		return;
	}

	m_fileStream >> m_name;
	m_fileStream >> m_gold;

	int numItemsInInventory = 0;
	m_fileStream >> numItemsInInventory;

	m_inventory.reserve(numItemsInInventory);

	std::string data = "";

	getline(m_fileStream, data);

	while (getline(m_fileStream, data))
	{
		std::string tokenizedString = data;

		std::string itemType, itemName;
		int numOfItem;

		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
		itemType = tokenizedString.substr(0, tokenizedString.find("\""));
		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
		itemName = tokenizedString.substr(0, tokenizedString.find("\""));
		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

		numOfItem = atoi(tokenizedString.c_str());

		std::shared_ptr<Item> item = nullptr;
		if (itemType == "Weapon" || itemType == "Armor")
		{
			item = weaponArmorShop.FindItemByName(itemName);
		}
		else if (itemType == "Potion")
		{
			item = potionShop.FindItemByName(itemName);
		}
		else
		{
			throw std::bad_exception();
		}

		if (item == nullptr)
		{
			throw std::bad_exception();
		}

		AddItemToInventory(item, numOfItem);
	}

	m_fileStream.close();
}

void Player::SavePlayerInfoToFile()
{
	m_fileStream.open(m_fileName, std::fstream::out | std::fstream::trunc);

	m_fileStream << m_name << std::endl;
	m_fileStream << m_gold << std::endl;

	m_fileStream << GetNumItemsInInventory() << std::endl;

	for (auto item : m_inventory)
	{
		std::string itemType, itemName;

		if (item.first->GetType() == "Weapon")
		{
			itemType = "\"Weapon\"";
		}
		else if (item.first->GetType() == "Armor")
		{
			itemType = "\"Armor\"";
		}
		else if (item.first->GetType() == "Poition")
		{
			itemType = "\"Potion\"";
		}
		else
		{
			throw std::bad_exception();
		}
		
		m_fileStream << itemType << " ";

		itemName = std::string("\"") + item.first->GetName() + "\"";
		m_fileStream << itemName << " ";

		m_fileStream << item.second << std::endl;
	}

	m_fileStream.close();
}