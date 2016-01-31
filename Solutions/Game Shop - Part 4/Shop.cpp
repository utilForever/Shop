#include <iostream>
#include <string>

#include "Shop.h"

Shop::Shop()
{
	std::cout << "- Shop Closed -" << std::endl;
}

Shop::Shop(std::string name, std::initializer_list<std::shared_ptr<Item>> items)
	: m_name(name), m_fileName("")
{
	for (auto& item : items)
	{
		m_items.push_back(item);
	}
}

Shop::Shop(std::string name, std::string fileName)
	: m_name(name), m_fileName(fileName)
{
	m_fileStream.open(m_fileName);

	if (!m_fileStream.is_open())
	{
		throw std::bad_exception();
	}
}

Shop::~Shop()
{
	m_fileStream.close();
}

void Shop::ReadDataFromFile()
{
	std::string data = "";

	while (std::getline(m_fileStream, data))
	{
		std::string tokenizedString = data;

		std::string type, name, description;
		int weight, value;

		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
		type = tokenizedString.substr(0, tokenizedString.find("\""));
		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
		name = tokenizedString.substr(0, tokenizedString.find("\""));
		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
		description = tokenizedString.substr(0, tokenizedString.find("\""));
		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

		tokenizedString = tokenizedString.substr(1);

		weight = atoi(tokenizedString.substr(0, tokenizedString.find(" ")).c_str());
		tokenizedString = tokenizedString.substr(tokenizedString.find(" ") + 1);
		value = atoi(tokenizedString.substr(0, tokenizedString.find(" ")).c_str());
		tokenizedString = tokenizedString.substr(tokenizedString.find(" ") + 1);

		if (type == "Weapon")
		{
			int damage = atoi(tokenizedString.c_str());

			m_items.push_back(std::make_shared<Weapon>(name, description, weight, value, damage));
		}
		else if (type == "Armor")
		{
			int defense = atoi(tokenizedString.c_str());

			m_items.push_back(std::make_shared<Armor>(name, description, weight, value, defense));
		}
		else if (type == "Potion")
		{
			tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
			std::string potionType = tokenizedString.substr(0, tokenizedString.find("\""));
			tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
			int capacity = atoi(tokenizedString.c_str());

			m_items.push_back(std::make_shared<Potion>(name, description, weight, value, potionType, capacity));
		}
		else
		{
			throw std::bad_exception();
		}
	}
}

void Shop::ShowShopMessage(Player& player) const
{
	int inputIndex = 0;

	while (true)
	{
		std::cout << "Welcome to " << m_name << "!" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		std::cout << "1. Show Item List" << std::endl;
		std::cout << "2. Buy Item" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << std::endl;

		std::cout << "Select : ";
		std::cin >> inputIndex;

		switch (inputIndex) {
		case 1:
			ShowItemList();
			break;
		case 2:
			ShowBuyMessage(player);
			break;
		case 3:
			return;
			break;
		default:
			std::cout << "Error: Invalid number, please input again." << std::endl;
			break;
		}
	}
}

void Shop::ShowItemList() const
{
	int itemIdx = 0;

	std::cout << "- Item List -" << std::endl;
	for (auto item : m_items)
	{
		std::cout << "No. " << (itemIdx++) + 1 << std::endl;
		item->Describe();
		std::cout << std::endl;
	}
}

void Shop::ShowBuyMessage(Player& player) const
{
	size_t buyItemIndex = 0;

	while (true)
	{
		std::cout << "Which item to buy?";
		std::cout << " (1 ~ " << m_items.size() << ", 0: Exit) ";

		std::cin >> buyItemIndex;

		if (buyItemIndex == 0)
		{
			return;
		}
		
		if (buyItemIndex < 1 || buyItemIndex > m_items.size())
		{
			std::cout << "Error: Invalid number, please input again." << std::endl;
		}
		else
		{
			BuyItem(player, buyItemIndex - 1);
			return;
		}
	}
}

void Shop::BuyItem(Player& player, int index) const
{
	if (player.GetGold() - m_items[index]->GetGold() < 0)
	{
		std::cout << "You can't buy this, because you don't have enough gold!" << std::endl;
	}
	else
	{
		std::cout << "Thanks for buying the " << m_items[index]->GetName() << "!" << std::endl;
		std::cout << "Now, your gold is " << player.GetGold() << " - " << m_items[index]->GetGold() << " = ";
		player.SetGold(player.GetGold() - m_items[index]->GetGold());
		std::cout << player.GetGold() << std::endl;
		std::cout << std::endl;
	}
}