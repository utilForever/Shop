#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item
{
public:
	Item(std::string name, std::string description, float weight, float value);
	Item(const Item& item) = default;
	Item(Item&& item) = default;
	virtual ~Item() = default;

	Item& operator=(const Item& rhs) = default;
	Item& operator=(Item&& rhs) = default;

	virtual void Describe() const;

protected:
	std::string m_name;
	std::string m_description;
	float m_weight;
	float m_value;
};

class Weapon : public Item
{
public:
	Weapon(std::string name, std::string description, float weight, float value, float damage);
	Weapon(const Weapon& weapon) = default;
	Weapon(Weapon&& weapon) = default;
	virtual ~Weapon() = default;

	Weapon& operator=(const Weapon& rhs) = default;
	Weapon& operator=(Weapon&& rhs) = default;

	virtual void Describe() const override;

protected:
	float m_damage;
};

class Armor : public Item
{
public:
	Armor(std::string name, std::string description, float weight, float value, float defense);
	Armor(const Armor& armor) = default;
	Armor(Armor&& armor) = default;
	virtual ~Armor() = default;

	Armor& operator=(const Armor& rhs) = default;
	Armor& operator=(Armor&& rhs) = default;

	virtual void Describe() const override;

protected:
	float m_defense;
};

class Potion : public Item
{
public:
	Potion(std::string name, std::string description, float weight, float value, std::string type, float capacity);
	Potion(const Potion& potion) = default;
	Potion(Potion&& potion) = default;
	virtual ~Potion() = default;

	Potion& operator=(const Potion& rhs) = default;
	Potion& operator=(Potion&& rhs) = default;

	virtual void Describe() const override;

protected:
	std::string m_type;
	float m_capacity;
};

#endif