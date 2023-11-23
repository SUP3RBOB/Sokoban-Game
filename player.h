#pragma once
#include <stdbool.h>
#include "raylib.h"

typedef struct {
    float x;
    float y;
    float speed;
    Rectangle sprite;
} Player;

Player* CreatePlayer(float x, float y, float speed);
void SetPlayerX(Player* player, float x);
void SetPlayerY(Player* player, float y);
void DrawPlayer(Player* player);
void DestroyPlayer(Player* player);