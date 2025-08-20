#include "game.h"

#include <iostream>
#include "raylib.h"

using namespace std;

void gamePlay()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "PONG2 Ahora es personal");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        ///Input
        //Update

        BeginDrawing();
        //Draw
        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
}