#include "LoginScreen.h"
#include "conio.h" 
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

extern Game game;

void DrawPixelInConsole(int linesX_start, int linesX_end, int linesY_start, int linesY_end)
{
	for (linesY_start; linesY_start < linesY_end; linesY_start++)
	{
		FASG::WritePixelBuffer(linesX_start, linesY_start, linesX_end, linesY_start, FASG::EBackColor::Yellow);
	}
}

void DrawNameLogScreen()
{
	//W
	DrawPixelInConsole(57, 58, 4, 16);
	DrawPixelInConsole(65, 66, 4, 16);
	DrawPixelInConsole(61, 62, 13, 15);
	DrawPixelInConsole(57, 66, 15, 16);
	
	//A
	DrawPixelInConsole(70, 71, 4, 16);
	DrawPixelInConsole(78, 79, 4, 16);
	DrawPixelInConsole(70, 79, 11, 12);
	DrawPixelInConsole(70, 79, 4, 5);

	//R
	DrawPixelInConsole(83, 84, 4, 16);
	DrawPixelInConsole(83, 92, 4, 5);
	DrawPixelInConsole(83, 90, 11, 12);
	DrawPixelInConsole(91, 92, 4, 11);
	DrawPixelInConsole(91, 92, 12, 16);

	//S
	DrawPixelInConsole(96, 103, 4, 5);
	DrawPixelInConsole(96, 103, 10, 11);
	DrawPixelInConsole(96, 103, 15, 16);
	DrawPixelInConsole(102, 103, 10, 16);
	DrawPixelInConsole(96, 97, 4, 11);

	//o
	DrawPixelInConsole(87, 91, 18, 19);
	DrawPixelInConsole(87, 91, 22, 23);
	DrawPixelInConsole(87, 87, 18, 22);
	DrawPixelInConsole(91, 91, 18, 22);
	
	//n
	DrawPixelInConsole(94, 94, 18, 23);
	DrawPixelInConsole(98, 98, 18, 23);
	FASG::WritePixelBuffer(95, 19, FASG::EBackColor::Yellow);
	FASG::WritePixelBuffer(96, 20, FASG::EBackColor::Yellow);
	FASG::WritePixelBuffer(97, 21, FASG::EBackColor::Yellow);

	//t
	DrawPixelInConsole(104, 104, 18, 23);
	DrawPixelInConsole(102, 106, 18, 19);

	//h
	DrawPixelInConsole(108, 108, 18, 23);
	DrawPixelInConsole(111, 111, 18, 23);
	DrawPixelInConsole(108, 111, 20, 21);

	//e
	DrawPixelInConsole(113, 113, 18, 23);
	DrawPixelInConsole(113, 116, 18, 19);
	DrawPixelInConsole(113, 116, 22, 23);

	//S
	DrawPixelInConsole(91, 98, 24, 25);
	DrawPixelInConsole(91, 92, 24, 31);
	DrawPixelInConsole(91, 98, 30, 31);
	DrawPixelInConsole(91, 98, 35, 36);
	DrawPixelInConsole(97, 98, 30, 36);

	//T
	DrawPixelInConsole(102, 111, 24, 25);
	DrawPixelInConsole(106, 107, 24, 36);

	//A
	DrawPixelInConsole(115, 116, 24, 36);
	DrawPixelInConsole(115, 124, 32, 33);
	DrawPixelInConsole(115, 124, 24, 25);
	DrawPixelInConsole(123, 124, 24, 36);

	//R
	DrawPixelInConsole(128, 129, 24, 36);
	DrawPixelInConsole(128, 137, 24, 25);
	DrawPixelInConsole(128, 135, 31, 32);
	DrawPixelInConsole(136, 137, 24, 31);
	DrawPixelInConsole(136, 137, 32, 36);

	//S
	DrawPixelInConsole(141, 148, 24, 25);
	DrawPixelInConsole(141, 142, 24, 31);
	DrawPixelInConsole(141, 148, 30, 31);
	DrawPixelInConsole(147, 148, 30, 36);
	DrawPixelInConsole(141, 148, 35, 36);
}

void BackgroundWords(int initialX, int finalX, int Y)
{
	for (initialX; initialX <= finalX; initialX++)
	{
		FASG::WritePixelBuffer(initialX, Y, FASG::EBackColor::LightWhite);
	}
}

void LogScreen()
{	
	DrawNameLogScreen();
	
	BackgroundWords(79, 121, 41);
	BackgroundWords(92, 108, 46);

	FASG::WriteStringBuffer(41,FASG::EAligned::CENTER,"Presione cualquier tecla para continuar", FASG::EForeColor::Yellow);
	FASG::WriteStringBuffer(46, FASG::EAligned::CENTER, "X para cerrar", FASG::EForeColor::Yellow);

	
	
	FASG::RenderFrame();

	char LoginScreenChar = toupper(_getch());

	if (LoginScreenChar == 'X')
	{
		game.executable = true;
		game.gameplay = true;
	}	
}