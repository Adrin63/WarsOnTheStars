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
   FASG::WriteStringBuffer(55, FASG::EAligned::CENTER, "X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
   FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "WASD MOVIMIENTO", FASG::EForeColor::LightWhite);
   FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "J DISPARAR", FASG::EForeColor::LightWhite);
   FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "P PAUSAR", FASG::EForeColor::LightWhite);

   //Subrayar los controles
   BackgroundWords(141, 159, 20);
   BackgroundWords(143, 156, 25);
   BackgroundWords(144, 155, 30);
    
   FASG::RenderFrame();

   //Volver al Menu
   if (FASG::IsKeyPressed('X'))
   {
       game.howToPlay = false;
   }
}