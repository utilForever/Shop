#ifndef SHOP_H
#define SHOP_H

#include <memory>
#include <vector>
#include <fstream>

#include "Item.h"
#include "Player.h"

class Shop
{
public:
	Shop();
	Shop(std::string name, std::initializer_list<std::shared_ptr<Item>> items);
	Shop(std::string name, std::string fileName);
	Shop(const Shop& shop) = delete;
	Shop(Shop&& shop) = delete;
	~Shop();

	Shop& operator=(const Shop& rhs) = delete;
	Shop& operator=(Shop&& rhs) = delete;

	void ReadDataFromFile();

	void ShowShopMessage(Player& player) const;
	void ShowItemList() const;
	void ShowBuyMessage(Player& player) const;

	void BuyItem(Player& player, int index, int numItems) const;

private:
	std::ifstream m_fileStream;

	std::string m_name;
	std::string m_fileName;

	std::vector<std::shared_ptr<Item>> m_items;
};

#endif