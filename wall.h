#pragma once

typedef struct wall {
    float x;
    float y;
    float width;
    float height;
    void* sprite;
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

Walls* CreateWallList();
void AddWall(Walls* walls, Wall* wall);
void DestroyWalls(Walls* walls);