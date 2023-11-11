#pragma once
#include "Player.h"
#include "Goal.h"
#include "Bullet.h"
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"
#include <cstdlib>

class TPVCar : public GameObject {
private:
    Goal* goal;
    ofxAssimpModelLoader model;
    bool estadecelerando;
    float reducedTime;

    bool start = true;
    float distanceNextDir;
    float delayDistance = 750;
    glm::vec3 velocity = glm::vec3(8, 0, 8);

    // MODIFICACIONES PARA HACER QUE EL COCHE SE MUEVA DE IZQUIERDA A DERECHA:
    //float minX = -15.0f;  // the leftmost point that the car can move to
    //float maxX = 15.0f;   // the rightmost point that the car can move to

public:
    TPVCar(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~TPVCar();
    void receiveCarCollision(Player* car) override;
    void update();
    void decelerar();
    void receiveBulletCollision(GameObject* bullet);
    void draw();
};