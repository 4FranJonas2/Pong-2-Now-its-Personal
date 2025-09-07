#pragma once

#include "raylib.h"

//#include "utilities.h"

namespace pong2
{
	struct Player
	{
		float initPlayer1PosX = 10;
		float initPlayer2PosX = 775;
		float initPlayerPosY = 225;

		Rectangle playerRec;
		Color playerColor;
		int playerPoints;
		int playerLives;
		float playerVel;
	};
	void InitPlayer(Player& player, float initPlayerPosX, float initPlayerPosY);
	void UpdatePlayer(Player& player, KeyboardKey key1, KeyboardKey key2);
	void DrawPlayer(Player player);
}

