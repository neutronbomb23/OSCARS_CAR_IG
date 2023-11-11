#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"
class Building : public GameObject {
public:
    Building(Game* game, glm::vec3 pos, glm::vec3 dim);
    void update() override;
    void draw() override;
    ~Building();
private: 
    ofxAssimpModelLoader model;
};

