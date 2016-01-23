#include "Item.h"

int main()
{
	Item* item = new Weapon("Excalibur", "The legendary sword of King Arthur", 12.0f, 1024.0f, 24.0f);
	item->Describe();

	std::cout << std::endl;

	item = new Armor("Steel Armor", "Protective covering made by steel", 15.0f, 805.0f, 18.0f);
	item->Describe();
}