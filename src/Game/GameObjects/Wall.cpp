#include "Wall.h"
#include "Player.h"
#include "Pedestrian.h"

Wall::Wall(Game* game, glm::vec3 pos, glm::vec3 dim, bool isLeftWall)
    : GameObject(game, pos, dim), isLeftWall(isLeftWall) {
    material.setEmissiveColor(ofColor::darkorange);
}


Wall::~Wall(){}

void Wall::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}



void  Wall::receiveCarCollision(Player *car){
    car->stop();
    car->explosionSound();
    if (isLeftWall && car->transform.getX() < transform.getX() || !isLeftWall && car->transform.getX() > transform.getX()) {
        car->resetPosition();
    }
}

void  Wall::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
};

void Wall::receivePedestrianCollision(Pedestrian *pedestrian){
   pedestrian->turn();
}