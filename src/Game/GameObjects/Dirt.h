#ifndef Dirt_h
#define Dirt_h

#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Dirt : public GameObject {
public:
    Dirt(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Dirt();

    void update();

    void draw() override;
    void receiveCarCollision(Player* car) override;

private:
    ofxAssimpModelLoader model;
    ofTexture dirtTexture;
};

#endif /* Dirt_h */
