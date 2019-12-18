#include "LoginScreen.h"
#include "conio.h" 
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

extern Game game;

void LogScreen()
{	
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