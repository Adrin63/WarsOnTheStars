#include "HowToPlay.h" 
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include <conio.h>

//Variables de game para determinar el punto donde estas del juego
extern Game game;

void HowToPlay()
{
   //Poner Graficamente los controles
   FASG::WriteSpriteBuffer(89, 5, FASG::Sprite("Controles.txt"));
   

   //Escribir controles
   FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "1 JUGADOR", FASG::EForeColor::Black);
   FASG::WriteStringBuffer(23, FASG::EAligned::CENTER, "WASD MOVIMIENTO      J DISPARO      K MISIL", FASG::EForeColor::LightWhite);
   FASG::WriteStringBuffer(26, FASG::EAligned::CENTER, "P PARA PAUSAR", FASG::EForeColor::LightWhite);
   FASG::WriteStringBuffer(35, FASG::EAligned::CENTER, "2 JUGADORES", FASG::EForeColor::Black);
   FASG::WriteStringBuffer(38, FASG::EAligned::CENTER, "WASD MOVIMIENTO     C DISPARO, 1 JUGADOR ", FASG::EForeColor::LightWhite);
   FASG::WriteStringBuffer(41, FASG::EAligned::CENTER, "IJKL MOVIMIENTO     9 DISPARO, 2 JUGADOR", FASG::EForeColor::LightWhite);
   FASG::WriteStringBuffer(44, FASG::EAligned::CENTER, "P PARA PAUSAR", FASG::EForeColor::LightWhite);
   FASG::WriteStringBuffer(55, FASG::EAligned::CENTER, "X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);

   //Subrayar los controles
   BackgroundWordsHowToPlay(128, 172, 35);
   BackgroundWordsHowToPlay(128, 172, 20);
    
   FASG::RenderFrame();

   //Volver al Menu
   if (FASG::IsKeyPressed('X'))
   {
       game.howToPlay = false;
   }
}

void BackgroundWordsHowToPlay(int a, int b, int c)
{
    for (a; a <= b; a++)
    {
        FASG::WritePixelBuffer(a, c, FASG::EBackColor::White);
    }
}