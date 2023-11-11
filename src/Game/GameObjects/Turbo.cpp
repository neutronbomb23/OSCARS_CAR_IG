#include "Turbo.h"
#include "Player.h"

Turbo::Turbo(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("FE.dae");
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -30, 0);
    model.setScale(0.2, 0.2, 0.2);
}

Turbo::~Turbo() {}

void Turbo::receiveCarCollision(Player* car) {
    car->turbo();
    kill();
}

void Turbo::update() {
    model.update();
}

void Turbo::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}