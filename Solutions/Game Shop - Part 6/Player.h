#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>

#include "Item.h"

class Player
{
public:
	Player();
	Player(int gold);

	Player(const Player& item) = delete;
	Player(Player&& item) = delete;
	~Player() = default;

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

private:
	int m_gold;
	std::vector<std::pair<std::shared_ptr<Item>, int>> m_inventory;
};

#endif