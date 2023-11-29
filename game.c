#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include "objects.h"

Objects* objects;
int level = 1;

void Start() {
    objects = malloc(sizeof(Objects));
    objects->player = CreatePlayer(0, 0);
    objects->walls = CreateWallList();
    objects->boxes = CreateBoxList();
    objects->goals = CreateGoalList();

    LevelOne(objects);
}

void Update() {
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
        level++;
        DestroyLevel(objects);
        LoadLevel(objects, level);
    }
}

void Draw() {
    ClearBackground(BLACK);
    DrawObjects(objects);
}

void End() {
    DestroyObjects(objects);
}