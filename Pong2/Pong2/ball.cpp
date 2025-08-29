#include "ball.h"

#include <ctime>

namespace pong2
{
	BallDir ballDir;

	void InitBall(Ball& ball)
	{
		Vector2 ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
		Vector2 ballSped = { 0.2f, 0.1f };
		ball.ballColor = RED;
		ball.ballSpeed = ballSped;
		ball.ballCircle.pos.x = ballPosition.x;
		ball.ballCircle.pos.y = ballPosition.y;
		ball.ballCircle.rad = 20.0f;
		ball.gamePause = true;
		ball.frameCounter = 0;
	}

	void UpdateBall(Ball& ball)
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			ball.gamePause = !ball.gamePause;
		}
		if (!ball.gamePause)
		{
			ball.ballCircle.pos.x += ball.ballSpeed.x;
			ball.ballCircle.pos.y += ball.ballSpeed.y;	
		}
		else
		{
			ball.frameCounter++;
		}
	}

	void CheckCollisionBallPlayer(Ball& ball, Rectangle playerRec)
	{
		//chequeo de rebote con los bordes de la arena
			//rebote derecho e izquierdo bas abajo
		if (ball.ballCircle.pos.x >= ((playerRec.width / 2) - ball.ballCircle.rad))
		{
			ball.ballSpeed.x *= -1.0f;
		}
		if (ball.ballCircle.pos.x <= ball.ballCircle.rad + (playerRec.width / 2))
		{
			ball.ballSpeed.x *= -1.0f;
		}
		//rebote inferior y superior
		if ((ball.ballCircle.pos.y >= ((playerRec.height / 2) - ball.ballCircle.rad))
			|| (ball.ballCircle.pos.y <= ball.ballCircle.rad + (playerRec.height / 2)))
		{
			ball.ballSpeed.y *= -1.0f;
		}
	}

	void CheckCollisionBallArena(Ball& ball, int player1Points, int player2Points)
	{
		//chequeo de rebote con los bordes de la arena
			//rebote derecho e izquierdo bas abajo
		if (ball.ballCircle.pos.x >= (GetScreenWidth() - ball.ballCircle.rad))
		{
			ball.ballSpeed.x *= -1.0f;
			player2Points++;
		}
		if (ball.ballCircle.pos.x <= ball.ballCircle.rad)
		{
			ball.ballSpeed.x *= -1.0f;
			player1Points++;
		}
		//rebote inferior y superior
		if ((ball.ballCircle.pos.y >= (GetScreenHeight() - ball.ballCircle.rad))
			|| (ball.ballCircle.pos.y <= ball.ballCircle.rad))
		{
			ball.ballSpeed.y *= -1.0f;
		}
	}

	void DrawBall(Ball ball)
	{
		DrawCircle(ball.ballCircle.pos.x, ball.ballCircle.pos.y,
			ball.ballCircle.rad, ball.ballColor);
		if (ball.gamePause && ((ball.frameCounter / 30) % 2))
		{
			DrawText("PAUSED", 350, 200, 20, GRAY);
		}
	}
}