#pragma once
#include <iostream>
struct Vector2D
{
	float X = 0;
	float Y = 0;
};

struct Game
{
	int W, H;
	bool gameplay = false;
	bool executable = false;
	bool login = true;
	bool difficulty = false;
	bool howToPlay = false;
	bool end = false;
};

void BackgroundWords(int initialX, int finalX, int Y);

void InitGame();

void DrawGame();

void Colisions(std::string tag1, std::string tag2);

void AllLeftLarg();

void TimeMinus(float &b);