#include "TPVCar.h"

TPVCar::TPVCar(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    model.loadModel("Car.dae");
    model.setRotation(0, 180, 1, 0, 180);
    model.setPosition(-3, -35, -20);
    model.setScale(0.5, 0.5, 0.5);
    collider->setWidth(130);
    collider->setHeight(80);
    collider->setDepth(220);
    reducedTime = 2.0f;
    distanceNextDir = delayDistance;
}

TPVCar::~TPVCar() {}

void TPVCar::receiveCarCollision(Player* car) {
    car->resetPosition();
    car->explosionSound();
}

void TPVCar::update() {
    if (distanceNextDir <= 0) {
       velocity.x = -velocity.x;
       distanceNextDir = 2 * delayDistance;
    }
    else {
        distanceNextDir -= abs(velocity.x);
    }

    model.update();
    transform.move(velocity.x, velocity.y, velocity.z);
    collider->setPosition(model.getPosition());
    
    if (estadecelerando) {
        velocity.z = 5.0f;
        if (ofGetElapsedTimef() - reducedTime >= 2.0f) {
            estadecelerando = false;  // Desactivar turbo
            velocity.z = 15.0f;  // Reducir la velocidad
        }
    }
}

//void TPVCar::update() {
//    // Determine if the car needs to change direction
//    if (transform.getPosition().x > maxX || transform.getPosition().x < minX) {
//        velocity.x = -velocity.x;
//    }
//
//    // Move the car
//    transform.move(velocity.x, velocity.y, velocity.z);
//
//    // Update model and move the car
//    model.update();
//
//    // Update the position of the collider
//    collider->setPosition(model.getPosition());
//
//    if (estadecelerando) {
//        velocity.z = 5.0f;
//        if (ofGetElapsedTimef() - reducedTime >= 2.0f) {
//            estadecelerando = false;  // Disable turbo
//            velocity.z = 15.0f;  // Reduce the speed
//        }
//    }
//}

void TPVCar::decelerar() {
    estadecelerando = true;
    reducedTime = ofGetElapsedTimef();
}

void  TPVCar::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
    decelerar();
};

void TPVCar::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}