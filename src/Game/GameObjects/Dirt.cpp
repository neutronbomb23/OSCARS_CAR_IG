#include "Dirt.h"
#include "Player.h"

Dirt::Dirt(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("Rock1.dae");
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -30, 0);
    model.setScale(0.5, 0.5, 0.5);
    material.setDiffuseColor(ofColor::yellow);
}

Dirt::~Dirt() {}

void Dirt::update() {
    model.update();
}

void Dirt::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
    material.begin();
    {
       
    }
    material.end();
}

void Dirt::receiveCarCollision(Player* car) {
    car->reduceSpeedOnDirt();
}
