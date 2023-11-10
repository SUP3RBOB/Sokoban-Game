#include <stdio.h>
#include "raylib.h"
#include "game.h"

int main(void) {
    InitWindow(640, 480, "Sokoban Game");

    Start();

    while (!WindowShouldClose()) {
        Update();
        BeginDrawing();
        Draw();
        EndDrawing();
    }

    End();
    CloseWindow();

    return 0;
}