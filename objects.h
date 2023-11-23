#pragma once
#include "player.h"
#include "wall.h"
#include "box.h"
#include "goal.h"

typedef struct {
    Player* player;
    Walls* walls;
    Boxes* boxes;
    Goals* goals;
} Objects;

void MovePlayer(Objects* objects, float x, float y);
void ResetObjects(Objects* objects);
void DrawObjects(Objects* objects);
void DestroyObjects(Objects* objects);

bool LevelCompleted(Objects* objects);

void LevelOne(Objects* objects);