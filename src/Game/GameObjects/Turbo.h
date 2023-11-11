#pragma once
#include "ofxAssimpModelLoader.h"
#include "GameObject.h"
class Turbo : public GameObject
{
public:
    Turbo(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Turbo();
    void receiveCarCollision(Player* car) override;
    void update();
    void draw();
private:
    ofxAssimpModelLoader model;
};

