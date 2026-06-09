#include "GameManager.cpp"
#include "raylib.h"
int main() {
    init();
    while (!WindowShouldClose()) {
        loop();
    }
    CloseWindow();
    return 0;
}
