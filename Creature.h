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
	Creature(std::string name, char symbol='?', int health=1, int damage=1, int gold=0);
		

	/// standard getter for the creature's name 
	const std::string& getName() const ;

	/// standard getter for the creature's symbol
	///
	/// @attention this is currently left unused
	char getSymbol() const ;

	/// standard getter for the creature's health
	int getHealth()	 const ;

	/// standard getter for the creature's damage 
	int getDamage() const;

	/// standard getter for the creature's gold 
	int getGold() const ;

	/// @brief function used to decrease a creature's health when attacked
	/// @param amountOfDamage equals to the damage of the attacking creature
	void reduceHealth(int amountOfDamage) ;
	
	/// @brief function that checks if the player is alive
	/// @return a boolean corresponding to the players aliveness xD
	bool isDead();

	/// function that adds gold after defeating a monster
	void addGold(int amountOfGold);
};

#endif