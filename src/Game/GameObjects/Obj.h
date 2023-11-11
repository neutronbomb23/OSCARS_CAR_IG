#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Obj : public GameObject{
public:
    Obj(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Obj();
    
    void update() override;
    void draw() override;
    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;
    void changeColor(ofColor newColor);

private: 
    ofxAssimpModelLoader model;
};