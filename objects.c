#include "objects.h"
#include <stdio.h>
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

void ResetObjects(Objects* objects) {
    ResetPlayerPosition(objects->player);

    Box* current = objects->boxes->first;
    while (current != NULL) {
        ResetBox(current);
        current = current->next;
    }
}

void DrawObjects(Objects* objects) {
    DrawGoals(objects->goals);
    DrawPlayer(objects->player);
    DrawWalls(objects->walls);
    DrawBoxes(objects->boxes);
}

void DestroyObjects(Objects* objects) {
    DestroyPlayer(objects->player);
    DestroyWalls(objects->walls);
    DestroyBoxes(objects->boxes);
    DestroyGoals(objects->goals);
    free(objects);
}

bool LevelCompleted(Objects* objects) {
    int goalsCaptured = 0;

    Goal* current = objects->goals->first;
    while (current != NULL) {
        if (PointOnBox(objects->boxes, current->x + 16, current->y + 16, NULL)) {
            goalsCaptured++;
        }
        current = current->next;
    }

    return goalsCaptured >= objects->goals->count;
}

void LoadLevel(Objects* _objects, int _level) {
    if (_level == 1) {
        LevelOne(_objects);
        return;
    }

    if (_level == 2) {
        LevelTwo(_objects);
        return;
    }
}

void LevelOne(Objects* objects) {
    SetPlayerPosition(objects->player, 320, 224);
    SetPlayerStartPosition(objects->player, 320, 224);

    AddBox(objects->boxes, CreateBox(192, 160));
    AddBox(objects->boxes, CreateBox(352, 256));
    AddBox(objects->boxes, CreateBox(224, 320));

    AddGoal(objects->goals, CreateGoal(384, 160));
    AddGoal(objects->goals, CreateGoal(384, 352));
    AddGoal(objects->goals, CreateGoal(288, 320));

    AddWall(objects->walls, CreateWall(320, 384, 96, 32));
    AddWall(objects->walls, CreateWall(160, 352, 160, 32));
    AddWall(objects->walls, CreateWall(128, 288, 32, 64));
    AddWall(objects->walls, CreateWall(384, 320, 32, 32));
    AddWall(objects->walls, CreateWall(416, 160, 32, 224));
    AddWall(objects->walls, CreateWall(224, 288, 128, 32));
    AddWall(objects->walls, CreateWall(320, 256, 32, 32));
    AddWall(objects->walls, CreateWall(384, 192, 32, 96));
    AddWall(objects->walls, CreateWall(160, 128, 32, 160));
    AddWall(objects->walls, CreateWall(256, 224, 32, 32));
    AddWall(objects->walls, CreateWall(256, 128, 64, 96));
    AddWall(objects->walls, CreateWall(192, 96, 64, 32));
    AddWall(objects->walls, CreateWall(320, 128, 96, 32));
}

void LevelTwo(Objects* objects) {
    SetPlayerPosition(objects->player, 320, 224);
    SetPlayerStartPosition(objects->player, 320, 224);

    AddBox(objects->boxes, CreateBox(192, 160));
    AddBox(objects->boxes, CreateBox(352, 256));
    AddBox(objects->boxes, CreateBox(224, 320));

    AddGoal(objects->goals, CreateGoal(384, 160));
    AddGoal(objects->goals, CreateGoal(384, 352));
    AddGoal(objects->goals, CreateGoal(288, 320));

    AddWall(objects->walls, CreateWall(320, 384, 96, 32));
    AddWall(objects->walls, CreateWall(160, 352, 160, 32));
    AddWall(objects->walls, CreateWall(128, 288, 32, 64));
    AddWall(objects->walls, CreateWall(384, 320, 32, 32));
    AddWall(objects->walls, CreateWall(416, 160, 32, 224));
    AddWall(objects->walls, CreateWall(224, 288, 128, 32));
    AddWall(objects->walls, CreateWall(320, 256, 32, 32));
    AddWall(objects->walls, CreateWall(384, 192, 32, 96));
    AddWall(objects->walls, CreateWall(160, 128, 32, 160));
    AddWall(objects->walls, CreateWall(256, 224, 32, 32));
    AddWall(objects->walls, CreateWall(256, 128, 64, 96));
    AddWall(objects->walls, CreateWall(192, 96, 64, 32));
    AddWall(objects->walls, CreateWall(320, 128, 96, 32));
}

void DestroyLevel(Objects* objects) {
    ClearWalls(objects->walls);
    ClearBoxes(objects->boxes);
    ClearGoals(objects->goals);
}