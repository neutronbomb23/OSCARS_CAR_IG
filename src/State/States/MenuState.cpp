#include "PlayState.h"
#include "MenuState.h"

MenuState::MenuState(Game* game) : State(game, "Menu State") {
    font.load("Foldit.ttf", 24);
}

void MenuState::update(){
    if (ofGetKeyPressed(' '))
        next();
};
    
void MenuState::draw(){
    ofBackground(0);
    font.drawString(name, 10, 30);
    font.drawString("Press Space To Play", 10, 80);
};

void MenuState::next(){
    if (ofGetKeyPressed(' '))
        game->setState(new PlayState(game));
};
