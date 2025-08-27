#include "ball.h"

#include <ctime>


namespace pong2
{
	BallDir ballDir;

	void InitBall(Ball& ball)
	{
		ball.ballColor = RED;
		ball.ballVel = 0.1f;

		Vector2 ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
		Vector2 ballSpeed = { 5.0f, 4.0f };

		ball.ballVelo = ballSpeed;
		ball.ballCircle.pos.x = ballPosition.x;
		ball.ballCircle.pos.y = ballPosition.y;
		ball.ballCircle.rad = 20.0f;
		ball.ballFirstMove = true;
	}

	void UpdateBall(Ball& ball, Pong gamestats, Rectangle player1Rec)
	{
		/*ball.ballCircle.pos.y -= ball.ballVel;
		ball.ballCircle.pos.x -= ball.ballVel;*/
		int randDir = 0;

		if (IsKeyPressed(KEY_SPACE) && ball.ballFirstMove)
		{
			randDir = (GetRandomValue(1, 4));

			ball.ballFirstMove = false;

			//caso especial donde seteo una direccion random al iniciar
			switch ((BallDir)randDir)
			{
			case::pong2::BallDir::UPRIGHT:				
				ballDir = BallDir::UPRIGHT;
				break;
			case::pong2::BallDir::UPLEFT:				
				ballDir = BallDir::UPLEFT;
				break;
			case::pong2::BallDir::DOWNRIGHT:				
				ballDir = BallDir::DOWNRIGHT;
				break;
			case::pong2::BallDir::DOWNLEFT:
				ballDir = BallDir::DOWNLEFT;
				break;
			default:
				break;
			}
		}

		if (!ball.ballFirstMove)
		{
			switch ((BallDir)ballDir)
			{		
			case::pong2::BallDir::UPRIGHT:	
				ball.ballCircle.pos.y -= ball.ballVel;
				ball.ballCircle.pos.x += ball.ballVel;
				ballDir = BallDir::UPRIGHT;
				break;

			case::pong2::BallDir::UPLEFT:	
				ball.ballCircle.pos.y -= ball.ballVel;
				ball.ballCircle.pos.x -= ball.ballVel;
				ballDir = BallDir::UPLEFT;
				break;

			case::pong2::BallDir::DOWNRIGHT:	
				ball.ballCircle.pos.y += ball.ballVel;
				ball.ballCircle.pos.x += ball.ballVel;
				ballDir = BallDir::DOWNRIGHT;
				break;

			case::pong2::BallDir::DOWNLEFT:	
				ball.ballCircle.pos.y += ball.ballVel;
				ball.ballCircle.pos.x -= ball.ballVel;
				ballDir = BallDir::DOWNLEFT;
				break;

			default:
				break;
			}
		}
	}

	void DrawBall(Ball ball)
	{
		DrawCircle(ball.ballCircle.pos.x, ball.ballCircle.pos.y,
			ball.ballCircle.rad, ball.ballColor);
	}

	//void ballHitBox(Ball ball, int screenWidth, int screenHeiht, Rectangle playerRec)
	//{
	//	// Check walls collision
	//	bool IsRigthSide = ball.ballCircle.pos.x >= (screenWidth - ball.ballCircle.rad);
	//	bool IsLeftSide = ball.ballCircle.pos.x <= (ball.ballCircle.rad);
	//	bool IsTop = ball.ballCircle.pos.y <=  ball.ballCircle.rad;
	//	bool IsBottom = ball.ballCircle.pos.y >= (screenHeiht - (ball.ballCircle.rad));

	//	if (IsRigthSide)
	//	{
	//		ball.ballCircle.pos.x = (screenWidth - ball.ballRad);
	//		ball.ballDir.x *= -1.0f;
	//		player::AddPointPlayer1(player1);
	//	}
	//	else if (IsLeftSide)
	//	{
	//		ball.ballCircle.pos.x = (ball.ballRad + lineThick);
	//		ball.ballDir.x *= -1.0f;
	//		player::AddPointPlayer2(player2);
	//	}

	//	if (IsTop)
	//	{
	//		ball.ballCircle.pos.y = (gameArena.y + ball.ballRad + lineThick);
	//		ball.ballDir.y *= -1.0f;
	//	}
	//	else if (IsBottom)
	//	{
	//		ball.ballCircle.pos.y = (heigth - (ball.ballRad + lineThick));
	//		ball.ballDir.y *= -1.0f;
	//	}
	//}


}