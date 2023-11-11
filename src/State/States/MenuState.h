#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"

class MenuState: public State{
private:
    ofTrueTypeFont font;

public:
    MenuState(Game* game);
    
    ~MenuState(){};
    
    void update();
    void draw();
    void next();
};
#endif 