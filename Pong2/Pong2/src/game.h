#pragma once

#include "player.h"
#include "ball.h"

namespace pong2
{
	void GamePlay();
	void Init(Player& player1, Player& player2,Ball& ball);
	//void Input();
	void Update(Player& player1, Player& player2, Pong& gameStats, Ball& ball);
	void Draw(Player player1, Player player2, Ball& ball);
}
