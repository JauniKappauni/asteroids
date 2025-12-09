#pragma once
#include <raylib.h>

class circle
{
private:
    float posX = 600;
    float posY = 200;
    float speed = 25;
    float radius = 50;

public:
    circle();
    ~circle();
    void spawn()
    {
        DrawCircle(posX, posY, radius, WHITE);
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
    float getRadius(){
        return radius;
    }
};

circle::circle()
{
}

circle::~circle()
{
}
