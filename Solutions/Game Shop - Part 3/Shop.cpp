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
		float weight, value;

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

		weight = static_cast<float>(atof(tokenizedString.substr(0, tokenizedString.find(" ")).c_str()));
		tokenizedString = tokenizedString.substr(tokenizedString.find(" ") + 1);
		value = static_cast<float>(atof(tokenizedString.substr(0, tokenizedString.find(" ")).c_str()));
		tokenizedString = tokenizedString.substr(tokenizedString.find(" ") + 1);

		if (type == "Weapon")
		{
			float damage = static_cast<float>(atof(tokenizedString.c_str()));

			m_items.push_back(std::make_shared<Weapon>(name, description, weight, value, damage));
		}
		else if (type == "Armor")
		{
			float defense = static_cast<float>(atof(tokenizedString.c_str()));

			m_items.push_back(std::make_shared<Armor>(name, description, weight, value, defense));
		}
		else if (type == "Potion")
		{
			tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
			std::string potionType = tokenizedString.substr(0, tokenizedString.find("\""));
			tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
			float capacity = static_cast<float>(atof(tokenizedString.c_str()));

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
	std::cout << "Welcome to " << m_name << "!" << std::endl;
	std::cout << "- Item List -" << std::endl;
	for (auto& item : m_items)
	{
		item->Describe();
		std::cout << std::endl;
	}
}