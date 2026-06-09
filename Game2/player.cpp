#include "raylib.h"
struct Player {
    Vector2 position;
    Vector2 size;
    float speed;
    Color color;
};
Player player;
void initPlayer() {
    player.position = {400, 300};
    player.size = {40.0f, 40.0f};
    player.speed =300.0f;
    player.color =BLUE;
}
void UpdatePlayer() {
    float deltatime = GetFrameTime();
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        player.position.x += player.speed * deltatime;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        player.position.x -= player.speed * deltatime;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        player.position.y += player.speed * deltatime;
    }
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        player.position.y -= player.speed * deltatime;
    }
}
void DrawPlayer() {
    DrawRectangleV(player.position, player.size, player.color);
}
