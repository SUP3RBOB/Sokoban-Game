#pragma once
#include <stdbool.h>
#include "raylib.h"

typedef struct wall {
    float x;
    float y;
    Rectangle sprite;
    struct wall* next;
} Wall;

typedef struct {
    Wall* first;
    Wall* last;
    int count;
} Walls;

Wall* CreateWall(float x, float y, float width, float height);
void DrawWall(Wall* wall);
void DestroyWall(Wall* wall);

bool PointOnWall(Walls* list, float x, float y);

Walls* CreateWallList();
void AddWall(Walls* walls, Wall* wall);
void DrawWalls(Walls* walls);
void DestroyWalls(Walls* walls);