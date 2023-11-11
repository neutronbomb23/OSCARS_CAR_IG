#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Oil : public GameObject {
public:
    Oil(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Oil();

    void update();

    void draw() override;
    void receiveBulletCollision(GameObject* bullet);
    void receiveCarCollision(Player* car) override;

private:
    ofxAssimpModelLoader model;
    ofTexture texture;
};


