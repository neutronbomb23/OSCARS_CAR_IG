#pragma once
#include "ofxAssimpModelLoader.h"
#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include <glm/glm.hpp>
class Crane;

class Hook : public GameObject {
public:
    Hook(Game* game, glm::vec3 pos, glm::vec3 dim, Crane* c);
    ~Hook();
    void receiveCarCollision(Player* car);
    void update();
    void draw();

    void translate(glm::vec3 pos, float distance);

private:
    ofxAssimpModelLoader model;
    glm::vec3 hookPosition;
    float hookY = 350;
};