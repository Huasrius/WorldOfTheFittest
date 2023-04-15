/*H***********************************************************
* FILENAME :  properties.h        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   This header contains all constant for adjust the program.
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

#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <stdlib.h>

using namespace std;

enum Role {EMPTY, GRASS, RABBIT, FOX, MAX_ROLE};

const size_t DEFAULT_GROW_LEVEL {2};
const size_t MAX_GROW_LEVEL {8};
const size_t EDGE_LENGTH_GAME_BOARD {40};
const size_t LIFESPAN_RABBIT {6};
const size_t SEXUAL_MATURITY_RABBIT {1};
const size_t LIFESPAN_FOX {9};
const size_t SEXUAL_MATURITY_FOX {1};
const size_t MAX_REPLETION_LEVEL_FOX {4};
const size_t MAX_REPLETION_LEVEL_RABBIT {3};
const size_t GRASS_START_POPULATION {400};
const size_t RABBIT_START_POPULATION {300};
const size_t FOX_START_POPULATION {150};
const size_t NEIGHBORHOOD_SIZE {8};

#endif // PROPERTIES_H
