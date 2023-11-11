
#ifndef Bullet_h
#define Bullet_h

#include "GameObject.h"

class Bullet : public GameObject{
private:
    float lastMoveTime;
    float creationTime;
public:
    Bullet(Game *game, ofNode transform);
    ~Bullet();
    
    void update() override;
    void draw() override;
    void checkCollisions() override;
    
};
#endif /* Bullet_h */
