#include "ball.h"

namespace pong2
{
	void InitBall(Ball& ball, float initBallPosX, float initBallPosY)
	{
		ball.ballColor = RED;
		ball.ballVel = 0.1f;

		ball.ballCircle.pos.x = (ball.initBallPosX / 2);
		ball.ballCircle.pos.y = (ball.initBallPosY / 2);
		ball.ballCircle.rad = 2.5f;
	}

	void UpdateBall(Ball& ball)
	{
	}

	void DrawBall(Ball ball)
	{
	}
}