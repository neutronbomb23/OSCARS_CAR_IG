#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"

ResultState::ResultState(Game* game) : State(game, "Result State") {
    totalTime = game->getTotalPlayedTime();
    font.load("Foldit.ttf", 24); // Carga la fuente en el tamaño deseado
    song.load("ounana.mp3");
    song.setVolume(0.3);
    song.play();
};

ResultState::~ResultState() {};

void ResultState::update() {
    if (ofGetKeyPressed(OF_KEY_TAB))
        game->setState(new PlayState(game));
};

void ResultState::draw() {
    ofBackground(0, 0, 0, 0);
    font.drawString(name, 10, 50); // Nombre del estado
    font.drawString("Time played: " + ofToString(totalTime), 10, 100);// Tiempo guardado
    font.drawString("Coins: " + ofToString(game->getPlayer()->getCoins()), 10, 150);// Monedas conseguidas
    if (game->didPlayerWin()) {
        font.drawString("Has ganado!", 10, 200); // Mensaje de victoria
    }
    else {
        font.drawString("Has perdido", 10, 200); // Mensaje de derrota
    }
    font.drawString("Press TAB to play again.", 10, 250); // Mensaje para jugar de nuevo
}

void ResultState::next() {
    game->setState(new MenuState(game));
};
