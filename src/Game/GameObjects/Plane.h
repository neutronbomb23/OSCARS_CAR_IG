#ifndef PLANE_H
#define PLANE_H

#include "GameObject.h"
#include "Game.h"
#include "ofxAssimpModelLoader.h"
#include "ofMain.h"
#include "Player.h"

class Plane : public GameObject {
public:
    Plane(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Plane();

    void update();
    void draw();

private:
    ofxAssimpModelLoader model;
    glm::vec3 velocity;
    float timeCounter;
};

#endif