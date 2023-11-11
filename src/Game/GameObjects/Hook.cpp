#include "Hook.h"
#include "Player.h"
#include "Crane.h"
#include <cstdlib>

Hook::Hook(Game* game, glm::vec3 pos, glm::vec3 dim, Crane* c) : GameObject(game, pos) {
    model.loadModel("hammer.dae");  // Asegúrate de tener un modelo 3D para el gancho
    model.setRotation(0, 0, 0, 0, 0);
    hookPosition = glm::vec3(0, 250, 300); // Establece la posición inicial del gancho
    model.setScale(0.2, 0.2, 0.2);  // Escala el gancho si es necesario

    transform.setParent(c->transform); // Vincula el gancho a los movomientos del poste
}

Hook::~Hook() {}

void Hook::receiveCarCollision(Player* car) {
    car->loseAllCoins();
    car->explosionSound();
}

void Hook::update() {
    model.update();

    // Cambia el movimiento del gancho aquí
    hookPosition.y = hookY + (sin(ofGetElapsedTimef()) * 150);
    model.setPosition(hookPosition.x, hookPosition.y, hookPosition.z);  // Corrección aquí

    collider->setPosition(model.getPosition() - glm::vec3(0, 150, 0));
}



void Hook::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Hook::translate(glm::vec3 pos, float distance) {
    model.setPosition(pos.x, hookPosition.y, pos.z);
}
