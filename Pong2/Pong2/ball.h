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

		Vector2 ballSpeed;
		Circle ballCircle;
		Color ballColor;
		float ballVel;
		int frameCounter;
	};

	void InitBall(Ball& ball);
	void UpdateBall(Ball& ball);
	bool CheckCollisionBallPlayer(Ball& ball, Rectangle playerRec, Color& playerColor);
	void CheckCollisionBallArena(Ball& ball, int player1Points, int player2Points);
	void DrawBall(Ball& ball);
}


