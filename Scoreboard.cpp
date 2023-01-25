#include "Scoreboard.h"

#include <time.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include "ASCII_art.h"

const std::string currentDateTime() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void printScoreboard()
{
	// reading in the scores
    std::ifstream scr{"ScoreLog.txt"};

	if (!scr)
    {
        // Print an error and exit
        std::cerr << "ScoreLog.txt could not be opened for reading!\n";
        return ;
    }

	// creating a struct to hold an entire entry
    struct scoreEntry
	{
		std::string name;
		int gold;
		char w;
		std::string date;
	};

    // creating a vector to store entries
	std::vector<scoreEntry> scoreEntries;
	scoreEntry s;

    // reading in the enrties
	while (scr)
	{
		scr >> s.name >> s.gold >> s.w >> s.date;
		scoreEntries.push_back(s);
	}

    // sorting entries based on gold obtained
	std::sort(scoreEntries.begin(),
			  scoreEntries.end(),
			  [](const scoreEntry& s1, const scoreEntry& s2) {return s1.gold > s2.gold;});
	
    
    art::drawLines();
    art::drawScoreboard();
    int num {1};
    // printing the sorted scoreboard to screen
	for (const auto i: scoreEntries)
	{
        std::cout << num++ << ". " <<"Player " << i.name << " obtained "<< i.gold << ";      Date and time: "<< i.date <<'\n';
        if (num>10) {return;}
	}
}