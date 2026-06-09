#include "raylib.h"
struct Enemy {
  Vector2 position;
  Vector2 size;
  float speed;
  Color color;
};
Enemy enemy;
void initEnemy() {
    enemy.position.x = 100;
    enemy.position.y = 100;
    enemy.size.x = 30;
    enemy.size.y = 30;
    enemy.speed = 120;
    enemy.color = RED;
}
void UpdateEnemy() {
    float dt = GetFrameTime();

        // SIMPLE AI: Follow the player
        // To move toward something, we compare positions
        if (player.position.x > enemy.position.x) enemy.position.x += enemy.speed * dt;
        if (player.position.x < enemy.position.x) enemy.position.x -= enemy.speed * dt;

        if (player.position.y > enemy.position.y) enemy.position.y += enemy.speed * dt;
        if (player.position.y < enemy.position.y) enemy.position.y -= enemy.speed * dt;

        // COLLISION WITH PLAYER
        Rectangle playerRect = { player.position.x, player.position.y, player.size.x, player.size.y };
        Rectangle enemyRect = { enemy.position.x, enemy.position.y, enemy.size.x, enemy.size.y };

        if (CheckCollisionRecs(playerRect, enemyRect)) {
            // Reset the game if touched
            initPlayer();
            initEnemy();
            score = 0;
        }
    }

    void drawEnemy() {
        DrawRectangleV(enemy.position, enemy.size, enemy.color);
    }
