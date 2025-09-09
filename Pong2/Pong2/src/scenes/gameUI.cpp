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
}