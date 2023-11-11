#include "Fence.h"
#include "Player.h"
#include <cstdlib>

Fence::Fence(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos), lastMoveTime(ofGetElapsedTimef()), worldPos(pos) {
    model.loadModel("fence.fbx");
    model.setRotation(0, 180, 1, 0, 1);
    model.setPosition(0, 0, 0);
    model.setScale(0.5, 0.5, 0.5);
    material.setDiffuseColor(ofColor::yellow);
    movingUp = false;
    initialY = -30;   
    collider->setParent(transform);
    collider->setDepth(200);
    collider->setHeight(700);
    collider->setScale(3, 4, 2);
    collider->setWidth(400);
}

Fence::~Fence() {}

void Fence::update() {
    float currentTime = ofGetElapsedTimef();
    float timeDiff = currentTime - lastMoveTime;
    float yPos = worldPos.y;

    if (!movingUp && timeDiff >= 5.0f) {
        // Mover el objeto hacia arriba.
        yPos += 10.0f;
        worldPos.y = yPos;
        model.setPosition(model.getPosition().x, yPos, model.getPosition().z);
        if (yPos >= initialY + 2000) {
            lastMoveTime = currentTime;
            movingUp = true;
        }
    }
    else if (movingUp && timeDiff >= 2.0f) {
        // Mover el objeto hacia abajo.
        yPos -= 10.0f;
        worldPos.y = yPos;
        model.setPosition(model.getPosition().x, yPos, model.getPosition().z);
        if (yPos <= initialY) {
            lastMoveTime = currentTime;
            movingUp = false;
        }
    }

    model.update();
    collider->setPosition(model.getPosition());
}

void Fence::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Fence::receiveCarCollision(Player* car) {
    car->stop();
    car->explosionSound();
}


void Fence::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
    kill();
}