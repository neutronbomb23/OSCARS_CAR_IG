#include "Pit.h"
#include "Game.h"

Pit::Pit(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    material.setDiffuseColor(ofColor::black);
    model.loadModel("Craneo.dae");
    model.setPosition(0, 0, 0);
    model.setRotation(0, 180, 1, 0, 0);
    model.setScale(0.10, 0.10, 0.10);
}

Pit::~Pit() {
}

void Pit::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Pit::receiveCarCollision(Player* car) {
    kill();
    car->resetPosition();
    
}
