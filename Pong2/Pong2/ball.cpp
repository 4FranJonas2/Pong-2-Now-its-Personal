#include "ball.h"

#include <ctime>


namespace pong2
{
	BallDir ballDir;

	void InitBall(Ball& ball)
	{
		ball.ballColor = RED;
		ball.ballVel = 0.1f;

		ball.ballCircle.pos.x = (800 / 2);
		ball.ballCircle.pos.y = (450 / 2);
		ball.ballCircle.rad = 20.0f;
		ball.ballFirstMove = true;
	}

	void UpdateBall(Ball& ball, Pong gamestats)
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

	void ballHitBox(Ball ball, int screenWidth, int screenHeiht)
	{

	}


}