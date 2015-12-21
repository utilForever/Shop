#include "Shop.h"

int main(int argc, char* argv[])
{
	Shop weaponArmorShop = Shop(
		"Weapon/Armor Shop", 
	{
		std::make_shared<Weapon>("Sword", "Medium DMG", 3.0f, 10.0f, 10.0f),
		std::make_shared<Armor> ("Cap", "Light Armor", 1.0f, 5.0f, 5.0f),
		std::make_shared<Armor> ("Gloves", "Light Armor", 1.0f, 5.0f, 5.0f),
		std::make_shared<Weapon>("Axe", "High DMG", 5.0f, 15.0f, 15.0f),
		std::make_shared<Armor> ("Boots", "Light Armor", 1.0f, 5.0f, 5.0f)
	});

	Shop potionShop = Shop(
		"Potion Shop",
	{
		std::make_shared<Potion>("Small Health Potion", "Recovery 100 HP", 1.0f, 50.0f, "Health", 100.0f),
		std::make_shared<Potion>("Small Mana Potion", "Recovery 50 MP", 0.5f, 30.0f, "Mana", 50.0f),
		std::make_shared<Potion>("Medium Health Potion", "Recovery 200 HP", 2.0f, 120.0f, "Health", 200.0f),
		std::make_shared<Potion>("Medium Mana Potion", "Recovery 100 MP", 1.0f, 75.0f, "Mana", 100.0f),
		std::make_shared<Potion>("Large Health Potion", "Recovery 300 HP", 3.0f, 200.0f, "Health", 300.0f)
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
		}
	}
}