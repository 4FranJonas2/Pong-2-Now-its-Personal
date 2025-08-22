#pragma once

#include "raylib.h"

namespace player
{
	struct Player
	{
		Rectangle playerRec;
		Color playerColor;
		int playerPoints;
		int playerLives;
	};
	void Initplayer(Player& player);
	void UpdatePlayer(Player& player);
	void DrawPlayer(Player& player);
}

