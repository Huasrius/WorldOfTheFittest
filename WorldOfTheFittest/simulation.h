/*H***********************************************************
* FILENAME :  simulation.h        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The header File for Class Simulation
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
    Simulation();
    void display(void) const;
    void oneCycle(void);

private:
    void fillVectors(void);
    Living* worldPlayground[EDGE_LENGTH_GAME_BOARD+2][EDGE_LENGTH_GAME_BOARD+2];
    Living** neighbor[NEIGHBORHOOD_SIZE];
    struct vec_{
        vector<Living**> grass;
        vector<Living**> rabbit;
        vector<Living**> fox;
    }vec;
    struct statics_{
        unsigned numberOfGrass;
        unsigned numberOfRabbits;
        unsigned numberOfFoxes;
    }statics;
    void setStart(Role role);
    void setNeighbors(unsigned x, unsigned y);
};

#endif // SIMULATION_H
