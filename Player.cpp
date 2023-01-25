#include "Player.h"

#include <string>
#include <fstream>
#include "Creature.h"

Player::Player(std::string name) :
	Creature{ name, '@', 10, 1, 0 } // '@' is always the players symbol, health starts with 10, damage at 1 and gold at 0
	{
	}

void Player::levelUp() {++m_level; ++m_damage;}

int Player::getLevel() {return m_level;}
bool Player::hasWon() {return m_level >= 20;} 

void Player::healPlayer(int amount) { ++m_health; };
void Player::buffPlayerDamage(int amount) { ++m_damage; };

void Player::writeScoreToFile(std::string Time)
{
		std::ofstream outf;
		outf.open("ScoreLog.txt", std::ios_base::app);

		if (!outf)
    	{
        	// Print an error and exit
        	std::cerr << "ScoreLog.txt could not be opened for writing!\n";
        	return ;
    	}

		char victory = (hasWon()) ? 'W' : 'L';
		outf << m_name << " " <<  " " << m_gold << " " << victory << " " << Time << '\n';
};