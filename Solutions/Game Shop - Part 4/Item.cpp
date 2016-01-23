#include "Item.h"

Item::Item(std::string name, std::string description, float weight, float value)
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

float Item::GetGold() const
{
	return m_value;
}

Weapon::Weapon(std::string name, std::string description, float weight, float value, float damage)
	: Item(name, description, weight, value), m_damage(damage)
{
	
}

void Weapon::Describe() const
{
	Item::Describe();
	std::cout << "Damage      = " << m_damage << std::endl;
}

Armor::Armor(std::string name, std::string description, float weight, float value, float defense)
	: Item(name, description, weight, value), m_defense(defense)
{

}

void Armor::Describe() const
{
	Item::Describe();
	std::cout << "Defense     = " << m_defense << std::endl;
}

Potion::Potion(std::string name, std::string description, float weight, float value, std::string type, float capacity)
	: Item(name, description, weight, value), m_type(type), m_capacity(capacity)
{

}

void Potion::Describe() const
{
	Item::Describe();
	std::cout << "Type         = " << m_type << std::endl;
	std::cout << "Capacity     = " << m_capacity << std::endl;
}