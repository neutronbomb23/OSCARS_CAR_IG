#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class ArcoLoco : public GameObject
{
private:
    ofxAssimpModelLoader model;
    ofFbo fbo;
    int num;
    glm::vec3 pos_;
    int currentTime;
    int previousTime = 0;
    ofTexture texture;
public:
    ArcoLoco(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~ArcoLoco();

    void update() override;
    void draw() override;
    void receiveCarCollision(Player* car) override;
};