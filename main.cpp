#include <raylib.h>
#include "circle.h"

int main()
{
    circle circle1;
    int screenWidth = 800;
    int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "Asteroids");
    SetTargetFPS(60);
    float posX = 20, posY = 20;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        float dt = GetFrameTime();
        float speed = 400.0f;
        if (IsKeyDown(KEY_A))
        {
            posX -= speed * dt;
        }
        if (IsKeyDown(KEY_D))
        {
            posX += speed * dt;
        }
        if (IsKeyDown(KEY_W))
        {
            posY -= speed * dt;
        }
        if (IsKeyDown(KEY_S))
        {
            posY += speed * dt;
        }
        DrawRectangle(posX, posY, 20, 20, WHITE);
        circle1.spawn();
        circle1.setX(circle1.getPosX() - circle1.getSpeed() * dt);
        circle1.setY(circle1.getPosY() - circle1.getSpeed() * dt);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}