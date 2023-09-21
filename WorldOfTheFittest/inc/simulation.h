/*H***********************************************************
* FILENAME :  simulation.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for Class Simulation
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

#ifndef SIMULATION_H
#define SIMULATION_H

#include "properties.h"
#include "living.h"
#include "animal.h"
#include "empty.h"
#include "grass.h"
#include "rabbit.h"
#include "fox.h"

/**
 * @brief The Simulation class simulate the World and draw the playground afer each cycle.
 *        It contains members world Playground, neighbors, vector and a statics for all
 *        child clas from living.
 *        It contains puplic display and oneCycle Methodes for simulate one cycle and dispaying it
 *        for filling the vectors is a private fillVectors available.
 */
class Simulation
{
public:
    Simulation(Shader* shader);
    void oneCycle(void);
    Living* worldPlayground[BOARD_LEVELS][BOARD_LENGTH_X + 2][BOARD_LENGTH_Y + 2];
    Shader* shader;
    struct vec_ {
        vector<Living**> grass;
        vector<Living**> rabbit;
        vector<Living**> fox;
    }vec;
    struct statics_ {
        size_t numberOfGrass;
        size_t numberOfRabbits;
        size_t numberOfFoxes;
    }statics;
private:
    void fillVectors(void);
    Living** neighbor[BOARD_LEVELS][NEIGHBORHOOD_SIZE];
    void setStart(Role role);
    void setNeighbors(unsigned x, unsigned y);
};

#endif // SIMULATION_H
