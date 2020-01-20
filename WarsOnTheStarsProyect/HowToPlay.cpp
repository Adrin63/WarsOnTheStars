#include "HowToPlay.h" 
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include <conio.h>

extern Game game;

void HowToPlay()
{
    bool ComJug = false;

    if (!ComJug)
    {
        char ComJugChar = toupper(_getch());

        if (ComJugChar == 'X')
        {
            game.executable = true;
            game.howToPlay = false;
        }
    }
    FASG::WriteSpriteBuffer(89, 5, FASG::Sprite("Controles.txt"));

    FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "WASD = movimiento", FASG::EForeColor::LightWhite);
    FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "J = disparar.", FASG::EForeColor::LightWhite);
    FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "P = pausar.", FASG::EForeColor::LightWhite);

    FASG::WriteStringBuffer(55, FASG::EAligned::CENTER, "Pulsa X para volver al menu", FASG::EForeColor::LightWhite);
}