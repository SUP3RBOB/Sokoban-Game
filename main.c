#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "game.h"

int main(void) {
    InitWindow(640, 480, "Sokoban Game");

    Objects* objects = malloc(sizeof(Objects));
    int level = 1;

    Start(objects);

    while (!WindowShouldClose()) {
        Update(objects, &level);
        BeginDrawing();
        Draw(objects, &level);
        EndDrawing();
    }

    End(objects);
    CloseWindow();

    return 0;
}