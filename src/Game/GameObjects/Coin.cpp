#include "Coin.h"
#include "Player.h"
#include "Game.h"


Coin::Coin(Game *game, glm::vec3 pos, glm::vec3 dim):
    GameObject(game, pos, dim){
    material.setDiffuseColor(ofColor::yellow);
        
 
    
}
Coin::~Coin(){
    
}


void Coin::update(){
    model.update();
}

void Coin::draw(){
   
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Coin::receiveCarCollision(Player *car){
    car->addCoins(5);
    kill();
}

void Coin::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    kill();
    game->getPlayer()->addCoins(100);
}

void Coin::changeColor(ofColor newColor) { //Método para cambiar el color.
  
    material.setDiffuseColor(newColor);
}
