#ifndef CRANE_H
#define CRANE_H

#include "ofxAssimpModelLoader.h"
#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include <glm/glm.hpp>
#include "Hook.h"

class Crane : public GameObject {
public:
    Crane(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Crane();
    void receiveCarCollision(Player* car);
    void update();
    void draw();

private:
    ofxAssimpModelLoader model;
    Hook* hook = nullptr;
    float hammerDistance = 200;
};

#endif 
