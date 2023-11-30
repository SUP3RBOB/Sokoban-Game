#include "game.h"
#include <stdio.h>

void Start(Objects* objects) {
    objects->player = CreatePlayer(0, 0);
    objects->walls = CreateWallList();
    objects->boxes = CreateBoxList();
    objects->goals = CreateGoalList();

    LevelOne(objects);
}

void Update(Objects* objects, int* level) {
    if (IsKeyPressed(KEY_RIGHT)) {
        MovePlayer(objects, 1, 0);
    }

    if (IsKeyPressed(KEY_LEFT)) {
        MovePlayer(objects, -1, 0);
    }

    if (IsKeyPressed(KEY_DOWN)) {
        MovePlayer(objects, 0, 1);
    }

    if (IsKeyPressed(KEY_UP)) {
        MovePlayer(objects, 0, -1);
    }

    if (IsKeyPressed(KEY_SPACE)) {
        ResetObjects(objects);
    }

    if (LevelCompleted(objects)) {
        (*level)++;
        DestroyLevel(objects);
        LoadLevel(objects, *level);
    }
}

void Draw(Objects* objects, int* level) {
    ClearBackground(BLACK);
    DrawObjects(objects);
    char levelLabel[12];
    sprintf(levelLabel, "Level %d", (*level));
    DrawText(levelLabel, 4, 4, 30, WHITE);
}

void End(Objects* objects) {
    DestroyObjects(objects);
}