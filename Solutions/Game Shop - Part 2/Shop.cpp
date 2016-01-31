#include <iostream>
#include <string>

#include "Shop.h"

Shop::Shop()
{
	std::cout << "- Shop Closed -" << std::endl;
}

Shop::Shop(std::string name, std::initializer_list<std::shared_ptr<Item>> items)
	: m_name(name)
{
	for (auto& item : items)
	{
		m_items.push_back(item);
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