#include "Crane.h"
#include "Player.h"
#include <cstdlib>

Crane::Crane(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("lamp.dae");
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(pos.x, pos.y, pos.z);
    model.setScale(1.5, 1, 1.5);

    hook = new Hook(game, pos, dim, this);
    game->addGameObject(hook);
}

Crane::~Crane() {}

void Crane::receiveCarCollision(Player* car) {
    car->brake();
    car->explosionSound();
}

void Crane::update() {
    model.update();
    transform.rotateDeg(2, glm::vec3(0, 1, 0));
}

void Crane::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}