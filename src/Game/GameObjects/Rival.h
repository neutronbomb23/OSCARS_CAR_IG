#pragma once
#include "Goal.h"
#include "Bullet.h"
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Rival : public GameObject {
public:
   Rival(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Rival();
    void receiveCarCollision(Player* car) override;
    void update();
    void decelerar();
    void receiveBulletCollision(GameObject* bullet);
    void draw();
private:
    Goal* goal;
    ofxAssimpModelLoader model;
    float speed;
    bool estadecelerando;
    float reducedTime;
};