#include "ball.h"

#include <iostream>

#include <ctime>
#include <math.h>

namespace pong2
{
	BallDir ballDir;

	void InitBall(Ball& ball)
	{
		float initBallPosX = GetScreenWidth();
		float initBallPosY = GetScreenHeight();

		Vector2 ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
		Vector2 ballSped = { 0.1f, 0.1f };

		//ball.ballSize = 
		ball.ballColor = ORANGE;
		ball.ballSpeed = ballSped;
		ball.ballCircle.pos.x = ballPosition.x;
		ball.ballCircle.pos.y = ballPosition.y;
		ball.ballCircle.rad = 15.0f;
		ball.frameCounter = 0;
	}

	void UpdateBall(Ball& ball)
	{	
			ball.ballCircle.pos.x += ball.ballSpeed.x * 0.2f;
			ball.ballCircle.pos.y += ball.ballSpeed.y * 0.2f;
	}

	bool CheckCollisionBallPlayer(Ball& ball, Rectangle playerRec, Color& playerColor)
	{
		if (ball.ballCircle.pos.x + ball.ballCircle.rad >= playerRec.x &&  //izquierda
			ball.ballCircle.pos.x - ball.ballCircle.rad <= playerRec.x + playerRec.width && //derecha
			ball.ballCircle.pos.y + ball.ballCircle.rad >= playerRec.y && //arriba
			ball.ballCircle.pos.y - ball.ballCircle.rad <= playerRec.y + playerRec.height) //abajo
		{
			//golpe por derecha
			if (ball.ballCircle.pos.x - ball.ballCircle.rad > playerRec.x + playerRec.width)
			{
				ball.ballCircle.pos.x = playerRec.x + ball.ballCircle.rad + playerRec.width;
			}

			//golpe por izquierda
			if (ball.ballCircle.pos.x + ball.ballCircle.rad < playerRec.x)
			{
				ball.ballCircle.pos.x = playerRec.x - ball.ballCircle.rad;
			}

			//golpe por arriba
			if (ball.ballCircle.pos.y - ball.ballCircle.rad < playerRec.y)
			{
				ball.ballCircle.pos.y = playerRec.y - ball.ballCircle.rad;
			}

			//golpe por abajo
			if (ball.ballCircle.pos.y + ball.ballCircle.rad > playerRec.y + playerRec.height)
			{
				ball.ballCircle.pos.y = playerRec.y + playerRec.height + ball.ballCircle.rad;
			}

			ball.ballSpeed.x *= -1.0f;
			ball.ballSpeed.y *= -1.0f;

			return true;
		}

		else
		{
			return false;
		}
	}

	void CheckCollisionBallArena(Ball& ball, int& player1Points, int& player2Points)
	{
		//chequeo de rebote con los bordes de la arena
		//rebote derecho e izquierdo bas abajo
		if (ball.ballCircle.pos.x >= (GetScreenWidth() - ball.ballCircle.rad))
		{
			ball.ballCircle.pos.x = GetScreenWidth() - ball.ballCircle.rad;
			ball.ballSpeed.x *= -1.0f;
			player2Points++;

			std::cout << "player   2 points: " << player2Points << std::endl;
		}

		if (ball.ballCircle.pos.x <= ball.ballCircle.rad)
		{
			ball.ballCircle.pos.x = ball.ballCircle.rad;
			ball.ballSpeed.x *= -1.0f;
			player1Points++;
			std::cout << "player   1 points: " << player1Points << std::endl;
		}

		//rebote inferior y superior
		if (ball.ballCircle.pos.y >= (GetScreenHeight() - ball.ballCircle.rad))
		{
			ball.ballCircle.pos.y = (GetScreenHeight() - ball.ballCircle.rad);
			ball.ballSpeed.y *= -1.0f;
		}
		else if (ball.ballCircle.pos.y <= ball.ballCircle.rad)
		{
			ball.ballCircle.pos.y = ball.ballCircle.rad;
			ball.ballSpeed.y *= -1.0f;
		}
	}

	void DrawBall(Ball& ball)
	{
		DrawCircle(ball.ballCircle.pos.x, ball.ballCircle.pos.y,
			ball.ballCircle.rad, ball.ballColor);
	}
}