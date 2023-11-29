#include "wall.h"
#include <stdlib.h>

Wall* CreateWall(float x, float y, float width, float height) {
    Wall* wall = malloc(sizeof(Wall));
    wall->x = x;
    wall->y = y;
    wall->next = NULL;

    Rectangle r;
    r.x = x;
    r.y = y;
    r.width = width;
    r.height = height;
    wall->sprite = r;
    return wall;
}

void DrawWall(Wall* wall) {
    DrawRectangleRec(wall->sprite, WHITE);
}

void DestroyWall(Wall* wall) {
    free(wall);
}

bool PointOnWall(Walls* walls, float x, float y) {
    Vector2 point = { x, y };
    Wall* current = walls->first;
    while (current != NULL) {
        if (CheckCollisionPointRec(point, current->sprite)) {
            return true;
        }
        current = current->next;
    }

    return false;
}

Walls* CreateWallList() {
    Walls* walls = malloc(sizeof(Walls));
    walls->first = NULL;
    walls->last = NULL;
    walls->count = 0;
    return walls;
}

void AddWall(Walls* walls, Wall* wall) {
    if (walls->count <= 0) {
        walls->first = wall;
        walls->last = wall;
        walls->count++;
        return;
    }

    walls->last->next = wall;
    walls->last = wall;
    walls->count++;
}

void ClearWalls(Walls* walls) {
    Wall* current = walls->first;
    while (current != NULL) {
        Wall* temp = current;
        current = current->next;
        DestroyWall(temp);
    }

    walls->first = NULL;
    walls->last = NULL;
    walls->count = 0;
}

void DrawWalls(Walls* walls) {
    Wall* current = walls->first;
    while (current != NULL) {
        DrawWall(current);
        current = current->next;
    }
}

void DestroyWalls(Walls* walls) {
    Wall* current = walls->first;
    while (current != NULL) {
        Wall* temp = current;
        current = current->next;
        DestroyWall(temp);
    }

    free(walls);
}