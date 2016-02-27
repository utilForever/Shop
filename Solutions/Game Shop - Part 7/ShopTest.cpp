#include <iostream>

#include "Player.h"
#include "Shop.h"

void ShowShopList(Player&, Shop&, Shop&);

int main()
{
	Shop weaponArmorShop("Weapon/Armor Shop", "equip_item.txt");
	weaponArmorShop.ReadDataFromFile();

	Shop potionShop("Potion Shop", "potion_item.txt");
	potionShop.ReadDataFromFile();

	Player player("Adol", "player_info.txt");
	player.LoadPlayerInfoFromFile(weaponArmorShop, potionShop);

	ShowShopList(player, weaponArmorShop, potionShop);

	player.SavePlayerInfoToFile();

	return 0;
}

void ShowShopList(Player& player, Shop& weaponArmorShop, Shop& potionShop)
{
	int inputIndex = 0;
	while (true)
	{
		std::cout << " - Shop Select - " << std::endl;
		std::cout << "   0. Show Player's Inventory" << std::endl;
		std::cout << "   1. Weapon/Armor Shop" << std::endl;
		std::cout << "   2. Potion Shop" << std::endl;
		std::cout << "   3. Exit" << std::endl;
		std::cout << std::endl;

		std::cout << "Select : ";
		std::cin >> inputIndex;

		switch (inputIndex) {
		case 0:
			system("cls");
			player.ShowInventory();
			break;
		case 1:
			system("cls");
			weaponArmorShop.ShowShopMessage(player);
			system("cls");
			break;
		case 2:
			system("cls");
			potionShop.ShowShopMessage(player);
			system("cls");
			break;
		case 3:
			return;
			break;
		default:
			std::cout << "Error: Invalid number, please input again." << std::endl;
			break;
		}
	}
}