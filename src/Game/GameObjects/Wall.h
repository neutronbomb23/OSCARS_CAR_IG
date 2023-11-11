#ifndef Wall_h
#define Wall_h

#include "GameObject.h"

class Pedestrian;

class Wall : public GameObject{
    
    
public:
    Wall(Game* game, glm::vec3 pos, glm::vec3 dim, bool isLeftWall);
    ~Wall();
    bool isLeftWall;
    void draw() override;
    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;
    void receivePedestrianCollision(Pedestrian *pedestrian) override;
    
};

#endif

