#ifndef PLAYER_H
#define PLAYER_H

#include <map>
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

	void ShowInventory() const;

private:
	int m_gold;
	std::map<std::string, int> m_inventory;
};

#endif