#include "player.h"
#include <stdio.h>
#include <stdlib.h>

Player* CreatePlayer(float x, float y) {
    Player* player = malloc(sizeof(Player));
    player->x = x;
    player->y = y;
    player->xStart = x;
    player->yStart = y;

    Rectangle r;
    r.x = x;
    r.y = y;
    r.width = 32;
    r.height = 32;
    player->sprite = r;

    player->speed = r.width;

    return player;
}

void SetPlayerPosition(Player* player, float x, float y) {
    player->x = x;
    player->y = y;
}

void SetPlayerStartPosition(Player* player, float x, float y) {
    player->xStart = x;
    player->yStart = y;
}

void ResetPlayerPosition(Player* player) {
    SetPlayerPosition(player, player->xStart, player->yStart);
}

void DrawPlayer(Player* player) {
    player->sprite.x = player->x;
    player->sprite.y = player->y;
    DrawRectangleRec(player->sprite, RED);
}

void DestroyPlayer(Player* player) {
    free(player);
}
