#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>
#include "Creature.h"

class Player : public Creature
{
protected:
	int m_level{ 1 }; // initiliazing with starting level which is 1

public:
	Player(std::string name);
		
	void levelUp() ;

	int getLevel() ;
	bool hasWon() ;

	void healPlayer(int amount) ;
	void buffPlayerDamage(int amount) ;

	void writeScoreToFile(std::string Time);

};

	
#endif