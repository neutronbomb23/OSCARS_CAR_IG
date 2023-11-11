#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"
#include "Rival.h"
class Player;

class Game : public StateMachine{
    ofEasyCam cam;
    ofCamera miniMapCam;
    Player *player;

    GameObjectContainer *gameObjects = nullptr;
    GameObjectGenerator *generator  = nullptr;
    bool bDebug;
    bool bPlayerFinish;
    float pausedTime;
    float initTime;
    float elapsedTime;
    float elapsedTimePaused;
    ofSoundPlayer scream;
    float totalPauseTime = 0.0f;
    float pauseStartTime = 0.0f;
    float lastPedestrianTime;
    float pedestrianInterval;
    bool playerWon;
    Rival* ri;

public:
    int ROAD_LENGTH;
    int ROAD_WIDTH;
    
    Game();
    ~Game();
    void init();
    void update();
    void draw();
    void finishGame();
    void toggleDebug();
    bool isFinished();
    void setFinished(bool v);

    void playerWins() { playerWon = true; }
    void playerLoses() { playerWon = false; }
    bool didPlayerWin() { return playerWon; }

    Player *getPlayer();
    vector<GameObject *> getCollisions(GameObject *gameObject);
    void addGameObject(GameObject *gameobject);
    
    void doScream();

    void stopTime();
    void resumeTime();
    float getEllapsedTime();
    float getTotalPlayedTime();
};
#endif