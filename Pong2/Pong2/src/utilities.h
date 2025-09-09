#pragma once

namespace pong2
{
	//float defaultVel = 0.1f;
	enum class SceneStatus
	{
		INITGAME = 1,
		GAMEMENU,
		GAMEPLAYTWOPLAYERS,
		GAMEPAUSE,
		RESETGAME,
		GAMEEND
	};

	struct Pong
	{
		SceneStatus gameManager;
		bool endGame = false;
		const int screenWidth = 800;
		const int screenHeight = 450;
	};
}
