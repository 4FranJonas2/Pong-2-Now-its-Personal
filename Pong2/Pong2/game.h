#pragma once

#include "player.h"
#include "ball.h"

namespace pong2
{
	void GamePlay();
	void Init(Player& player1, Player& player2);
	//void Input();
	void Update(Player& player1, Player& player2);
	void Draw(Player player1, Player player2);
}
