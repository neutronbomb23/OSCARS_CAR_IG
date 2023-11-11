#ifndef PlayState_h
#define PlayState_h
#include "Coin.h"
#include "State.h"
#include "Game.h"

class PlayState : public State {
private:
    bool paused = false;
    float pausedTime = 0.0f;
    float pauseStartTime;
    ofSoundPlayer song;
    ofSoundPlayer caracc;
    bool isPlaying = false;
    const int DELAY_PRESSED = 500;
    int nextTimePressPause = 0;
    bool canMove;
    int countdown;
    int countdownEndTime;
    ofTrueTypeFont font;
    ofTrueTypeFont font1;
    Coin* coin;
    GameObjectGenerator* go;

public:
    PlayState(Game* game);
    float totalTime;
    ~PlayState() {};
    void update();
    void draw();
    void next();
    void keyPressed(int key);
};
#endif