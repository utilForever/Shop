```
#include <iostream>
#include <string>

class Item
{
public:
	Item(std::string name, std::string description, float weight, float value)
	{

	}

	virtual void Describe()
	{

	}

protected:

private:
};

class Weapon : public Item
{
public:
	Weapon(std::string name, std::string description, float weight, float value, float damage)
	{

	}

protected:

private:
};

class Armor : public Item
{
public:
	Armor(std::string name, std::string description, float weight, float value, float defense)
	{

	}

protected:

private:
};

int main()
{
	Item* item = new Weapon("Excalibur", "The legendary sword of King Arthur", 12.0f, 1024.0f, 24.0f);
	item->Describe();

	item = new Armor("Steel Armor", "Protective covering made by steel", 15.0f, 805.0f, 18.0f);
	item->Describe();
}
```

## 실행 결과
```
Name        = Excalibur
Description = The legendary sword of King Arthur
Weight      = 12 lbs
Value       = 1024 gold coins
Damage      = 24

Name        = Steel Armor
Description = Protective covering made by steel
Weight      = 15 lbs
Value       = 805 gold coins
Defense     = 18
```
