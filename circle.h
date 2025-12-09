#pragma once
#include <raylib.h>

class circle
{
private:
    float posX = 600;
    float posY = 200;
    float speed = 25;

public:
    circle();
    ~circle();
    void spawn()
    {
        DrawCircle(posX, posY, 50, WHITE);
    }
    float getPosX()
    {
        return posX;
    }
    float getPosY()
    {
        return posY;
    }
    void setX(float x)
    {
        posX = x;
    }
    void setY(float y)
    {
        posY = y;
    }
    int getSpeed()
    {
        return speed;
    }
    void reset()
    {
        posX = 600;
        posY = 200;
    }
};

circle::circle()
{
}

circle::~circle()
{
}
