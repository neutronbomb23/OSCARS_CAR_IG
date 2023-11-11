#include "Obstacle.h"
#include "Player.h"
#include <cstdlib>

Obstacle::Obstacle(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("cat.dae");
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -30, 0);
    model.setScale(0.5, 0.5, 0.5);
}

Obstacle::~Obstacle() {}

void Obstacle::receiveCarCollision(Player* car) {
    car->stop();
    car->explosionSound();
}

void Obstacle::update(){
    model.update();
}

void Obstacle::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
};

void Obstacle::draw(){
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}