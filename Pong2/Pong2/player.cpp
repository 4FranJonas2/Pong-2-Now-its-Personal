#include "player.h"

namespace pong2
{
	void InitPlayer(Player& player, float initPlayerPosX, float initPlayerPosY)
	{
		//default stats for player
		int playerRecWidth = 25;
		int playerRecHeight = 100;
		float defaultVel = 0.1f;

		player.playerColor = BROWN;
		player.playerLives = 3;
		player.playerPoints = 0;
		player.playerVel = defaultVel;

		player.playerRec.x = initPlayerPosX;
		player.playerRec.y = initPlayerPosY;
		player.playerRec.width = playerRecWidth;
		player.playerRec.height = playerRecHeight;
	}
	void UpdatePlayer(Player& player, KeyboardKey key1, KeyboardKey key2)
	{
		//movimiento 
		if (IsKeyDown(key2))
		{
			player.playerRec.y += player.playerVel;
		}
		if (IsKeyDown(key1))
		{
			player.playerRec.y -= player.playerVel;
		}
	}
	void DrawPlayer(Player player)
	{
		DrawRectangle(player.playerRec.x, player.playerRec.y, player.playerRec.width,
			player.playerRec.height, player.playerColor);
	}
}