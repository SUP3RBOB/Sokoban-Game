#include "box.h"
#include <stdio.h>
#include <stdlib.h>

Box* CreateBox(float x, float y) {
    Box* box = malloc(sizeof(Box));
    box->x = x;
    box->y = y;
    box->xStart = x;
    box->yStart = y;
    box->next = NULL;

    Rectangle r;
    r.x = x;
    r.y = y;
    r.width = 32;
    r.height = 32;
    box->sprite = r;
    return box;
}

bool PointOnBox(Boxes* boxes, float x, float y, Box** outBox) {
    Vector2 point = { x, y };
    Box* current = boxes->first;
    while (current != NULL) {
        if (CheckCollisionPointRec(point, current->sprite)) {
            if (outBox != NULL) {
                *outBox = current;
            }
            return true;
        }
        current = current->next;
    }

    return false;
}

void MoveBox(Box* box, float x, float y) {
    box->x += x;
    box->y += y;
}

void ResetBox(Box* box) {
    box->x = box->xStart;
    box->y = box->yStart;
}

void DrawBox(Box* box) {
    box->sprite.x = box->x;
    box->sprite.y = box->y;
    DrawRectangleRec(box->sprite, BLUE);
}

void DestroyBox(Box* box) {
    free(box);
}

Boxes* CreateBoxList() {
    Boxes* boxes = malloc(sizeof(Boxes));
    boxes->first = NULL;
    boxes->last = NULL;
    boxes->count = 0;
    return boxes;
}

void AddBox(Boxes* boxes, Box* box) {
    if (boxes->count <= 0) {
        boxes->first = box;
        boxes->last = box;
        boxes->count++;
        return;
    }

    boxes->last->next = box;
    boxes->last = box;
    boxes->count++;
}

void ClearBoxes(Boxes* boxes) {
    Box* current = boxes->first;
    while (current != NULL) {
        Box* temp = current;
        current = current->next;
        DestroyBox(temp);
    }

    boxes->first = NULL;
    boxes->last = NULL;
    boxes->count = 0;
}

void DrawBoxes(Boxes* boxes) {
    Box* current = boxes->first;
    while (current != NULL) {
        DrawBox(current);
        current = current->next;
    }
}

void DestroyBoxes(Boxes* boxes) {
    Box* current = boxes->first;
    while (current != NULL) {
        Box* temp = current;
        current = current->next;
        DestroyBox(temp);
    }

    free(boxes);
}
