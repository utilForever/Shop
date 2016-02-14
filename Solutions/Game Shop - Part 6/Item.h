#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
	Item(std::string name, std::string description, int weight, int value);
	Item(const Item& item) = default;
	Item(Item&& item) = default;
	virtual ~Item() = default;

	Item& operator=(const Item& rhs) = default;
	Item& operator=(Item&& rhs) = default;

	virtual void Describe() const;
	std::string GetName() const;
	int GetGold() const;

protected:
	std::string m_name;
	std::string m_description;
	int m_weight;
	int m_value;
};

class Weapon : public Item
{
public:
	Weapon(std::string name, std::string description, int weight, int value, int damage);
	Weapon(const Weapon& weapon) = default;
	Weapon(Weapon&& weapon) = default;
	virtual ~Weapon() = default;

	Weapon& operator=(const Weapon& rhs) = default;
	Weapon& operator=(Weapon&& rhs) = default;

	void Describe() const override;

protected:
	int m_damage;
};

class Armor : public Item
{
public:
	Armor(std::string name, std::string description, int weight, int value, int defense);
	Armor(const Armor& armor) = default;
	Armor(Armor&& armor) = default;
	virtual ~Armor() = default;

	Armor& operator=(const Armor& rhs) = default;
	Armor& operator=(Armor&& rhs) = default;

	void Describe() const override;

protected:
	int m_defense;
};

class Potion : public Item
{
public:
	Potion(std::string name, std::string description, int weight, int value, std::string type, int capacity);
	Potion(const Potion& potion) = default;
	Potion(Potion&& potion) = default;
	virtual ~Potion() = default;

	Potion& operator=(const Potion& rhs) = default;
	Potion& operator=(Potion&& rhs) = default;

	void Describe() const override;

protected:
	std::string m_type;
	int m_capacity;
};

#endif