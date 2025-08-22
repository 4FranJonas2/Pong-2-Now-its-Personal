#pragma once

#include "player.h"

namespace pong2
{
	void GamePlay();
	void Init(Player& player1, Player& player2);
	void Input();
	void Update();
	void Draw(Player& player1, Player& player2);
}
