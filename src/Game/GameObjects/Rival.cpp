#include "Rival.h"
#include "Bullet.h"
#include "Player.h"
#include <cstdlib>

Rival::Rival(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("Car.dae");
    model.setRotation(0, 180, 1, 0, 180);
    model.setPosition(-3, -35, -20);
    model.setScale(0.5, 0.5, 0.5);
    collider->setWidth(130);
    collider->setHeight(80);
    collider->setDepth(220);
    // define a fixed speed for the rival
    speed = 5.0f;
    reducedTime = 2.0f;
}

Rival::~Rival() {}

void Rival::receiveCarCollision(Player* car) {
    car->stop();
    car->explosionSound();
}

void Rival::update() {
    model.update();
    transform.move(0, 0, speed);
    collider->setPosition(model.getPosition());
    if (this->transform.getZ() > 20000){
        game->playerLoses();
        game->finishGame();
    }

    if (estadecelerando) {
        speed = 2.0f;

        if (ofGetElapsedTimef() - reducedTime >= 2.0f) {
            estadecelerando = false;  // Desactivar turbo
            speed = 5.0f;  // Reducir la velocidad
        }
    }
}

void Rival::decelerar() {
    estadecelerando = true;
    reducedTime = ofGetElapsedTimef();
}

void  Rival::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
    decelerar();
};

void Rival::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}