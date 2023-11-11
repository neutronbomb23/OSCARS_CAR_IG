#include "ArcoLoco.h"
#include "Game.h"
#include "Bullet.h"
#include "Player.h"

ArcoLoco::ArcoLoco(Game* game, glm::vec3 pos, glm::vec3 dim) :
    GameObject(game, pos, dim) {
    pos_ = pos;
    model.loadModel("balloon.obj");
    model.setRotation(0, 90, 1, 0, 0);  
    model.setPosition(0, 0, 0);
    model.setScale(3.0, 6.0, 3.0);
    collider->setScale(1.2);
    collider->setWidth(2000);
    fbo.allocate(pos.x, pos.z, GL_RGBA);
    //material.setDiffuseColor(ofColor::blue);
}

ArcoLoco::~ArcoLoco() {}

void ArcoLoco::update() {
    model.update();
    currentTime = ofGetElapsedTimeMillis();
    if (currentTime - previousTime >= 1000) {
        num = ofRandom(0, 100);
        previousTime = currentTime;
    }
    //fbo.begin();
    //ofClear(0, 0, 0, 0);
    //ofSetColor(255, 0, 0);
    //ofDrawRectangle(pos_.x, pos_.y, 1000, 1000);
    ////Dibuja un número aleatorio en la textura
    //ofSetColor(0);
    //ofDrawBitmapString(ofToString(num), fbo.getWidth() / 2, fbo.getHeight() / 2);
    //fbo.end();
}

void ArcoLoco::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();

    material.begin();
    {
        //collider->draw();
    }
    material.end();

    fbo.draw(pos_.x, pos_.y);
}

void ArcoLoco::receiveCarCollision(Player* car) {
    car->addCoins(num);
}