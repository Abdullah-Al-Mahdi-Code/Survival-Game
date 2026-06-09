#include "raylib.h"

struct Coin {
    Vector2 position; // Use lowercase
    float radius;
    Color color;
};

// These are global variables
int score;
Coin coin;

void initCoin() {
    coin.position.x = (float)GetRandomValue(40, 760);
    coin.position.y = (float)GetRandomValue(40, 560);
    coin.radius = 15.0f; // You forgot to initialize radius!
    coin.color = GOLD;
    score = 0;
}

void UpdateCoin() {

    Rectangle playerRect = { player.position.x, player.position.y, player.size.x, player.size.y };

    if (CheckCollisionCircleRec(coin.position, coin.radius, playerRect)) {
        score = score + 1;
        coin.position.x = GetRandomValue(40, 760);
        coin.position.y = GetRandomValue(40, 560);
    }
} // <--- You were missing this brace!

void DrawCoin() {
        DrawCircleV(coin.position, coin.radius, coin.color);

    // Draw score outside the "if active" so it stays on screen
    // We use TextFormat to convert the integer score into text
    DrawText(TextFormat("Score: %i", score), 40, 40, 20, WHITE);
}
