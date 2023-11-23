#pragma once
#include "player.h"
#include "wall.h"
#include "box.h"

typedef struct {
    Player* player;
    Walls* walls;
    Boxes* boxes;
} Objects;

void MovePlayer(Objects* objects, float x, float y);
void DrawObjects(Objects* objects);
void DestroyObjects(Objects* objects);