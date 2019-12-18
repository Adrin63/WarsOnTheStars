#include "Background.h";

const int MAX_INIT_STARS = 10;
int starX, starY;

char BKGMap[MAP_HEIGHT][MAP_WIDTH];

void Background()
{
	/*for (int i = 0; i < MAX_INIT_STARS; i++)
	{
		starX = rand() % MAP_WIDTH;
		starY = rand() % MAP_HEIGHT;

	}*/

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}