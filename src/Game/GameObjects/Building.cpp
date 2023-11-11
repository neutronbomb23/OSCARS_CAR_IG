#include "Building.h"
#include "Game.h"

Building::Building(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    model.loadModel("building_04.dae");
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -30, 0);
    model.setScale(0.1, 0.1, 0.1);
}

Building::~Building() {}

void Building::draw() {
    model.drawFaces();
}

void Building::update() {
    model.update();
    collider->setPosition(model.getPosition());
}