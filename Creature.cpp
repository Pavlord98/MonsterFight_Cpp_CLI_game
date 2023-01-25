#include "Creature.h"

#include <iostream>
#include <string>

/// This is the base class for all of the creatures (Monsters, pets and the player)
///
/// This class contains attributes that are common to all of the creatures

Creature::Creature(std::string name, char symbol, int health, int damage, int gold)
	: m_name{ name }
	, m_symbol{ symbol }
	, m_health{ health }
	, m_damage{ damage }
	, m_gold{ gold }
	{
	}

	/// standard getter for the creature's name 
	const std::string& Creature::getName() const { return m_name; }

	/// standard getter for the creature's symbol
	///
	/// @attention this is currently left unused
	char Creature::getSymbol() const { return m_symbol; }

	/// standard getter for the creature's health
	int Creature::getHealth()	 const { return m_health; }

	/// standard getter for the creature's damage 
	int Creature::getDamage()	 const { return m_damage; }

	/// standard getter for the creature's gold 
	int Creature::getGold() const { return m_gold; }

	/// @brief function used to decrease a creature's health when attacked
	/// @param amountOfDamage equals to the damage of the attacking creature
	void Creature::reduceHealth(int amountOfDamage) { m_health -= amountOfDamage; }
	
	/// @brief function that checks if the player is alive
	/// @return a boolean corresponding to the players aliveness xD
	bool Creature::isDead() { return m_health <= 0; }

	/// function that adds gold after defeating a monster
	void Creature::addGold(int amountOfGold) { m_gold += amountOfGold; }

