

#ifndef iColllide_h
#define iColllide_h

#include "ofMain.h"
#include "BoxCollider.h"

class Player;
class Pedestrian;

class iCollide{
    
    protected:
        BoxCollider *collider;

    public:
    
    virtual void receiveCarCollision(Player *car) {};
    virtual void receiveBulletCollision(GameObject *bullet) {};
    virtual void receivePedestrianCollision(Pedestrian *pedestrian) {};
        
    BoxCollider* getCollider(){
        return collider;
    }
        
    bool collide(iCollide *other){
        return collider->collide(other->getCollider());
    }
};

#endif /* iColllide_h */
