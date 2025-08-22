#include "player.h"

namespace pong2
{
	void Initplayer(Player& player, float initPlayerPosX, float initPlayerPosY)
	{
		//default stats for player
		int playerRecWidth = 25;
		int playerRecHeight = 100;

		player.playerColor = BROWN;
		player.playerLives = 3;
		player.playerPoints = 0;

		player.playerRec.x = initPlayerPosX;
		player.playerRec.y = initPlayerPosY;
		player.playerRec.width = playerRecWidth;
		player.playerRec.height = playerRecHeight;
	}
	void UpdatePlayer(Player& player, KeyboardKey key1, KeyboardKey key2)
	{
		//movimiento 
		if (IsKeyDown(key1))
		{
			player.initPlayerPosY++;
		}
		else if (IsKeyDown(key2))
		{
			player.initPlayerPosY--;
		}
		else
		{
			playerIsNotMoving(player);
		}
	}
	void DrawPlayer(Player& player)
	{
		DrawRectangle(player.playerRec.x, player.playerRec.y, player.playerRec.width,
						player.playerRec.height, player.playerColor);
	}

	void playerIsNotMoving(Player& player)
	{
		player.initPlayerPosY = player.initPlayerPosY;
	}
}