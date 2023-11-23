#include "player.h"
#include <stdio.h>
#include <stdlib.h>

Player* CreatePlayer(float x, float y) {
    Player* player = malloc(sizeof(Player));
    player->x = x;
    player->y = y;

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

void DrawPlayer(Player* player) {
    player->sprite.x = player->x;
    player->sprite.y = player->y;
    DrawRectangleRec(player->sprite, RED);
}

void DestroyPlayer(Player* player) {
    free(player);
}
