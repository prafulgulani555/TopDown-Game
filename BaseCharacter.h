// ifndef is short for "if not defined" apart from this "#pragma once" can be used
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getCollsionRec();
    virtual void tick(float deltaTime);  
    // pure virtual class are not defined in parent they are only defined in child and are market pure virtual by = 0
    virtual Vector2 getScreenPos() = 0;
    bool getAlive() {return alive;}
    void setAlive(bool isAlive) {alive = isAlive;}

protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1: facing right, -1: facing left
    float rightLeft{1.f};
    // animation variables
    float runningtime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{4.f};
    Vector2 velocity{};

private:
    bool alive{true};
};

#endif