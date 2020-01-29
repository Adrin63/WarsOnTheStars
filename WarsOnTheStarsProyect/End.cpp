#include "End.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"	

//Variables de game para determinar el punto donde estas del juego
extern Game game;

//Hacer que aparezcan y desaparezcan las letras en pantalla
bool onDead = true;
float const DissapearCDDead = 1.f;
float coolDownDead = DissapearCDDead;

void GameOver()
{
	//Hacer que aparezcan y desaparezcan las letras en pantalla
	TimeMinus(coolDownDead);

	if (onDead)
	{
		FASG::WriteSpriteBuffer(90, 10, FASG::Sprite("GameOver.txt"));
		FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "PULSA C PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
	}

	//Hace aparecer y desaparecer el sprite
	if (coolDownDead <= 0)
	{
		switch (onDead)
		{
		case true:
			onDead = false;
			break;
		case false:
			onDead = true;
			break;
		}
		coolDownDead = DissapearCDDead;
	}

	FASG::RenderFrame();

	//Volver al menu
	if (FASG::IsKeyPressed('C'))
	{
		game.login = true;
		game.end = false;
	}
}
