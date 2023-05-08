/*H***********************************************************
* FILENAME :  properties.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   This header contains all constant for adjust the program.
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

#ifndef PROPERTIES_H
#define PROPERTIES_H
#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

enum Role {EMPTY, GRASS, RABBIT, FOX, MAX_ROLE};
enum Level {GROUND, ABOVE};

// Board
const size_t BOARD_LENGTH_X = 80;
const size_t BOARD_LENGTH_Y = 60;
const size_t BOARD_LEVELS = 2;
const size_t CYCLE_TIME_MS = 1;
// Drawing
const size_t CIRCLE_SEGMENTS_NUM = 500;
const double M_PI = std::acos(-1);
// Life
const size_t DEFAULT_GROW_LEVEL = 2;
const size_t MAX_GROW_LEVEL = 8;
const size_t NEIGHBORHOOD_SIZE = 8;
// Gras
const size_t GRASS_START_POPULATION = 400;
// Rabit
const size_t RABBIT_START_POPULATION = 300;
const size_t RABBIT_LIFESPAN = 6;
const size_t RABBIT_SEXUAL_MATURITY = 1;
const size_t RABBIT_MAX_REPLETION_LEVEL = 3;
// Fox
const size_t FOX_START_POPULATION = 500;
const size_t FOX_LIVESPAN = 20;
const size_t FOX_SEXUAL_MATURITY = 1;
const size_t FOX_MAX_REPLETION_LEVEL = 6;

#endif // PROPERTIES_H
