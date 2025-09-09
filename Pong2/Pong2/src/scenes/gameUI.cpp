#include "gameUI.h"

namespace pong2
{
	
	void PrintScore(int playerScore, int posX)
	{
		DrawText(TextFormat("%i",playerScore), posX, 200, 60, GRAY);
	}
	void PrintArena(int screenWidth, int screenHeight)
	{
		DrawLine((screenWidth / 2), 0, (screenWidth / 2), screenHeight, GRAY);
	}
	void PrintPause()
	{
		int textFont = 30;
		Color textColor = WHITE;

		DrawText("GAME PAUSE", 305, 100, textFont, textColor);
		DrawText("Press SPACEBAR", 265, 300, textFont, textColor);
		DrawText("To Continue", 310, 350, textFont, textColor);
	}
	void PrintEndMatchMsg(int player1Score, int player2Score, SceneStatus& gameScene)
	{
		int textFont = 30;
		Color textColor = WHITE;
		int winScore = 3;
		int auxPosXPlayer1 = 100;
		int auxPosXPlayer2 = 470;
		int auxPosY = 100;

		if (player1Score == winScore)
		{
			DrawText("Player 1 WINS ", auxPosXPlayer1, auxPosY, textFont, textColor);
			DrawText("Player 2  LOSE ", auxPosXPlayer2, auxPosY, textFont, textColor);
		}

		if (player2Score == winScore)
		{
			DrawText("Player 1 LOSE ", auxPosXPlayer1, auxPosY, textFont, textColor);
			DrawText("Player 2  WINS ", auxPosXPlayer2, auxPosY, textFont, textColor);
		}
	}
}