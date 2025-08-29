#include "game.h"

#include <iostream>

using namespace std;

namespace pong2
{
	void GamePlay()
	{
		srand(time(nullptr));
		Pong gameStats;
		Player player1;
		Player player2;
		Ball ball;

		InitWindow(gameStats.screenWidth, gameStats.screenHeight, "PONG2 Ahora es personal");

		Init(player1, player2, ball);

		while (!WindowShouldClose())
		{
			Update(player1, player2, gameStats, ball);

			BeginDrawing();

			ClearBackground(BLACK);
			Draw(player1, player2, ball);

			EndDrawing();
		}

		CloseWindow();
	}

	void Init(Player& player1, Player& player2, Ball& ball)
	{
		InitPlayer(player1, player1.initPlayer1PosX, player1.initPlayerPosY);
		InitPlayer(player2, player2.initPlayer2PosX, player2.initPlayerPosY);
		InitBall(ball);
	}

	void Input()
	{

	}

	void Update(Player& player1, Player& player2, Pong& gameStats, Ball& ball)
	{
		UpdatePlayer(player1, KEY_W, KEY_S);
		UpdatePlayer(player2, KEY_UP, KEY_DOWN);
		UpdateBall(ball);
		CheckCollisionBallArena(ball, player1.playerPoints, player2.playerPoints);
		CheckCollisionBallPlayer(ball, player1.playerRec);
		CheckCollisionBallPlayer(ball, player2.playerRec);

	}

	void Draw(Player player1, Player player2, Ball& ball)
	{
		DrawPlayer(player1);
		DrawPlayer(player2);
		DrawBall(ball);
	}
}