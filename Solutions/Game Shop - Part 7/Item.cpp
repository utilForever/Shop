#include <iostream>
#include <string>

#include "Item.h"


Item::Item(std::string name, std::string description, int weight, int value)
	: m_name(name), m_description(description), m_weight(weight), m_value(value)
{
	
}

void Item::Describe() const
{
	std::cout << "Name        = " << m_name << std::endl;
	std::cout << "Description = " << m_description << std::endl;
	std::cout << "Weight      = " << m_weight << " lbs" << std::endl;
	std::cout << "Value       = " << m_value << " gold coins" << std::endl;
}

std::string Item::GetName() const
{
	return m_name;
}

int Item::GetGold() const
{
	return m_value;
}

Weapon::Weapon(std::string name, std::string description, int weight, int value, int damage)
	: Item(name, description, weight, value), m_damage(damage)
{
	
}

void Weapon::Describe() const
{
	Item::Describe();
	std::cout << "Damage      = " << m_damage << std::endl;
}

std::string Weapon::GetType() const
{
	return move(std::string("Weapon"));
}

Armor::Armor(std::string name, std::string description, int weight, int value, int defense)
	: Item(name, description, weight, value), m_defense(defense)
{

}

void Armor::Describe() const
{
	Item::Describe();
	std::cout << "Defense     = " << m_defense << std::endl;
}

std::string Armor::GetType() const
{
	return move(std::string("Armor"));
}

Potion::Potion(std::string name, std::string description, int weight, int value, std::string type, int capacity)
	: Item(name, description, weight, value), m_type(type), m_capacity(capacity)
{

}

void Potion::Describe() const
{
	Item::Describe();
	std::cout << "Type        = " << m_type << std::endl;
	std::cout << "Capacity    = " << m_capacity << std::endl;
}

std::string Potion::GetType() const
{
	return move(std::string("Potion"));
}