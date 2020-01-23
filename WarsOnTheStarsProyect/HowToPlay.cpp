#include "HowToPlay.h" 
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include <conio.h>

extern Game game;

void HowToPlay()
{

        if (FASG::IsKeyPressed('X'))
        {
            game.howToPlay = false;
        }

    FASG::WriteSpriteBuffer(89, 5, FASG::Sprite("Controles.txt"));

    FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "WASD MOVIMIENTO", FASG::EForeColor::LightWhite);
    FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "J DISPARAR", FASG::EForeColor::LightWhite);
    FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "P PAUSAR", FASG::EForeColor::LightWhite);

    FASG::WriteStringBuffer(55, FASG::EAligned::CENTER, "X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
}