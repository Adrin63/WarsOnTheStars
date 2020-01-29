#pragma once

//Dificultad
void Difficulty();

//Dificultades del juego
enum Diff
{
	INMORTAL, NORMAL, ONE
};

//Cantidad de jugadores
enum QuantityPlayers
{
	ONEPLAYER, TWOPLAYERS
};

//Setter para enviar la dificultad del juego
Diff envDifficulty();

QuantityPlayers envQuantityPlayers();
