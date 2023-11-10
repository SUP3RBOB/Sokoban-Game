#include "game.h"
#include "raylib.h"
#include "player.h"

Player* player;

void Start() {
    player = CreatePlayer(0, 0, 32);
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
}

void End() {
    DestroyPlayer(player);
}