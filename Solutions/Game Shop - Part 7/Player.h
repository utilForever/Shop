#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include <fstream>

#include "Item.h"

class Shop;

class Player
{
public:
	Player() = delete;
	Player(std::string name, std::string fileName);

	Player(const Player& item) = delete;
	Player(Player&& item) = delete;
	~Player();

	Player& operator=(const Player& rhs) = delete;
	Player& operator=(Player&& rhs) = delete;

	int GetGold() const;
	void SetGold(int gold);

	void AddItemToInventory(std::shared_ptr<Item> item, int numItems);
	void RemoveItemFromInventory(size_t index, int numItems);

	void ShowInventory() const;

	size_t GetNumItemsInInventory() const;
	size_t GetNumItemsWithIndex(size_t index) const;
	std::shared_ptr<Item> GetItemWithIndex(size_t index) const;

	void LoadPlayerInfoFromFile(Shop& weaponArmorShop, Shop& potionShop);
	void SavePlayerInfoToFile();

private:
	std::string m_name;
	int m_gold;
	std::vector<std::pair<std::shared_ptr<Item>, int>> m_inventory;

	std::string m_fileName;
	std::fstream m_fileStream;
};

#endif