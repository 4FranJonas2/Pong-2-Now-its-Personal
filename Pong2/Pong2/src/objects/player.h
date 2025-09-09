#pragma once

#include "raylib.h"

#include "../utilities.h"

namespace pong2
{
	struct Player
	{
		float initPlayer1PosX = 10;
		float initPlayer2PosX = 775;

		Rectangle playerRec;
		Color playerColor;
		int playerPoints;
		int playerLives;
		float playerVel;
	};

	void InitPlayer(Player& player, float initPlayerPosX);
	void UpdatePlayer(Player& player, KeyboardKey key1, KeyboardKey key2);
	void CheckPlayerPoints(int playerpoints, int player2Points, SceneStatus& gameStatus);
	void DrawPlayer(Player player);
}

