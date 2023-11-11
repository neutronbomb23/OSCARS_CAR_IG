
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game *game, ofNode otherTransform)
:GameObject(game, otherTransform.getGlobalPosition(), glm::vec3(10))
{
    transform.setGlobalOrientation(otherTransform.getGlobalOrientation());
    material.setEmissiveColor(ofColor::red);
    creationTime = ofGetElapsedTimef();
}

Bullet::~Bullet(){}

void Bullet::update(){
    transform.move(transform.getZAxis() * 100);
    float currentTime = ofGetElapsedTimef();
    if (currentTime - creationTime >= 2.0f)
    {
        kill();
    }
};

void Bullet::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
    
};

void Bullet::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveBulletCollision(this);
    }
}
