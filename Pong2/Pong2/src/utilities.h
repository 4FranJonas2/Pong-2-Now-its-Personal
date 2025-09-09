#pragma once

namespace pong2
{
	//float defaultVel = 0.1f;
	enum class SceneManager
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
		SceneManager gameManager;

		const int screenWidth = 800;
		const int screenHeight = 450;
	};
}
