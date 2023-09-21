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
const size_t BOARD_LENGTH_X = 120;
const size_t BOARD_LENGTH_Y = 60;
const size_t BOARD_LEVELS = 2;
const size_t CYCLE_TIME_MS = 1;
// Display
const float SCR_GLFW_RANGE = 2.0;
const float SCR_LIVING_OFFSET_FACTOR = 0.3; //for a not uniform display of the coordinates
// Drawing
const size_t CIRCLE_SEGMENTS_NUM = 20;
// Life
const size_t DEFAULT_GROW_LEVEL = 2;
const size_t NEIGHBORHOOD_SIZE = 8;
// Gras
const size_t GRASS_START_POPULATION = 400;
const size_t MAX_GROW_LEVEL = 4;
// Rabit
const size_t RABBIT_START_POPULATION = 300;
const size_t RABBIT_LIFESPAN = 6;
const size_t RABBIT_SEXUAL_MATURITY = 1;
const size_t RABBIT_MAX_REPLETION_LEVEL = 3;
const size_t RABBIT_BIRTH_REPLETION_LEVEL = 1;
// Fox
const size_t FOX_START_POPULATION = 500;
const size_t FOX_LIFESPAN = 20;
const size_t FOX_SEXUAL_MATURITY = 3;
const size_t FOX_MAX_REPLETION_LEVEL = 10;
const size_t FOX_BIRTH_REPLETION_LEVEL = 2;

// CALCULATIONS
// Board
 
// Display
const size_t SCR_WIDTH = BOARD_LENGTH_X * 12;
const size_t SCR_HEIGHT = BOARD_LENGTH_Y * 12;
const float SCR_LIVING_DELTA_X = SCR_GLFW_RANGE / BOARD_LENGTH_X;
const float SCR_LIVING_DELTA_Y = SCR_GLFW_RANGE / BOARD_LENGTH_Y;
// Drawing
const double M_PI = std::acos(-1);
// Life

// Gras

// Rabit

// Fox

#endif // PROPERTIES_H
