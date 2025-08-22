#pragma once

#include "raylib.h"

namespace pong2
{
	struct Circle
	{
		Vector2 pos;
		float rad;
	};

	struct Ball
	{
		float initBallPosX = GetScreenWidth();
		float initBallPosY = GetScreenHeight();

		Circle ballCircle;
		Color ballColor;
		float ballVel;
	};
	void InitBall(Ball& ball, float initBallPosX, float initBallPosY);
	void UpdateBall(Ball& ball);
	void DrawBall(Ball ball);
}


