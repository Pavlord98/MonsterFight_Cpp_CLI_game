#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

class Creature
{
protected:
	std::string m_name;
	char m_symbol{};
	int m_health{};
	int m_damage{};
	int m_gold{};

public:
	Creature(std::string name, char symbol='?', int health=1, int damage=1, int gold=0)
		: m_name{ name }
		, m_symbol{ symbol }
		, m_health{ health }
		, m_damage{ damage }
		, m_gold{ gold }
	{
	}

	const std::string& getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth()	 const { return m_health; }
	int getDamage()	 const { return m_damage; }
	int getGold() const { return m_gold; }

	void reduceHealth(int amountOfDamage) { m_health -= amountOfDamage; }
	bool isDead() { return m_health <= 0; }
	void addGold(int amountOfGold) { m_gold += amountOfGold; }
};

#endif