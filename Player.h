#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Creature.h"

class Player : public Creature
{
protected:
	int m_level{ 1 }; // initiliazing with starting level which is 1

public:
	Player(std::string name)
		: Creature{ name, '@', 10, 1, 0 } // '@' is always the players symbol, health starts with 10, damage at 1 and gold at 0
	{
	}

	void levelUp() // leveling up results in an incearse in damage by one
	{
		++m_level;
		++m_damage;
	}

	int getLevel() { return m_level; }
	bool hasWon() { return m_level >= 20; } // the goal is reaching level 20

	void healPlayer(int amount) { ++m_health; }
	void buffPlayerDamage(int amount) { ++m_damage; }


};

#endif