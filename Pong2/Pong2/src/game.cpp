#include "game.h"

#include <iostream>

using namespace std;

namespace pong2
{
	bool gamePause = true;

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
		InitPlayer(player1, player1.initPlayer1PosX);
		InitPlayer(player2, player2.initPlayer2PosX);
		InitBall(ball);
	}

	void Input()
	{

	}

	void Update(Player& player1, Player& player2, Pong& gameStats, Ball& ball)
	{
		bool ballIsHitP1;
		bool ballIsHitP2;
		

		if (IsKeyPressed(KEY_SPACE))
		{
			gamePause = false;
		}
		if (!gamePause)
		{
			UpdatePlayer(player1, KEY_W, KEY_S);
			UpdatePlayer(player2, KEY_UP, KEY_DOWN);
			CheckCollisionBallArena(ball, player1.playerPoints, player2.playerPoints);
			ballIsHitP1 = CheckCollisionBallPlayer(ball, player1.playerRec, player1.playerColor);
			ballIsHitP2 = CheckCollisionBallPlayer(ball, player2.playerRec, player2.playerColor);
			UpdateBall(ball);
		
			if (ballIsHitP1 or ballIsHitP2)
			{
				ball.ballColor = YELLOW;
			}
			
		}
	}

	void Draw(Player player1, Player player2, Ball& ball)
	{
		DrawPlayer(player1);
		DrawPlayer(player2);
		DrawBall(ball);
	}
}