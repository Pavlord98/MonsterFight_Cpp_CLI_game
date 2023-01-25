#ifndef MONSTER_H
#define MONSTER_H

#include <array>
#include "Creature.h"
#include <cstdlib> // for generating random numbers
#include <ctime> // for time

int getRandomNumber(int min, int max);


class Monster : public Creature
{
public:
	enum class Type // types of monsters in this game
	{
		dragon,
		orc,
		slime,
		max_types
	};

private:
	static const Creature& getDefaultCreature(Type type) // lookup table for monster atributes 
	{
		// array with elements of type Creature and length of max_types
		static const std::array <Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
		{	{ "dragon", 'D', 20, 4, 100 },
			{ "orc", 'o', 4, 2, 25 },
			{ "slime", 's', 1, 1, 10 } }
		};

		return monsterData.at(static_cast<std::size_t>(type));
	}

public:
	Monster(Type type);

	
	static Monster getRandomMonster()
	{
		int num{ getRandomNumber(0, static_cast<int>(Type::max_types) - 1) };
		return Monster{ static_cast<Type>(num) };
	}
};

#endif