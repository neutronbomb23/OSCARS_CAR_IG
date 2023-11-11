#ifndef BOMB_H
#define BOMB_H

#include "GameObject.h"
#include "Game.h"
#include "ofxAssimpModelLoader.h"

class Player;

class Bomb : public GameObject {
public:
    Bomb(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Bomb();

    void update();
    void draw();

private:
    ofxAssimpModelLoader model;
};

#endif