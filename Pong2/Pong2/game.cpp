#include "game.h"

#include <iostream>

using namespace std;

namespace pong2
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	void GamePlay()
	{
		Player player1;
		Player player2;
		Ball ball;

		InitWindow(screenWidth, screenHeight, "PONG2 Ahora es personal");

		Init(player1, player2);

		while (!WindowShouldClose())
		{
			Update(player1, player2);

			BeginDrawing();

			ClearBackground(BLACK);
			Draw(player1, player2);

			EndDrawing();
		}

		CloseWindow();
	}

	void Init(Player& player1, Player& player2)
	{
		InitPlayer(player1, player1.initPlayer1PosX, player1.initPlayerPosY);
		InitPlayer(player2, player2.initPlayer2PosX, player2.initPlayerPosY);
	}

	void Input()
	{

	}

	void Update(Player& player1, Player& player2)
	{
		UpdatePlayer(player1, KEY_W, KEY_S);
		UpdatePlayer(player2, KEY_UP, KEY_DOWN);
	}

	void Draw(Player player1, Player player2)
	{
		DrawPlayer(player1);
		DrawPlayer(player2);
	}
}