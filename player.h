#pragma once

typedef struct {
    int x;
    int y;
    int speed;
} Player;

Player* CreatePlayer(int x, int y, int speed);
void MovePlayer(Player* player, int x, int y);
void DrawPlayer(Player* player);
void DestroyPlayer(Player* player);