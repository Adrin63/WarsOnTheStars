#include "LoginScreen.h"
#include "conio.h" 
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

extern Game game;

/*
void Tool(int weight_start, int weight_end, int height_start, int height_end)
{
	for (int w = weight_start; w < weight_end; w++)
	{
		for (int h = height_start; h < height_end; h++)
		{
			std::cout << "_\n";
			
		}
		std::cout << "\n";
	}
}

void LogoWS()
{
	




	for (int w = 0; w < game.W; w++)
	{
		for (int h = 0; h < game.H; h++)
		{
		
		}
	}
}
*/

void LogScreen()
{	
	//LogoWS();
	FASG::WriteStringBuffer(41,FASG::EAligned::CENTER,"Presione cualquier tecla para continuar", FASG::EForeColor::White);
	FASG::WriteStringBuffer(46, FASG::EAligned::CENTER, "X para cerrar", FASG::EForeColor::White);

	FASG::RenderFrame();

	char LoginScreenChar = toupper(_getch());

	if (LoginScreenChar == 'X')
	{
		game.executable = true;
		game.gameplay = true;
	}	

}

/*void DrawMap()
{
	for (int fila = 0; fila < MAP_H; fila++)
	{
		int columnaConsola = 0;
		for (int columna = XCam; columna < XCam + W; columna++)
		{
			if (Map[fila][columna] == 'X')
				FASG::WritePixelBuffer(columnaConsola, fila, FASG::EBackColor::LightGreen);

			columnaConsola++;
		}
	}
}




void CreatePlatform(int x, int y, int width)
{
	for (int columna = x; columna < x + width; columna++)
	{
		if (InMapRange(columna, y))
			Map[y][columna] = 'X';
	}
}

void CreateStepPlatform(int x, int y, int step, int numStairs, int gap, int width)
{
	for (int stair = 0; stair < numStairs; stair++)
	{
		CreatePlatform(x + (gap + width) * stair, y + (step * stair), width);
	}
}*/