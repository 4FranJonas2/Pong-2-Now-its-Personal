#include "game.h"
#include <iostream>

#include "player.h"

using namespace std;

namespace pong2
{
    void GamePlay()
    {
        const int screenWidth = 800;
        const int screenHeight = 450;

        InitWindow(screenWidth, screenHeight, "PONG2 Ahora es personal");

        //SetTargetFPS(60);

        while (!WindowShouldClose())
        {
            Input();
            Update();

            BeginDrawing();
            Draw();
            ClearBackground(RAYWHITE);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
        }

        CloseWindow();
    }

    void Input()
    {

    }

    void Update()
    {

    }

    void Draw()
    {

    }

}