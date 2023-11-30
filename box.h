#pragma once
#include <stdbool.h>
#include "raylib.h"

typedef struct box {
    float x;
    float y;
    float xStart;
    float yStart;
    Rectangle sprite;
    Texture2D texture;
    struct box* next;
} Box;

typedef struct {
    Box* first;
    Box* last;
    int count;
} Boxes;

Box* CreateBox(float x, float y);

bool PointOnBox(Boxes* boxes, float x, float y, Box** outBox);
void MoveBox(Box* box, float x, float y);
void ResetBox(Box* box);
void DrawBox(Box* box);
void DestroyBox(Box* box);

Boxes* CreateBoxList();
void AddBox(Boxes* boxes, Box* box);
void ClearBoxes(Boxes* boxes);
void DrawBoxes(Boxes* boxes);
void DestroyBoxes(Boxes* boxes);