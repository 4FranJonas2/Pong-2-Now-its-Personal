#pragma once

#include "raylib.h"
#include "..\utilities.h"
#include <string>

namespace pong2
{
	void PrintScore(int playerScore, int posX);
	void PrintArena(int screenWidth, int screenHeight);
	void PrintPause();
}