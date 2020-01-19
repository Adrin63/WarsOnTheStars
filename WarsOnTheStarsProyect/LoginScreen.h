#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

struct Logear
{
	Vector2D pos;
	FASG::Sprite dou = FASG::Sprite("LS.txt");
};

void LogScreen();
//void InitLogScreen();