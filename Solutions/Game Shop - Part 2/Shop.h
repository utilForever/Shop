#ifndef SHOP_H
#define SHOP_H

#include <memory>
#include <vector>

#include "Item.h"

class Shop
{
public:
	Shop();
	Shop(std::string name, std::initializer_list<std::shared_ptr<Item>> items);
	Shop(const Shop& shop) = default;
	Shop(Shop&& shop) = default;
	~Shop() = default;

	Shop& operator=(const Shop& rhs) = default;
	Shop& operator=(Shop&& rhs) = default;

	void ShowItemList() const;

private:
	std::string m_name;
	std::vector<std::shared_ptr<Item>> m_items;
};

#endif