Game: MonsterFight.o Scoreboard.o Player.o Pet.o Monster.o GameMechanics.o Dog.o Crow.o Creature.o Cat.o ASCII_art.o
	g++ MonsterFight.o Scoreboard.o Player.o Pet.o Monster.o GameMechanics.o Dog.o Crow.o Creature.o Cat.o ASCII_art.o -o Game

MonsterFight.o: MonsterFight.cpp
	g++ -c MonsterFight.cpp 

Scoreboard.o: Scoreboard.cpp
	g++ -c Scoreboard.cpp 

Player.o: Player.cpp
	g++ -c Player.cpp 

Pet.o: Pet.cpp
	g++ -c Pet.cpp 

Monster.o: Monster.cpp
	g++ -c Monster.cpp

GameMechanics.o: GameMechanics.cpp
	g++ -c GameMechanics.cpp 
	
Dog.o: Dog.cpp
	g++ -c Dog.cpp 
	
Crow.o: Crow.cpp
	g++ -c Crow.cpp 
	
Creature.o: Creature.cpp
	g++ -c Creature.cpp 
	
Cat.o: Cat.cpp
	g++ -c Cat.cpp 

ASCII_art.o: ASCII_art.cpp
	g++ -c ASCII_art.cpp  

clean:
	rm *.o