/*H***********************************************************
* FILENAME :  simulation.cpp
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The .cpp File descripes all Methodes of the class header File
*
* DATE:
*    07.05.2023
*
* NOTES :
*   Copyright Tobias HUSY 2023.  All rights reserved.
*
* AUTHOR:
*    Tobias HUSY <tobi-husy@hotmail.com>
*
*H*/

#include "simulation.h"

/**
 * @brief The Simulation::Simulation constructor initialize the hole simulation, that means a worldplayground
 *        is filled with each role on randomly location
 */
Simulation::Simulation() {

    // set the rand clock? 
    srand(static_cast<unsigned>(clock()));

    // set the world Playground with an outer layer of Null pointers as a border
    for (unsigned boardLevel = 0; boardLevel < BOARD_LEVELS; boardLevel++) {
        // set all the pointers to null cause I'm lazy
        for (unsigned ix = 0; ix < BOARD_LENGTH_X + 2; ix++) {
            for (unsigned iy = 0; iy < BOARD_LENGTH_Y + 2; iy++) {
                worldPlayground[boardLevel][ix][iy] = nullptr;
            }
        }       
        //fill the whole WorldPlayground with the Class Empty
        for (unsigned ix = 1; ix <= BOARD_LENGTH_X; ix++) {
            for (unsigned iy = 1; iy <= BOARD_LENGTH_Y; iy++) {
                worldPlayground[boardLevel][ix][iy] = new Empty(ix, iy);
            }
        }
    }

    //fill randomly the WorldPlayground with the CLass Grass times GRASS_START_POPULATION
    setStart(GRASS);

    //fill randomly the WorldPlayground with the CLass Rabbit times RABBIT_START_POPULATION
    setStart(RABBIT);

    //fill randomly the WorldPlayground with the CLass FOX times FOX_START_POPULATION
    setStart(FOX);

}


/**
 * @brief Simulation::oneCycle simulate one cycle of the simulation and does action for all roles except empty.
 */
void Simulation::oneCycle(void){
    unsigned i = 0;
    //do action for all Fox Classes
    for(i = 0; i < statics.numberOfFoxes; i++){
        setNeighbors((*vec.fox[i])->location.x,(*vec.fox[i])->location.y);
        (*vec.fox[i])->action(neighbor);
        //  if the role dies, because of starvation or senility the place is replaced by an empty class
        if(static_cast<Animal*>(*vec.fox[i])->getAge() == FOX_LIVESPAN || static_cast<Animal*>(*vec.fox[i])->getRepletionLevel() == 0) {
            Living* temp = worldPlayground[ABOVE][(*vec.fox[i])->location.x][(*vec.fox[i])->location.y];
            worldPlayground[ABOVE][(*vec.fox[i])->location.x][(*vec.fox[i])->location.y] = new Empty((*vec.fox[i])->location.x,(*vec.fox[i])->location.y);
            delete temp;
        }
    }

    //do action for all Rabbit Classes
    for(i = 0; i < statics.numberOfRabbits; i++){
        // in the rabbits vector could be empty classes, beacause a fox has eaten them, so it's necessary to check if it is a rabbit
        if((*vec.rabbit[i])->who() == RABBIT){
            setNeighbors((*vec.rabbit[i])->location.x,(*vec.rabbit[i])->location.y);
            (*vec.rabbit[i])->action(neighbor);
            //  if the role dies, because of starvation or senility the place is replaced by an empty class
            if(static_cast<Animal*>(*vec.rabbit[i])->getAge() == RABBIT_LIFESPAN || static_cast<Animal*>(*vec.rabbit[i])->getRepletionLevel() == 0) {
                Living* temp = worldPlayground[ABOVE][(*vec.rabbit[i])->location.x][(*vec.rabbit[i])->location.y];
                worldPlayground[ABOVE][(*vec.rabbit[i])->location.x][(*vec.rabbit[i])->location.y] = new Empty((*vec.rabbit[i])->location.x,(*vec.rabbit[i])->location.y);
                delete temp;
            }
        }
    }

    //do action for all Grass Classes
    for(i = 0; i < statics.numberOfGrass; i++){
        // in the grass vector could be empty classes, beacause a rabbit has eaten them, so it's necessary to check if it is a grass
        if((*vec.grass[i])->who() == GRASS){
            setNeighbors((*vec.grass[i])->location.x,(*vec.grass[i])->location.y);
            (*vec.grass[i])->action(neighbor);
        }
    }
    // fill the vectors again
    fillVectors();
}

/**
 * @brief Simulation::setNeighbors fills the array neighbor with the location's neigborhood
 * @param x
 * @param y
 */
void Simulation::setNeighbors(unsigned x, unsigned y){

    for (unsigned boardLevel = 0; boardLevel < BOARD_LEVELS; boardLevel++) {
        neighbor[boardLevel][0] = &worldPlayground[boardLevel][x - 1][y - 1];
        neighbor[boardLevel][1] = &worldPlayground[boardLevel][x][y - 1];
        neighbor[boardLevel][2] = &worldPlayground[boardLevel][x + 1][y - 1];
        neighbor[boardLevel][3] = &worldPlayground[boardLevel][x + 1][y];
        neighbor[boardLevel][4] = &worldPlayground[boardLevel][x + 1][y + 1];
        neighbor[boardLevel][5] = &worldPlayground[boardLevel][x][y + 1];
        neighbor[boardLevel][6] = &worldPlayground[boardLevel][x - 1][y + 1];
        neighbor[boardLevel][7] = &worldPlayground[boardLevel][x - 1][y];
    }
}

/**
 * @brief Simulation::setStart this is a function, which is called by the constructor and it initialize the
 *        world Playground randomly for each role
 * @param an Enumeration role
 */
void Simulation::setStart(Role role){
    unsigned x ,y;
    size_t startPopulation = 0;
    unsigned boardLevel = ABOVE;

    switch(role){
    case GRASS:
        startPopulation = GRASS_START_POPULATION;
        boardLevel = GROUND;
        break;
    case RABBIT :
        startPopulation = RABBIT_START_POPULATION;
        break;
    case FOX :
        startPopulation = FOX_START_POPULATION;
        break;
    default :
        break;
    }

    //set a new grass, rabbit or fox at a random location and fill a vector for each role
    for(unsigned i = 0; i < startPopulation; i++){
        do{
            x = 1 + rand()%BOARD_LENGTH_X;
            y = 1 + rand()%BOARD_LENGTH_Y;
        }while(EMPTY != worldPlayground[boardLevel][x][y]->who());

        switch(role){
        case GRASS:
            worldPlayground[GROUND][x][y] = new Grass(x,y);
            vec.grass.push_back(&worldPlayground[boardLevel][x][y]);
            break;
        case RABBIT :
            worldPlayground[ABOVE][x][y] = new Rabbit(x,y,rand()%RABBIT_LIFESPAN);
            vec.rabbit.push_back(&worldPlayground[boardLevel][x][y]);
            break;
        case FOX :
            worldPlayground[ABOVE][x][y] = new Fox(x,y,rand()%RABBIT_LIFESPAN);
            vec.fox.push_back(&worldPlayground[boardLevel][x][y]);
            break;
        default :
            break;
        }
        statics.numberOfFoxes = vec.fox.size();
        statics.numberOfRabbits = vec.rabbit.size();
        statics.numberOfGrass = vec.grass.size();
    }
}

/**
 * @brief Simulation::fillVectors filles a vector from the worldPlayground for each role
 */
void Simulation::fillVectors(void){

    vec.fox.erase(vec.fox.begin(),vec.fox.end());
    vec.rabbit.erase(vec.rabbit.begin(),vec.rabbit.end());
    vec.grass.erase(vec.grass.begin(),vec.grass.end());
    for (unsigned boardLevel = 0; boardLevel < BOARD_LEVELS; boardLevel++) {
        for (unsigned x = 1; x <= BOARD_LENGTH_X; x++)
            for (unsigned y = 1; y <= BOARD_LENGTH_Y; y++) {
                switch (worldPlayground[boardLevel][x][y]->who()) {
                case GRASS:
                    vec.grass.push_back(&worldPlayground[boardLevel][x][y]);
                    break;
                case RABBIT:
                    vec.rabbit.push_back(&worldPlayground[boardLevel][x][y]);
                    break;
                case FOX:
                    vec.fox.push_back(&worldPlayground[boardLevel][x][y]);
                    break;
                default:
                    break;
                }
            }
    }
    statics.numberOfFoxes = vec.fox.size();
    statics.numberOfRabbits = vec.rabbit.size();
    statics.numberOfGrass = vec.grass.size();
}

