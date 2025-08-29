#include "ball.h"

#include <ctime>
#include <math.h>

namespace pong2
{
	BallDir ballDir;

	void InitBall(Ball& ball)
	{
		Vector2 ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
		Vector2 ballSped = { 0.1f, 0.1f };
		ball.ballColor = RED;
		ball.ballSpeed = ballSped;
		ball.ballCircle.pos.x = ballPosition.x;
		ball.ballCircle.pos.y = ballPosition.y;
		ball.ballCircle.rad = 20.0f;
		ball.frameCounter = 0;
	}

	void UpdateBall(Ball& ball)
	{	
			ball.ballCircle.pos.x += ball.ballSpeed.x * 0.2f;
			ball.ballCircle.pos.y += ball.ballSpeed.y * 0.2f;
	}

	bool CheckCollisionBallPlayer(Ball& ball, Rectangle playerRec, Color& playerColor)
	{
		if (ball.ballCircle.pos.x + ball.ballCircle.rad >= playerRec.x &&     //izq
			ball.ballCircle.pos.x - ball.ballCircle.rad <= playerRec.x + playerRec.width   // derech
			
			)

		{
			playerColor = WHITE;
			ball.ballColor = YELLOW;
			return true;
			/*ball.ballSpeed.x *= -1.0f;
			ball.ballSpeed.y *= -1.0f;*/
			//ball.ballCircle.pos.x = ball.ballCircle.pos.x + ball.ballCircle.rad /*(playerRec.width / 2)*/;
			//ball.ballCircle.pos.y = ball.ballCircle.pos.y + ball.ballCircle.rad /*(playerRec.height / 2)*/;
		}
		else
		{
			playerColor = BROWN;
			ball.ballColor = RED;
			return false;
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

	void DrawBall(Ball& ball)
	{
		DrawCircle(ball.ballCircle.pos.x, ball.ballCircle.pos.y,
			ball.ballCircle.rad, ball.ballColor);
	}
}