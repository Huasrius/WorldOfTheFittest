/*H***********************************************************
* FILENAME :  simulation.cpp        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The .cpp File descripes all Methodes of the class header File
*
* DATE:
*    06.2018
*
* NOTES :
*
*   Copyright Valerio MOLLET, Tobias HUSY 2018.  All rights reserved.
*
* AUTHOR:
*    Valerio MOLLET <valerio.mollet@students.bfh.ch>
*    Tobias HUSY <tobias.husy@students.bfh.ch>
*
*H*/

#include "simulation.h"

/**
 * @brief The Simulation::Simulation constructor initialize the hole simulation, that means a worldplayground
 *        is filled with each role on randomly location
 */
Simulation::Simulation() {

    srand(static_cast<unsigned>(clock()));

    //set the limit for WorldPlayground
    for (unsigned ix = 0; ix < EDGE_LENGTH_GAME_BOARD + 2; ix++){
        worldPlayground[ix][0] = nullptr;
        worldPlayground[ix][EDGE_LENGTH_GAME_BOARD + 1] = nullptr;
    }
    for (unsigned iy = 1; iy < EDGE_LENGTH_GAME_BOARD + 1; iy++){
        worldPlayground[0][iy] = nullptr;
        worldPlayground[EDGE_LENGTH_GAME_BOARD + 1][iy] = nullptr;
    }
    //fill the whole WorldPlayground with the Class Empty
    for (unsigned ix = 1; ix <= EDGE_LENGTH_GAME_BOARD; ix++)
        for (unsigned iy = 1; iy <= EDGE_LENGTH_GAME_BOARD; iy++){
            worldPlayground[ix][iy] = new Empty(ix,iy);
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
        if(static_cast<Animal*>(*vec.fox[i])->getAge() == LIFESPAN_FOX || static_cast<Animal*>(*vec.fox[i])->getRepletionLevel() == 0) {
            Living* temp = worldPlayground[(*vec.fox[i])->location.x][(*vec.fox[i])->location.y];
            worldPlayground[(*vec.fox[i])->location.x][(*vec.fox[i])->location.y] = new Empty((*vec.fox[i])->location.x,(*vec.fox[i])->location.y);
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
            if(static_cast<Animal*>(*vec.rabbit[i])->getAge() == LIFESPAN_FOX || static_cast<Animal*>(*vec.rabbit[i])->getRepletionLevel() == 0) {
                Living* temp = worldPlayground[(*vec.rabbit[i])->location.x][(*vec.rabbit[i])->location.y];
                worldPlayground[(*vec.rabbit[i])->location.x][(*vec.rabbit[i])->location.y] = new Empty((*vec.rabbit[i])->location.x,(*vec.rabbit[i])->location.y);
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
    neighbor[0] = &worldPlayground[x-1][y-1];
    neighbor[1] = &worldPlayground[x][y-1];
    neighbor[2] = &worldPlayground[x+1][y-1];
    neighbor[3] = &worldPlayground[x+1][y];
    neighbor[4] = &worldPlayground[x+1][y+1];
    neighbor[5] = &worldPlayground[x][y+1];
    neighbor[6] = &worldPlayground[x-1][y+1];
    neighbor[7] = &worldPlayground[x-1][y];
}

/**
 * @brief Simulation::setStart this is a function, which is called by the constructor and it initialize the
 *        world Playground randomly for each role
 * @param an Enumeration role
 */
void Simulation::setStart(Role role){
    unsigned x ,y;
    size_t startPopulation = 0;

    switch(role){
    case GRASS:
        startPopulation = GRASS_START_POPULATION;
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
            x = 1 + rand()%EDGE_LENGTH_GAME_BOARD;
            y = 1 + rand()%EDGE_LENGTH_GAME_BOARD;
        }while(EMPTY != worldPlayground[x][y]->who());

        switch(role){
        case GRASS:
            worldPlayground[x][y] = new Grass(x,y);
            vec.grass.push_back(&worldPlayground[x][y]);
            break;
        case RABBIT :
            worldPlayground[x][y] = new Rabbit(x,y,rand()%LIFESPAN_RABBIT);
            vec.rabbit.push_back(&worldPlayground[x][y]);
            break;
        case FOX :
            worldPlayground[x][y] = new Fox(x,y,rand()%LIFESPAN_RABBIT);
            vec.fox.push_back(&worldPlayground[x][y]);
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

    for (unsigned x = 1; x <= EDGE_LENGTH_GAME_BOARD; x++)
        for (unsigned y = 1; y <= EDGE_LENGTH_GAME_BOARD; y++){
            switch(worldPlayground[x][y]->who()){
            case GRASS:
                vec.grass.push_back(&worldPlayground[x][y]);
                break;
            case RABBIT :
                vec.rabbit.push_back(&worldPlayground[x][y]);
                break;
            case FOX :
                vec.fox.push_back(&worldPlayground[x][y]);
                break;
            default :
                break;
            }
        }
    statics.numberOfFoxes = vec.fox.size();
    statics.numberOfRabbits = vec.rabbit.size();
    statics.numberOfGrass = vec.grass.size();
}

