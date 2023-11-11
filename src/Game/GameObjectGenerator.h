#ifndef GameObjectGenerator_h
#define GameObjectGenerator_h

#include "ofMain.h"
class Game;

class GameObjectGenerator{
    
public:
    GameObjectGenerator(Game *game);
    Game* game;
    void generateWorld();
    void addPedestrian();
};

#endif