#include "Game.h"
#include "Player.h"



Game::Game(){
    // TODO create settings
    ROAD_WIDTH = 2000;
    ROAD_LENGTH = 10000;

    generator = new GameObjectGenerator(this);
    bDebug = false;
    scream.load("aaa.wav");
    lastPedestrianTime = ofGetElapsedTimef();
    pedestrianInterval = 20.0f;
}

Game::~Game(){
    ofLogNotice() << "Deleting game";
    delete gameObjects;
    delete generator;
    delete currentState();
}

void Game::init(){
    if(gameObjects != nullptr)
        delete gameObjects;
    
    gameObjects = new GameObjectContainer();
    
    player = new Player(this);
    player->init();
    miniMapCam.setFarClip(100000);
    miniMapCam.setFov(90);
    cam.setPosition(0, 300, -600);
    cam.setTarget(player->transform);
    cam.setParent(player->transform);
    cam.setFarClip(100000);
    
    gameObjects->add(player);
    generator->generateWorld();
    bPlayerFinish = false;
    initTime = ofGetElapsedTimef();
}

void Game::update(){
    gameObjects->update();
    elapsedTime = ofGetElapsedTimef() - initTime;
    miniMapCam.setPosition(player->transform.getPosition().x, 1000, player->transform.getPosition().z);
    miniMapCam.lookAt(player->transform.getPosition());
    if (ofGetElapsedTimef() - lastPedestrianTime >= pedestrianInterval) {
        generator->addPedestrian();
        lastPedestrianTime = ofGetElapsedTimef();
    }
}

void Game::draw(){
    ofEnableLighting();
    ofEnableDepthTest();
    
    cam.begin();
    {
        if(bDebug) gameObjects->drawDebug();
        else gameObjects->draw();
    }
    cam.end();

    ofPushMatrix();
    {
        ofViewport(ofGetWidth() - 200, 0, 200, 200);
        miniMapCam.begin();
        gameObjects->draw();
        miniMapCam.end();
    }
    ofPopMatrix();
    ofViewport(0, 0, ofGetWidth(), ofGetHeight());
    ofDisableLighting();
    ofDisableDepthTest();
}


Player * Game::getPlayer(){
    return player;
}

vector<GameObject *> Game::getCollisions(GameObject *gameObject){
    return gameObjects->getCollisions(gameObject);
}

void  Game::addGameObject(GameObject *gameobject){
    gameObjects->add(gameobject);
}

void Game::finishGame(){
    bPlayerFinish = true;
}

void Game::toggleDebug(){
    bDebug = !bDebug;
}

bool Game::isFinished(){
    return bPlayerFinish;
}

void Game::setFinished(bool v){
    bPlayerFinish = v;
}

float Game::getEllapsedTime(){
    return ofGetElapsedTimef() - initTime;
}

void Game::doScream(){
    scream.play();
}

void Game::stopTime() {
    elapsedTimePaused = elapsedTime;
    pausedTime = elapsedTimePaused;
    pauseStartTime = ofGetElapsedTimef(); // Registramos el inicio de la pausa
}

void Game::resumeTime() {
    elapsedTime = elapsedTimePaused;
    initTime = ofGetElapsedTimef() - elapsedTime;
    totalPauseTime += ofGetElapsedTimef() - pauseStartTime; // Sumamos el tiempo de esta pausa al total
}

float Game::getTotalPlayedTime() {
    return ofGetElapsedTimef() - initTime - totalPauseTime;
}