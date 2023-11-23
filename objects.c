#include "objects.h"
#include <stdlib.h>

void MovePlayer(Objects* objects, float x, float y) {
    float xOffset = x * objects->player->speed;
    float yOffset = y * objects->player->speed;
    float xMove = objects->player->x + xOffset;
    float yMove = objects->player->y + yOffset;

    bool wallCollision = PointOnWall(objects->walls, xMove, yMove);
    if (wallCollision) return;

    Box* outBox;
    bool boxCollision = PointOnBox(objects->boxes, xMove, yMove, &outBox);
    if (boxCollision) {
        float bXMove = outBox->x + xOffset;
        float bYMove = outBox->y + yOffset;
        if (PointOnWall(objects->walls, bXMove, bYMove)) {
            return;
        } else {
            MoveBox(outBox, xOffset, yOffset);
        }
    }

    SetPlayerX(objects->player, xMove);
    SetPlayerY(objects->player, yMove);
}

void DrawObjects(Objects* objects) {
    DrawPlayer(objects->player);
    DrawWalls(objects->walls);
    DrawBoxes(objects->boxes);
}

void DestroyObjects(Objects* objects) {
    DestroyPlayer(objects->player);
    DestroyWalls(objects->walls);
    DestroyBoxes(objects->boxes);
    free(objects);
}