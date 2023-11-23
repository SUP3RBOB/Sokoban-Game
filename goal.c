#include "goal.h"
#include <stdlib.h>

Goal* CreateGoal(float x, float y) {
    Goal* goal = malloc(sizeof(Goal));
    goal->x = x;
    goal->y = y;
    Rectangle r;
    r.x = x;
    r.y = y;
    r.width = 32;
    r.height = 32;
    goal->sprite = r;
    return goal;
}

void DrawGoal(Goal* goal) {
    DrawRectangleRec(goal->sprite, GREEN);
}

void DestroyGoal(Goal* goal) {
    free(goal);
}

Goals* CreateGoalList() {
    Goals* goals = malloc(sizeof(Goals));
    goals->first = NULL;
    goals->last = NULL;
    goals->count = 0;
    return goals;
}

void AddGoal(Goals* goals, Goal* goal) {
    if (goals->count <= 0) {
        goals->first = goal;
        goals->last = goal;
        goals->count++;
        return;
    }

    goals->last->next = goal;
    goals->last = goal;
    goals->count++;
}

void DrawGoals(Goals* goals) {
    Goal* current = goals->first;
    while (current != NULL) {
        DrawGoal(current);
        current = current->next;
    }
}

void DestroyGoals(Goals* goals) {
    Goal* current = goals->first;
    while (current != NULL) {
        Goal* temp = current;
        current = current->next;
        DestroyGoal(temp);
    }

    free(goals);
}