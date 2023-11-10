#include "wall.h"
#include <stdlib.h>
#include "raylib.h"

Wall* CreateWall(float x, float y, float width, float height) {
    Wall* wall = malloc(sizeof(Wall));
    wall->x = x;
    wall->y = y;
    wall->width = width;
    wall->height = height;
    wall->next = NULL;

    Rectangle* r = malloc(sizeof(Rectangle));
    r->x = x;
    r->y = y;
    r->width = width;
    r->height = height;
    wall->sprite = r;
    return wall;
}

void DrawWall(Wall* wall) {
    DrawRectangleRec(*(Rectangle*)wall->sprite, WHITE);
}

void DestroyWall(Wall* wall) {
    free(wall->sprite);
    free(wall);
}