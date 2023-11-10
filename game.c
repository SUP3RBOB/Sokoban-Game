#include "game.h"
#include "raylib.h"
#include "player.h"
#include "wall.h"

Player* player;
Wall* wall;

void Start() {
    player = CreatePlayer(0, 0, 32);
    wall = CreateWall(256, 128, 96, 32);
}

void Update() {
    if (IsKeyPressed(KEY_RIGHT)) {
        MovePlayer(player, 1, 0);
    }

    if (IsKeyPressed(KEY_LEFT)) {
        MovePlayer(player, -1, 0);
    }

    if (IsKeyPressed(KEY_DOWN)) {
        MovePlayer(player, 0, 1);
    }

    if (IsKeyPressed(KEY_UP)) {
        MovePlayer(player, 0, -1);
    }
}

void Draw() {
    ClearBackground(BLACK);
    DrawPlayer(player);
    DrawWall(wall);
}

void End() {
    DestroyPlayer(player);
    DestroyWall(wall);
}