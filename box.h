#pragma once
#include <stdbool.h>
#include "raylib.h"

typedef struct box {
    float x;
    float y;
    Rectangle sprite;
    struct box* next;
} Box;

typedef struct {
    Box* first;
    Box* last;
    int count;
} Boxes;

Box* CreateBox(float x, float y);

bool PointOnBox(Boxes* boxes, float x, float y, Box** outBox);
bool MoveBox(Box* box, float x, float y);
void DrawBox(Box* box);
void DestroyBox(Box* box);

Boxes* CreateBoxList();
void AddBox(Boxes* boxes, Box* box);
void DrawBoxes(Boxes* boxes);
void DestroyBoxes(Boxes* boxes);