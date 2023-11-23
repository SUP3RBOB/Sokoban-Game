#include "game.h"
#include <stdlib.h>
#include "raylib.h"
#include "objects.h"

Objects* objects;

void Start() {
    objects = malloc(sizeof(Objects));
    objects->player = CreatePlayer(0, 0);
    objects->walls = CreateWallList();
    objects->boxes = CreateBoxList();

    AddWall(objects->walls, CreateWall(64, 64, 128, 32));
    AddBox(objects->boxes, CreateBox(128, 128));
    AddBox(objects->boxes, CreateBox(256, 256));
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
}

void Draw() {
    ClearBackground(BLACK);
    DrawObjects(objects);
}

void End() {
    DestroyObjects(objects);
}