#include <iostream>

#include "Shop.h"

int main()
{
	Shop weaponArmorShop = Shop(
		"Weapon/Armor Shop",
		{
		std::make_shared<Weapon>("Sword", "Medium DMG", 3, 10, 10),
		std::make_shared<Armor>("Cap", "Light Armor", 1, 5, 5),
		std::make_shared<Armor>("Gloves", "Light Armor", 1, 5, 5),
		std::make_shared<Weapon>("Axe", "High DMG", 5, 1, 1),
		std::make_shared<Armor>("Boots", "Light Armor", 1, 5, 5)
		});

	Shop potionShop = Shop(
		"Potion Shop",
		{
		std::make_shared<Potion>("Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100),
		std::make_shared<Potion>("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50),
		std::make_shared<Potion>("Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200),
		std::make_shared<Potion>("Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100),
		std::make_shared<Potion>("Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300)
		});

	int inputIndex = 0;
	while (true)
	{
		std::cout << " - Shop Select - " << std::endl;
		std::cout << "   1. Weapon/Armor Shop" << std::endl;
		std::cout << "   2. Potion Shop" << std::endl;
		std::cout << "   3. Exit" << std::endl;
		std::cout << std::endl;

		std::cout << "Select : ";
		std::cin >> inputIndex;

		switch (inputIndex) {
		case 1:
			system("cls");
			weaponArmorShop.ShowItemList();
			break;
		case 2:
			system("cls");
			potionShop.ShowItemList();
			break;
		case 3:
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "Invalid number! Try again." << std::endl << std::endl;
			break;
		}
	}
}