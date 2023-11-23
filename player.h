#pragma once
#include <stdbool.h>
#include "raylib.h"

typedef struct {
    float x;
    float y;
    float xStart;
    float yStart;
    float speed;
    Rectangle sprite;
} Player;

Player* CreatePlayer(float x, float y);
void SetPlayerPosition(Player* player, float x, float y);
void SetPlayerStartPosition(Player* player, float x, float y);
void ResetPlayerPosition(Player* player);
void DrawPlayer(Player* player);
void DestroyPlayer(Player* player);