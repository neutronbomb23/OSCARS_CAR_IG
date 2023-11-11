#include "PlayState.h"
#include "ResultState.h"
#include "Player.h"

PlayState::PlayState(Game* game) : State(game, "Play State") {
    game->init();
    song.load("ounana.mp3");
    caracc.load("caracc.wav");
    caracc.setVolume(0.3);
    song.setVolume(0.1);
    song.play();

    canMove = false; // The player can't move until the countdown is over
    countdown = 3; // Initialize the countdown
    countdownEndTime = ofGetElapsedTimeMillis() + 1000; // Each second, the countdown will decrease

    // Load the font and set its size
    font.load("Foldit.ttf", 14); // Adjust the size (14) according to your needs
    font1.load("Foldit.ttf", 25); // Adjust the size (25) according to your needs
};

void PlayState::update() {
    if (!paused) {
        if (!canMove) {
            if (ofGetElapsedTimeMillis() >= countdownEndTime) {
                countdown--;
                countdownEndTime = ofGetElapsedTimeMillis() + 1000;
            }
            if (countdown <= 0) {
                canMove = true;
            }
        }
        else {
            game->update();

            if (ofGetKeyPressed(OF_KEY_F1))
                game->getPlayer()->changeModel("Car.dae");
            else if (ofGetKeyPressed(OF_KEY_F2))
                game->getPlayer()->changeModel("taxi.fbx");
            else if (ofGetKeyPressed(OF_KEY_F3))
                game->getPlayer()->changeModel("policecar.fbx");
            else if (ofGetKeyPressed(OF_KEY_F4))
                coin->changeColor(ofColor::paleVioletRed);
                
            if (canMove) {
                if (ofGetKeyPressed(OF_KEY_LEFT))
                    game->getPlayer()->steerLeft();
                if (ofGetKeyPressed(OF_KEY_RIGHT))
                    game->getPlayer()->steerRight();

                if (ofGetKeyPressed(OF_KEY_UP)) {
                    game->getPlayer()->accelerate();
                    if (!caracc.isPlaying()) {
                        caracc.play();
                    }
                }
                else {
                    caracc.stop();
                }

                if (ofGetKeyPressed(OF_KEY_DOWN))
                    game->getPlayer()->brake();
            }

            if (ofGetKeyPressed(OF_KEY_BACKSPACE))
                game->getPlayer()->toggleLight();

            if (ofGetKeyPressed(OF_KEY_CONTROL) && nextTimePressPause <= ofGetCurrentTime().getAsMilliseconds()) {
                paused = true;
                song.setPaused(true);
                game->stopTime();
                nextTimePressPause = ofGetCurrentTime().getAsMilliseconds() + DELAY_PRESSED;
                pauseStartTime = ofGetCurrentTime().getAsSeconds();
            }
        }
    }
    else {
        pausedTime = ofGetCurrentTime().getAsSeconds() - pauseStartTime;
        if (ofGetKeyPressed(OF_KEY_CONTROL) && nextTimePressPause <= ofGetCurrentTime().getAsMilliseconds()) {
            paused = false;
            song.setPaused(false);
            game->resumeTime();
            nextTimePressPause = ofGetCurrentTime().getAsMilliseconds() + DELAY_PRESSED;
        }
    }
}

void PlayState::draw() {
    ofBackground(0, 70, 70, 0);
    ofPushMatrix();
    {
        ofTranslate(10, 0);
        ofTranslate(0, 20);
        font.drawString("Fps: " + ofToString(ofGetFrameRate()), 0, 0);
        ofTranslate(0, 20);
        font.drawString(name, 0, 0);
        ofTranslate(0, 20);

        if (!paused) {
            font.drawString("Time: " + ofToString(game->getEllapsedTime(), 2), 0, 0);
        }
        else {
            font.drawString("Time: " + ofToString(game->getEllapsedTime() - pausedTime, 2), 0, 0);
        }    
        ofTranslate(0, 20);
        font.drawString("Speed: " + ofToString(game->getPlayer()->getSpeed(), 2), 0, 0);
        ofTranslate(0, 20);
        font.drawString("Coins: " + ofToString(game->getPlayer()->getCoins(), 2), 0, 0);
    }

    ofPopMatrix();
    game->draw();

    if (!canMove) {
        std::string countdownText = "Countdown: " + ofToString(countdown);
        int textWidth = countdownText.size() * 8;  // Approximate width of a character
        int textHeight = 14;  // Approximate height of a character
        ofTranslate(ofGetWidth() / 2 - textWidth, ofGetHeight() / 2 + textHeight / 2);
        font1.drawString(countdownText, 0, 0);
    }
};

void PlayState::next() {
    game->setState(new ResultState(game));
};

void PlayState::keyPressed(int key) {
    if (key == 'l' || key == 'L')
        game->getPlayer()->toggleLight();
    if (key == 'd' || key == 'D')
        game->toggleDebug();
    if (key == ' ' && canMove)
        game->getPlayer()->shoot();
}