#include "player.h"
#include <stdlib.h>
#include "raylib.h"

Player* CreatePlayer(int x, int y, int speed) {
    Player* player = malloc(sizeof(Player));
    player->x = x;
    player->y = y;
    player->speed = speed;
    return player;
}

void MovePlayer(Player *player, int x, int y) {
    player->x += x * player->speed;
    player->y += y * player->speed;
}

void DrawPlayer(Player* player) {
    DrawRectangle(player->x, player->y, 32, 32, RED);
}

void DestroyPlayer(Player* player) {
    free(player);
}
