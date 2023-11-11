#include "Bomb.h"
#include "Player.h"
#include <cstdlib>

Bomb::Bomb(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("bomb.dae");
    model.setRotation(0, 270, 0, 0, 1);
    model.setPosition(0, 0, 0);
    model.setScale(0.1, 0.1, 0.1);
}

Bomb::~Bomb() {}

void Bomb::update() {
    model.update();
    transform.move(0, -5, 0);
    collider->setPosition(model.getPosition());
    if (transform.getY() < -10) {
        game->getPlayer()->receiveBombCollision(this);
        kill();
    }
}

void Bomb::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

