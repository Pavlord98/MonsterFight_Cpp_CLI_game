#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

/// This is the base class for all of the creatures (Monsters, pets and the player)
///
/// This class contains attributes that are common to all of the creatures
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

	/// standard getter for the creature's name 
	const std::string& getName() const { return m_name; }

	/// standard getter for the creature's symbol
	///
	/// @attention this is currently left unused
	char getSymbol() const { return m_symbol; }

	/// standard getter for the creature's health
	int getHealth()	 const { return m_health; }

	/// standard getter for the creature's damage 
	int getDamage()	 const { return m_damage; }

	/// standard getter for the creature's gold 
	int getGold() const { return m_gold; }

	/// @brief function used to decrease a creature's health when attacked
	/// @param amountOfDamage equals to the damage of the attacking creature
	void reduceHealth(int amountOfDamage) { m_health -= amountOfDamage; }
	
	/// @brief function that checks if the player is alive
	/// @return a boolean corresponding to the players aliveness xD
	bool isDead() { return m_health <= 0; }

	/// function that adds gold after defeating a monster
	void addGold(int amountOfGold) { m_gold += amountOfGold; }
};

#endif