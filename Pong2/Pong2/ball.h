#pragma once

#include "raylib.h"

#include "utilities.h"

namespace pong2
{
	struct Circle
	{
		Vector2 pos;
		float rad;
	};

	enum class BallDir
	{
		UPRIGHT=1,
		UPLEFT,
		DOWNRIGHT,
		DOWNLEFT
	};

	struct Ball
	{
		float initBallPosX = GetScreenWidth();
		float initBallPosY = GetScreenHeight();

		//BallDir ballDir;
		Vector2 ballSpeed;
		Circle ballCircle;
		Color ballColor;
		float ballVel;
		bool gamePause;
	};

	void InitBall(Ball& ball);
	void UpdateBall(Ball& ball, Pong gamestats, Rectangle playerRec);
	void DrawBall(Ball ball);
	//void ballHitBox(Ball ball, int screenWidth, int screenHeiht);

}


