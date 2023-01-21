#include <time.h>
#include <vector>
#include <fstream>
#include <algorithm>

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
	std::ifstream scr{"ScoreLog.txt"};

	if (!scr)
    {
        // Print an error and exit
        std::cerr << "ScoreLog.txt could not be opened for reading!\n";
        return ;
    }

	
    struct scoreEntry
	{
		std::string name;
		int gold;
		char w;
		std::string date;
	};

	/*	
	std::istream& operator>>(std::istream& is, scoreEntry& s)
	{
    	return scr >> s.name >> s.gold >> s.w >> s.date;	
	}
	*/

	std::vector<scoreEntry> scoreEntries;
	scoreEntry s;
	while (scr)
	{
		scr >> s.name >> s.gold >> s.w >> s.date;
		scoreEntries.push_back(s);
	}

	std::sort(scoreEntries.begin(),
			  scoreEntries.end(),
			  [](const scoreEntry& s1, const scoreEntry& s2) {return s1.gold > s2.gold;});
	
	for (const auto i: scoreEntries)
	{
		std::cout << "Player " << i.name << " obtained "<< i.gold << " Date and time: "<< i.date <<'\n';
	}
    

	
}