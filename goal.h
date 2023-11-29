#pragma once
#include "raylib.h"

typedef struct goal {
    float x;
    float y;
    Rectangle sprite;
    struct goal* next;
} Goal;

typedef struct {
    Goal* first;
    Goal* last;
    int count;
} Goals;

Goal* CreateGoal(float x, float y);
void DrawGoal(Goal* goal);
void DestroyGoal(Goal* goal);

Goals* CreateGoalList();
void AddGoal(Goals* goals, Goal* goal);
void ClearGoals(Goals* goals);
void DrawGoals(Goals* goals);
void DestroyGoals(Goals* goals);