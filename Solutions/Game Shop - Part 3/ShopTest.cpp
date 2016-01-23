#include "Shop.h"

int main()
{
	Shop weaponArmorShop("Weapon/Armor Shop", "equip_item.txt");
	weaponArmorShop.ReadDataFromFile();

	Shop potionShop("Potion Shop", "potion_item.txt");
	potionShop.ReadDataFromFile();

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