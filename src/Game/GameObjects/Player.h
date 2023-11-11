#ifndef Player_h
#define Player_h
#include "ofxAssimpModelLoader.h"
#include "Bomb.h"
#include "ofMain.h"
#include "GameObject.h"
class Game;
// TODO add speed settings
#define MAX_SPEED 10

class Player : public GameObject{
    ofLight faro;
    float speed;
    bool turboEnable = false;
    float  turboIniTime;
    bool bLight;
    glm::vec3 prevPos;
    ofxAssimpModelLoader model;
    bool skidding = false;
    bool reduced = false;
    float skidTime;
    float skidStartTime;
    float skidStartT;
    ofSoundPlayer explosion;

    bool spinning = false;
    float spinEndTime;
    int spinStrenght = 1;

public:
    int coins;
    Player(Game *game);
    ~Player();
    void init();
    void update() override;
    void startSkidding();
    void reduceSpeedOnDirt();
    void draw() override;
    void drawDebug() override;
    void checkCollisions() override;
    float getSpeed();
    void resetPosition();
    void explosionSound();
    void steerLeft();
    void steerRight();
    void accelerate();
    void toggleLight();
    void shoot();
    void turbo();
    void turnAround();
    void loseAllCoins();
    void receiveBombCollision(Bomb* bomb);
    void brake();
    void stop();
    void addCoins(int n = 1);
    int getCoins();
    void changeModel(const std::string& newModelPath);

    void spin(int durationMs, int intensity = 1);
};

#endif 
