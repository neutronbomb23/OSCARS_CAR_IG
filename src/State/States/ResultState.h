#ifndef ResultState_h
#define ResultState_h

#include "State.h"
#include "./Player.h"
#include "PlayState.h"
class Game;

class ResultState : public State {
public:
    ResultState(Game* game);
    float totalTime;
    ~ResultState();

    void update();
    void draw();
    void next();
    Player* pla;
    PlayState* playState;
    ofTrueTypeFont font;
    ofSoundPlayer song;
};

#endif /* ResultState_h */
