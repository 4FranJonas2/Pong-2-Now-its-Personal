#include "game.h"

#include <iostream>

using namespace std;

namespace pong2
{
	void GamePlay()
	{
		srand(time(nullptr));
		Pong gameStats;
		Player player1;
		Player player2;
		Ball ball;

		gameStats.gameManager = SceneManager::INITGAME;


		Init(player1, player2, ball,gameStats);

		while (!WindowShouldClose())
		{
			Update(player1, player2, gameStats, ball);

			BeginDrawing();

			ClearBackground(BLACK);
			Draw(player1, player2, ball,gameStats);

			EndDrawing();
		}

		CloseWindow();
	}

	void Init(Player& player1, Player& player2, Ball& ball, Pong& gameStats)
	{
		switch ((SceneManager)gameStats.gameManager)
		{
		case SceneManager::INITGAME:
			InitWindow(gameStats.screenWidth, gameStats.screenHeight, "PongOso");

			InitPlayer(player1, player1.initPlayer1PosX);
			InitPlayer(player2, player2.initPlayer2PosX);
			InitBall(ball);
			gameStats.gameManager = SceneManager::GAMEPAUSE;
			break;

		case SceneManager::RESETGAME:
			InitPlayer(player1, player1.initPlayer1PosX);
			InitPlayer(player2, player2.initPlayer2PosX);
			InitBall(ball);
			gameStats.gameManager = SceneManager::GAMEPLAYTWOPLAYERS;
			break;

		case SceneManager::GAMEEND:
			break;

		default:
			break;
		}

		
	}

	/*void Input()
	{

	}*/

	void Update(Player& player1, Player& player2, Pong& gameStats, Ball& ball)
	{
		switch ((SceneManager)gameStats.gameManager)
		{
		case SceneManager::INITGAME:
			break;	

		case SceneManager::GAMEMENU:
			break;

		case SceneManager::GAMEPLAYTWOPLAYERS:
			bool ballIsHitP1;
			bool ballIsHitP2;

			if (IsKeyPressed(KEY_SPACE) && gameStats.gameManager == SceneManager::GAMEPLAYTWOPLAYERS)
			{
				gameStats.gameManager = SceneManager::GAMEPAUSE;
			}

			if (gameStats.gameManager == SceneManager::GAMEPLAYTWOPLAYERS)
			{
				UpdatePlayer(player1, KEY_W, KEY_S);
				UpdatePlayer(player2, KEY_UP, KEY_DOWN);
				CheckCollisionBallArena(ball, player1.playerPoints, player2.playerPoints);
				ballIsHitP1 = CheckCollisionBallPlayer(ball, player1.playerRec, player1.playerColor);
				ballIsHitP2 = CheckCollisionBallPlayer(ball, player2.playerRec, player2.playerColor);
				UpdateBall(ball);
			}
			break;	

		case SceneManager::GAMEPAUSE:
			if (IsKeyPressed(KEY_SPACE) && gameStats.gameManager == SceneManager::GAMEPAUSE)
			{
				gameStats.gameManager = SceneManager::GAMEPLAYTWOPLAYERS;
			}
			break;

		case SceneManager::RESETGAME:
			break;

		case SceneManager::GAMEEND:
			break;	

		default:
			break;	
		}

		

		
		
	}

	void Draw(Player player1, Player player2, Ball& ball, Pong& gameStats)
	{
		int auxPosXPlayer1 = 200;
		int auxPosXPlayer2 = 570;

		switch ((SceneManager)gameStats.gameManager)
		{
		case SceneManager::GAMEMENU:
			break;

		case SceneManager::GAMEPLAYTWOPLAYERS:
			PrintScore(player1.playerPoints,auxPosXPlayer1);
			PrintScore(player2.playerPoints,auxPosXPlayer2);
			PrintArena(gameStats.screenWidth, gameStats.screenHeight);
			DrawPlayer(player1);
			DrawPlayer(player2);
			DrawBall(ball);
			break;

		case SceneManager::GAMEPAUSE:
			PrintScore(player1.playerPoints,auxPosXPlayer1);
			PrintScore(player2.playerPoints,auxPosXPlayer2);
			PrintArena(gameStats.screenWidth, gameStats.screenHeight);
			DrawPlayer(player1);
			DrawPlayer(player2);
			DrawBall(ball);
			PrintPause();
			break;

		case SceneManager::RESETGAME:
			DrawPlayer(player1);
			DrawPlayer(player2);
			DrawBall(ball);
			break;

		case SceneManager::GAMEEND:
			break;

		default:
			break;
		}
	}
}