#pragma once
#include "ofxAssimpModelLoader.h"
#include "GameObject.h"
class Fence : public GameObject
{
private:
	ofxAssimpModelLoader model; 
	float lastMoveTime;
	bool movingUp;
	float initialY;
	Player* player;
	glm::vec3 worldPos;
public:
	Fence(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Fence();
	void receiveCarCollision(Player* car);
	void receiveBulletCollision(GameObject* bullet);
	void update();
	void draw();
};

