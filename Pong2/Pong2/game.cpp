#include "game.h"

#include <iostream>

using namespace std;

namespace pong2
{
    void GamePlay()
    {
        const int screenWidth = 800;
        const int screenHeight = 450;

        Player player1;
        Player player2;

        InitWindow(screenWidth, screenHeight, "PONG2 Ahora es personal");

        Init(player1,player2);

        while (!WindowShouldClose())
        {
            Input();
            Update();

            BeginDrawing();
            //ClearBackground(BLACK);
            Draw(player1,player2);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
        }

        CloseWindow();
    }

    void Init(Player& player1, Player& player2)
    {
        Initplayer(player1,player1.initPlayer1PosX,player1.initPlayerPosY);
        Initplayer(player2, player2.initPlayer2PosX, player2.initPlayerPosY);
    }

    void Input()
    {

    }

    void Update()
    {

    }

    void Draw(Player& player1, Player& player2)
    {
        DrawPlayer(player1);
        DrawPlayer(player2);
    }

}