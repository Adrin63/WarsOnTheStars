#pragma once

//Dificultad
void Difficulty();

//Dificultades del juego
enum Diff
{
	INMORTAL, NORMAL, ONE
};

//Setter para enviar la dificultad del juego
Diff envDifficulty();