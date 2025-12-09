#include <raylib.h>
#include "circle.h"

int main()
{
    circle circle1;
    int screenWidth = 800;
    int screenHeight = 400;
    bool isGameStarted = false;
    InitWindow(screenWidth, screenHeight, "Asteroids");
    SetTargetFPS(60);
    float posX = 20, posY = 20;
    while (!WindowShouldClose())
    {
        if (!isGameStarted)
        {
            Vector2 mouse = GetMousePosition();
            Rectangle btn = {300, 100, 200, 100};
            Rectangle btn2 = {300, 250, 200, 100};
            BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangleRec(btn, GRAY);
            DrawRectangleRec(btn2, GRAY);
            DrawText("Start", 370, 150, 20, WHITE);
            DrawText("Quit", 370, 300, 20, WHITE);
            EndDrawing();
            if (CheckCollisionPointRec(mouse, btn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isGameStarted = true;
            }
            if (CheckCollisionPointRec(mouse, btn2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
            continue;
        }
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
        if (circle1.getPosY() < 0)
        {
            circle1.reset();
        }
        Vector2 object = {circle1.getPosX(), circle1.getPosY()};
        Rectangle player = {posX, posY, 20, 20};
        if (CheckCollisionCircleRec(object, circle1.getRadius(), player))
        {
            isGameStarted = false;
            posX = 20;
            posY = 20;
            circle1.reset();
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