#include "Plane.h"
#include "Bomb.h"
#include <cstdlib>

Plane::Plane(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("plane.dae");
    model.setRotation(0, 270, 1, 0, 1);
    model.setPosition(0, 30, 0);
    model.setScale(0.5, 0.5, 0.5);
    velocity = glm::vec3(0, 0, 0); // velocidad inicial
    timeCounter = 0;
}

Plane::~Plane() {}

void Plane::update() {
    model.update();

    transform.setPosition(transform.getPosition() + velocity);

    timeCounter += ofGetLastFrameTime();
    if (this->transform.getZ() == 20000) {
        transform.move(0, 0, -20);
    }
    if (timeCounter > 4) {
        velocity = glm::vec3(0, 0, ofRandom(-15, 15));
        timeCounter = 0;
        Bomb* bomb = new Bomb(game, glm::vec3(transform.getX(), transform.getY() , transform.getZ()), glm::vec3(50));
        game->addGameObject(bomb);
    }
}

void Plane::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}