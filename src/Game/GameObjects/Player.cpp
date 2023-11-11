#include "Player.h"
#include "Game.h"


const int SKID_TIME = 5000; // Duración del derrape en milisegundos
const float SKID_AMOUNT = 0.5; // Máxima cantidad de desplazamiento durante el derrape

Player::Player(Game* game) :GameObject(game, glm::vec3(100)) {
    model.loadModel("Car.dae");
    model.setRotation(0, 180, 1, 0, 180);
    model.setPosition(-3, -35, -20);
    model.setScale(0.3, 0.3, 0.3);
    collider->setWidth(130);
    collider->setHeight(80);
    collider->setDepth(220);
    material.setDiffuseColor(ofColor::blue);
    faro.setParent(transform);
    faro.setDiffuseColor(ofColor::yellow);
    faro.setSpotlight();
    faro.move(0, 0, 50);
    faro.rotateDeg(-200, 1, 0, 0);
    explosion.load("explo.mp3");
    explosion.setVolume(0.2);
    skidStartTime = 0.0f;  // Inicialización de skidStartTime
}

Player::~Player() {}

void Player::init() {
    transform.setPosition(0, 0, 1000);
    speed = 0;
    bLight = false;
    coins = 0;
}

void Player::update() {
    prevPos = transform.getPosition();
    transform.move(transform.getZAxis() * speed);
    model.update();

    if (speed > MAX_SPEED) speed = MAX_SPEED;
    if (speed < 0) speed = 0;

    if (skidding) { // Generar un número aleatorio entre -5.0 y 5.0
        float direction = 1;
        if (rand() % 2 == 0) direction = -1;

        if(skidStartT + 400 <= ofGetCurrentTime().getAsMilliseconds()) spin(400, direction);

        // Comprobar si han pasado 5 segundos
        if (ofGetElapsedTimef() - skidStartTime >= 5.0f) {
            skidding = false;
        }
    }

    if (turboEnable) {
        speed += 1;

        if (ofGetElapsedTimef() - turboIniTime >= 2.0f) {
            turboEnable = false;  // Desactivar turbo
            speed -= 0.5;  // Reducir la velocidad
        }
    }

    if (reduced) {
        if (speed <= 2.0) {
            speed = 2.0;
            reduced = false;
        }
    }

    if (spinning) {
        transform.rotate(spinStrenght, 0, 1, 0);
        if (ofGetCurrentTime().getAsMilliseconds() >= spinEndTime) {
            spinning = false;
        }
    }
}


void Player::turbo() {
    turboEnable = true;
    turboIniTime = ofGetElapsedTimef();
}

void Player::startSkidding() {
    skidding = true;
    skidStartTime = ofGetElapsedTimef(); 
    skidStartT = ofGetCurrentTime().getAsMilliseconds();
}


void Player::reduceSpeedOnDirt() {
    reduced = true;
    speed *= 0.90;
}

void Player::resetPosition() {
    transform.setPosition(0, 0, 200);
    speed = 0;
    transform.rotate(-180, 0, 1, 0);
}

void Player::explosionSound() {
    explosion.play();
}

void Player::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
    faro.draw();
    if (bLight)
        faro.enable();
    else
        faro.disable();
}

void Player::drawDebug() {
    collider->drawDebug();
    transform.transformGL();
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::checkCollisions() {
    vector<GameObject*> collisions = game->getCollisions(this);
    for (auto c : collisions) {
        c->receiveCarCollision(this);
    }
}

void Player::steerLeft() {
    transform.rotateDeg(1, 0, 2, 0);
}

void Player::steerRight() {
    transform.rotateDeg(-1, 0, 2, 0);
}

void Player::accelerate() {
    speed += 0.5;
}

void Player::brake() {
    speed -= 0.2;
    if (speed < 0) {
        speed = 0;
    }
}

void Player::stop() {
    speed = 0;
    transform.setPosition(prevPos);
}

void Player::toggleLight() {
    bLight = !bLight;
}

float Player::getSpeed() {
    return speed;
}

void Player::addCoins(int n) {
    coins += n;
}

int Player::getCoins() {
    return coins;
}

void Player::changeModel(const std::string& newModelPath) {
    model.clear();
    model.loadModel(newModelPath);

    if (newModelPath == "Car.dae"){
        model.setRotation(0, 180, 1, 0, 180);
        model.setScale(0.3, 0.3, 0.3);
        model.setPosition(-3, -35, -20);
    }
    else {
        model.setRotation(0, 180, 1, 0, 1);
        model.setScale(0.2, 0.2, 0.2);
        model.setPosition(-40, -35, -50);
    }
}

void Player::shoot() {
    if (coins > 0) {
        game->addGameObject(new Bullet(game, transform));
        coins -= 1;
    }
}


void Player::turnAround() {
    transform.rotate(-180, 0, 1, 0);
}

void Player::loseAllCoins() {
    coins = 0;
}

void Player::receiveBombCollision(Bomb* bomb) {
    float distance = glm::distance(transform.getPosition(), bomb->transform.getPosition());
    if (distance >= 250 && distance <= 650) {
        this->spin(2500, 4);
        speed = 0;
    }
    else if (distance < 249) {
        this->resetPosition();
    }
}

void Player::spin(int durationMs, int intensity) {
    spinEndTime = ofGetCurrentTime().getAsMilliseconds() + durationMs;
    spinStrenght = intensity;
    spinning = true;
}