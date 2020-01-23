#include "Engine.h"
#include "FAriasSimpleGraphics.h"
#include "Player.h"
#include "Enemies.h"

void BackgroundWords(int initialX, int finalX, int Y)
{
	for (initialX; initialX <= finalX; initialX++)
	{
		FASG::WritePixelBuffer(initialX, Y, FASG::EBackColor::LightBlack);
	}
}


void Colisions(std::string tag1, std::string tag2)
{
	int EnemiesLit = envLitEnQuantity();
	int EnemiesMid = envMidEnQuantity();
	int EnemiesLar = envLarEnQuantity();

	bool Shoot = envShoot();

	for (int i = 0; i < EnemiesLit; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLit" +i || tag2 == "ShootPlayer" && tag1 == "enLit" +i)
		{
			ReciveLitDmg(i);
			Shoot = false;
			ReciveLitDmg(!Shoot);

		}
	}

	for (int i = 0; i < EnemiesMid; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enMed" + i || tag2 == "ShootPlayer" && tag1 == "enMed" + i)
		{

		}
	}

	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLar" + i || tag2 == "ShootPlayer" && tag1 == "enLar" + i)
		{

		}
	}
}