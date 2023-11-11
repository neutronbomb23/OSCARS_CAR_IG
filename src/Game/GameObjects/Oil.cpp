#include "Oil.h"
#include "Player.h"

Oil::Oil(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("egg.dae", true);
    model.setRotation(0, 90,90, 0, 0);
    model.setScale(0.5, 0.5, 0.5);
    model.setPosition(0, -15, 0);
  
    //collider->setParent(transform);
    //collider->setHeight(15);
    //collider->setWidth(50);
    //collider->set(dim.x, dim.y, dim.z);
    material.setDiffuseColor(ofColor::yellow);
}

Oil::~Oil() {}

void Oil::update() {
    model.update();
}
void Oil::draw() {  
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();  
}

void  Oil::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
};

void Oil::receiveCarCollision(Player* car) { 
    car->startSkidding();
    kill();
}
