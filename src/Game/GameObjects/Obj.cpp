#include "Obj.h"
#include "Player.h"
#include "Game.h"

Obj::Obj(Game *game, glm::vec3 pos, glm::vec3 dim):
    GameObject(game, pos, dim){
    
    material.setDiffuseColor(ofColor::blue);
}

Obj::~Obj(){
    
}

void Obj::update(){
    model.update();
}

void Obj::draw(){
    material.begin();
    {
        ofDrawIcoSphere(transform.getX(), transform.getY(), transform.getZ(), 50);
    }
    material.end();
}

void Obj::receiveCarCollision(Player *car){
    if (rand() % 2 == 0)
        car->spin(2000, 1);
    else
        car->spin(2000, -1);
    kill();
}

void Obj::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    kill();
    game->getPlayer()->addCoins(100);
}

void Obj::changeColor(ofColor newColor) { //Método para cambiar el color.
    material.setDiffuseColor(newColor);
}