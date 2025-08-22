#include "player.h"

namespace player
{

	void Initplayer(Player& player)
	{
		//default stats for player
		float initPlayer1PosX = 100;
		float initPlayer1PosY = 225;

		float initPlayer2PosX = 225;
		float initPlayer2PosY = 225;

		int playerRecWidth = 50;
		int playerRecHeight = 100;

		player.playerColor = BROWN;
		player.playerLives = 3;
		player.playerPoints = 0;

		player.playerRec.x = initPlayer1PosX;
		player.playerRec.y = initPlayer1PosY;
		player.playerRec.width = playerRecWidth;
		player.playerRec.height = playerRecHeight;



	}
	void UpdatePlayer(Player& player)
	{
	}
	void DrawPlayer(Player& player)
	{
	}
}