#ifndef Obstacle_h
#define Obstacle_h
#include "ofxAssimpModelLoader.h"
#include "GameObject.h"

class Obstacle : public GameObject {
public:
    Obstacle(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Obstacle();

    void receiveCarCollision(Player* car) override;

    void update();

    void receiveBulletCollision(GameObject* bullet);

    void draw();

private:
    ofxAssimpModelLoader model;
    ofLight faro;
};

#endif
