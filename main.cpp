#include <raylib.h>

int main()
{
    int screenWidth = 800;
    int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "Asteroids");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}