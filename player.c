#include "player.h"
#include <stdlib.h>

Player* CreatePlayer(float x, float y, float speed) {
    Player* player = malloc(sizeof(Player));
    player->x = x;
    player->y = y;
    player->speed = speed;

    Rectangle r;
    r.x = x;
    r.y = y;
    r.width = 32;
    r.height = 32;
    player->sprite = r;

    return player;
}

void SetPlayerX(Player* player, float x) {
    player->x = x;
}

void SetPlayerY(Player* player, float y) {
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
