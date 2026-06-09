#include "raylib.h"

#include "player.cpp"
#include "coin.cpp"
#include "enemy.cpp" // New include

void init() {
    InitWindow(800, 600, "Game 2: Survival");
    SetTargetFPS(60);

    initPlayer();
    initCoin();
    initEnemy(); // Initialize enemy
}

void loop() {
    UpdatePlayer();
    UpdateCoin();
    UpdateEnemy(); // Update enemy

    BeginDrawing();
    ClearBackground(BLACK); // Let's make it dark for survival

    DrawPlayer();
    DrawCoin();
    drawEnemy(); // Draw enemy

    EndDrawing();
}
