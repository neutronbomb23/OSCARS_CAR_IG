#pragma once
#include "GameObject.h"
#include "Player.h"
#include "ofxAssimpModelLoader.h"

class Game;

class Pit : public GameObject {
public:
    Pit(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Pit();

    void draw();
    void receiveCarCollision(Player* car);

private:
    ofxAssimpModelLoader model;
    ofPlanePrimitive plane;
    ofMaterial material;
};
