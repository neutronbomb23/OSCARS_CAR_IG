#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Building.h"
#include "Fence.h"
#include "Dirt.h"
#include "Obstacle.h"
#include "Rival.h"
#include "Coin.h"
#include "Turbo.h"
#include "Oil.h"
#include "Crane.h"
#include "Plane.h"
#include "Pit.h"
#include "ofMain.h"
#include "Pedestrian.h"
#include "ArcoLoco.h"
#include "TPVCar.h"
#include "Obj.h"

GameObjectGenerator::GameObjectGenerator(Game* game) : game(game) {}

void GameObjectGenerator::generateWorld() {
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;

    glm::vec3 roadPos(0, -50.1, L / 2 + 10000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));

    game->addGameObject(road);
    //
    int wallSize = 100;

    ofImage circuito;
    circuito.load("circuito.png");

    int w = circuito.getWidth() / 16;
    int h = circuito.getHeight() / 16;
    circuito.resize(w, h);

    //    for(int x = 0; x < w; x++){
    //        for(int y = 0; y < h; y++){
    //            if(circuito.getColor(x, y).a > 250){
    //                auto wall = new Wall(game,
    //                                glm::vec3(x*wallSize - 5000, roadPos.y, y*wallSize -2000),
    //                                glm::vec3(wallSize*0.99));
    //                game->addGameObject(wall);
    //            }
    //        }
    //    }


    //     WALL with parts
    //    for(int l = 0; l < L; l += wallSize){
    //        auto wall_r = new Wall(game,
    //                        glm::vec3(-W/2, roadPos.y, l - 1000 + wallSize/2),
    //                        glm::vec3(wallSize));
    //        wall_r->isFixed = true;
    //        game->addGameObject(wall_r);
    //
    //    }


        // Goal
    glm::vec3 goal_pos(0, roadPos.y, roadPos.z + L / 2);
    auto goal = new Goal(game,
        goal_pos,
        glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);

    // Coins
    int numCoins = 10;
    for (int i = 0; i < numCoins; ++i) {
        float x = ofRandom(-W / 2 + wallSize, W / 2 - wallSize);
        float z = ofRandom(roadPos.z - L, roadPos.z + L / 2);
        auto coin = new Coin(game, glm::vec3(x, -25, z), glm::vec3(50));
        // coin->changeColor(ofColor::red);
        game->addGameObject(coin);
    }

    // Oil
    int numOil = 2;
    for (int i = 0; i < numOil; ++i) {
        float x = ofRandom(-W / 2 + wallSize, W / 2 - wallSize);
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto oil = new Oil(game, glm::vec3(x, -25, z), glm::vec3(50));
        game->addGameObject(oil);
    }

    // Obstacles
    int numObstacles = 4;
    for (int i = 0; i < numObstacles; ++i) {
        float x = ofRandom(-W / 2 + wallSize, W / 2 - wallSize);
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto obstacles = new Obstacle(game, glm::vec3(x, -25, z), glm::vec3(50));
        game->addGameObject(obstacles);
    }

    // Dirt
    int numDirt = 3;
    for (int i = 0; i < numDirt; ++i) {
        float x = ofRandom(-W / 2 + wallSize, W / 2 - wallSize);
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto dirt = new Dirt(game, glm::vec3(x, -25, z), glm::vec3(50));
        game->addGameObject(dirt);
    } 
    // Turbo
    int numTurbo = 3;
    for (int i = 0; i < numTurbo; ++i) {
        float x = ofRandom(-W / 2 + wallSize, W / 2 - wallSize);
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto dirt = new Turbo(game, glm::vec3(x, -25, z), glm::vec3(50));
        game->addGameObject(dirt);
    }

    // Pit
    int numPit = 4;
    for (int i = 0; i < numPit; ++i) {
        float x = ofRandom(-W / 2 + wallSize, W / 2 - wallSize);
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto pit = new Pit(game, glm::vec3(x, -25, z), glm::vec3(50));
        game->addGameObject(pit);
    }

    // Fence
    int numFence = 3;
    for (int i = 0; i < numFence; ++i) {
        float x = ofRandom(-W / 2 + wallSize, W / 2 - wallSize);
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto fence = new Fence(game, glm::vec3(x, -25, z), glm::vec3(50));
        game->addGameObject(fence);
    }

    // Pedestrians
    int numPedestrians = 2;
    for (int i = 0; i < numPedestrians; ++i) {
        float x = ofRandom(-W / 2 + wallSize * 1.1, W / 2 - wallSize * 1.1);
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto pedestrian = new Pedestrian(game, glm::vec3(x, 0, z), glm::vec3(50, 150, 50));
        if (ofRandom(0, 1) < 0.5) {
            pedestrian->turn();
        }
        game->addGameObject(pedestrian);
    }

    int numArcoloco = 1;
    for (int i = 0; i < numArcoloco; ++i) {
        float x = 0; // Center of the road
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto arco = new ArcoLoco(game, glm::vec3(x, -25, z), glm::vec3(W, 50, 50)); // Width of the object is same as road width
        game->addGameObject(arco);
    }

    // Wall to close the circuit.
    glm::vec3 wall_back_pos(0, roadPos.y + 20, -10);
    auto wall_back = new Wall(game,
        wall_back_pos, // Put the wall very close to the player in the z direction.
        glm::vec3(W, wallSize, wallSize), false); // The size of the wall extends along the width of the road.
    game->addGameObject(wall_back);



    // Grúa
    float craneZ = roadPos.z + L * 0.5;
    auto crane = new Crane(game, glm::vec3(0, 0, 0), glm::vec3(50, 150, 500));
    game->addGameObject(crane);


    // El avión de Oscar.
    float planeX = ofRandom(-W / 2 + wallSize, W / 2 - wallSize); // Posición aleatoria en X
    float planeY = 1000; // Altura del avión
    float planeZ = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2); // Posición aleatoria en Z
    auto plane = new Plane(game, glm::vec3(0, 1000, 3500), glm::vec3(100)); // Asume que el tamaño del avión es 100, cámbialo según tus necesidades
    auto plane1 = new Plane(game, glm::vec3(planeX, planeY, planeZ), glm::vec3(100)); // Asume que el tamaño del avión es 100, cámbialo según tus necesidades
    game->addGameObject(plane);
    game->addGameObject(plane1);

    float totalLength = abs(goal_pos.z - wall_back_pos.z);

    // Double the wall height
    int wallHeight = wallSize * 2.5;

    float wall_offset_z = 100;

    // Creating a horizontal wall at the goal position
    auto wall_goal = new Wall(game,
        glm::vec3(goal_pos.x, goal_pos.y, goal_pos.z + wall_offset_z), // Move the wall further in the z direction
        glm::vec3(W, wallSize, wallSize), false); // Adjust size as needed
    game->addGameObject(wall_goal);

    auto wall_r = new Wall(game,
        glm::vec3(W / 2, roadPos.y, (goal_pos.z + wall_back_pos.z) / 2),
        glm::vec3(wallSize, wallHeight, totalLength), false); // No es pared izquierda (es decir, es derecha)
    game->addGameObject(wall_r);

    auto wall_l = new Wall(game,
        glm::vec3(-W / 2, roadPos.y, (goal_pos.z + wall_back_pos.z) / 2),
        glm::vec3(wallSize, wallHeight, totalLength), true); // Es pared izquierda
    game->addGameObject(wall_l);

    float rivalDistanceFromPlayer = 300.0f; // Adjust this value as needed
    float rivalYPosition = -25;  // adjust this value as per your game world
    float rivalZPosition = 0;    // adjust this value as per your game world

    Rival* rival1 = new Rival(game, glm::vec3(-rivalDistanceFromPlayer, rivalYPosition, rivalZPosition), glm::vec3(50)); // to the left of the player
    TPVCar* rival2 = new TPVCar(game, glm::vec3(50, 0, 50), glm::vec3(50));   // to the right of the player

    game->addGameObject(rival1);
    game->addGameObject(rival2);

    // Obj
    int numObjs = 5;
    for (int i = 0; i < numCoins; ++i) {
        float x = ofRandom(-W / 2 + wallSize, W / 2 - wallSize);
        float z = ofRandom(roadPos.z - L * 0.8, roadPos.z + L / 2);
        auto obj = new Obj(game, glm::vec3(x, -25, z), glm::vec3(50));
        game->addGameObject(obj);
    }
}


void GameObjectGenerator::addPedestrian() {
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;
    float wallSize = 100;
    float x = ofRandom(-W / 2 + wallSize * 1.1, W / 2 - wallSize * 1.1);
    float z = ofRandom(0, L);
    auto pedestrian = new Pedestrian(game, glm::vec3(x, 0, z), glm::vec3(50, 150, 50));
    if (ofRandom(0, 1) < 0.5) {
        pedestrian->turn();
    }
    game->addGameObject(pedestrian);
}