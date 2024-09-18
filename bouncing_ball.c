#include "../include/raylib.h"
#define ballRadius 150


static Vector2 ballPosition = {0};
static Vector2 ballSpeed = { 5.0f, 4.0f };

void game_init() {
    InitWindow(800, 450, "Raylib Window");
    SetTargetFPS(60);
    int w = GetScreenWidth();
    int h = GetScreenHeight();
    ballPosition.x = w / 2;
    ballPosition.y = h / 2;
}

void game_frame() {
    ballPosition.x += ballSpeed.x;
    ballPosition.y += ballSpeed.y;

    if((ballPosition.x - ballRadius) <= 0 || ballPosition.x + ballRadius >= GetScreenWidth()) {
        ballSpeed.x *= -1;
    }

    if((ballPosition.y - ballRadius) <= 0 || ballPosition.y + ballRadius >= GetScreenHeight()) {
        ballSpeed.y *= -1;
    }
    
    BeginDrawing();

    ClearBackground(BLACK);

    DrawCircleV(ballPosition, (float)ballRadius, RED);

    EndDrawing();
}

void game_over() {
    CloseWindow();
}

#ifndef PLATFORM_WEB
int main(void)
{
    game_init();
    while(!WindowShouldClose())
    {
        game_frame();
    }
    game_over();
    return 0;
}
#endif
