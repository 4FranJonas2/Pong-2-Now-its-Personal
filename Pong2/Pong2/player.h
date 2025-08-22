#pragma once

#include "raylib.h"

namespace pong2
{
	struct Player
	{
		float initPlayer1PosX = 100;
		float initPlayer2PosX = 700;
		float initPlayerPosY = 225;

		Rectangle playerRec;
		Color playerColor;
		int playerPoints;
		int playerLives;
	};
	void Initplayer(Player& player, float initPlayerPosX, float initPlayerPosY);
	void UpdatePlayer(Player& player, KeyboardKey key1, KeyboardKey key2);
	void DrawPlayer(Player& player);
	void playerIsNotMoving(Player& player);
}

