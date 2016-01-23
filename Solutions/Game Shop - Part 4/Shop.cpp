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
	std::string dataStream;

	while (std::getline(m_fileStream, dataStream))
	{
		std::string tokenedStream = dataStream;

		std::string type, name, description;
		float weight, value;

		tokenedStream = tokenedStream.substr(tokenedStream.find("\"") + 1);
		type = tokenedStream.substr(0, tokenedStream.find("\""));
		tokenedStream = tokenedStream.substr(tokenedStream.find("\"") + 1);

		tokenedStream = tokenedStream.substr(tokenedStream.find("\"") + 1);
		name = tokenedStream.substr(0, tokenedStream.find("\""));
		tokenedStream = tokenedStream.substr(tokenedStream.find("\"") + 1);

		tokenedStream = tokenedStream.substr(tokenedStream.find("\"") + 1);
		description = tokenedStream.substr(0, tokenedStream.find("\""));
		tokenedStream = tokenedStream.substr(tokenedStream.find("\"") + 1);

		tokenedStream = tokenedStream.substr(1);

		weight = atof(tokenedStream.substr(0, tokenedStream.find(" ")).c_str());
		tokenedStream = tokenedStream.substr(tokenedStream.find(" ") + 1);
		value = atof(tokenedStream.substr(0, tokenedStream.find(" ")).c_str());
		tokenedStream = tokenedStream.substr(tokenedStream.find(" ") + 1);

		if (type == "Weapon")
		{
			float damage = atof(tokenedStream.c_str());

			m_items.push_back(std::make_shared<Weapon>(name, description, weight, value, damage));
		}
		else if (type == "Armor")
		{
			float defense = atof(tokenedStream.c_str());

			m_items.push_back(std::make_shared<Armor>(name, description, weight, value, defense));
		}
		else if (type == "Potion")
		{
			tokenedStream = tokenedStream.substr(tokenedStream.find("\"") + 1);
			std::string potionType = tokenedStream.substr(0, tokenedStream.find("\""));
			tokenedStream = tokenedStream.substr(tokenedStream.find("\"") + 1);
			float capacity = atof(tokenedStream.c_str());

			m_items.push_back(std::make_shared<Potion>(name, description, weight, value, potionType, capacity));
		}
		else
		{
			throw std::bad_exception();
		}
	}
}

void Shop::ShowItemList() const
{
	std::cout << "- Item List -" << std::endl;
	for (int i = 0; i < m_items.size(); ++i)
	{
		std::cout << "No. " << i + 1 << std::endl;
		m_items[i]->Describe();
		std::cout << std::endl;
	}
}

void Shop::ShowShopMessage(Player& player) const
{
	int inputIndex = 0;

	std::cout << "Welcome to " << m_name << "!" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "1. Show Item List" << std::endl;
	std::cout << "2. Buy Item" << std::endl;
	std::cout << "3. Sell Item" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << std::endl;

	std::cout << "Select : ";
	std::cin >> inputIndex;

	int buyItemIndex = 0;
	bool isValidNumber = false;

	switch (inputIndex) {
	case 1:
		ShowItemList();
		break;
	case 2:
		ShowItemList();

		while (!isValidNumber)
		{
			std::cout << "Which item to buy?";
			std::cout << " (1 ~ " << m_items.size() << ", 0: Exit) ";

			std::cin >> buyItemIndex;

			if (buyItemIndex < 1 || buyItemIndex > m_items.size())
			{
				std::cout << "Error: Input invalid number, please input again." << std::endl;
			}
			else
			{
				isValidNumber = true;
			}
		}

		BuyItem(player, buyItemIndex - 1);
		break;
	case 3:
		break;
	case 4:
		break;
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
	}
}