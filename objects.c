#include "objects.h"
#include <stdlib.h>

void MovePlayer(Objects* objects, float x, float y) {
    float xOffset = x * objects->player->speed;
    float yOffset = y * objects->player->speed;
    float xMove = objects->player->x + xOffset;
    float yMove = objects->player->y + yOffset;
    float collOffset = objects->player->sprite.width / 2;

    bool wallCollision = PointOnWall(objects->walls, xMove + collOffset, yMove + collOffset);
    if (wallCollision) return;

    Box* outBox;
    bool boxCollision = PointOnBox(objects->boxes, xMove + collOffset, yMove + collOffset, &outBox);
    if (boxCollision) {
        float bXMove = outBox->x + xOffset;
        float bYMove = outBox->y + yOffset;
        Box* dummyBox;
        if (PointOnWall(objects->walls, bXMove + collOffset, bYMove + collOffset) ||
                PointOnBox(objects->boxes, bXMove + collOffset, bYMove + collOffset, &dummyBox)) {
            return;
        } else {
            MoveBox(outBox, xOffset, yOffset);
        }
    }

    SetPlayerPosition(objects->player, xMove, yMove);
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