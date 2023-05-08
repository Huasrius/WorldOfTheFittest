/*H***********************************************************
* FILENAME :  shapeDrawer.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for the functions shapeDrawings
*
* DATE:
*    08.05.2023
*
* NOTES :
*   Copyright Tobias HUSY 2023.  All rights reserved.
*
* AUTHOR:
*    Tobias HUSY <tobi-husy@hotmail.com>
*
*H*/
#ifndef SHAPEDRAWING_H
#define SHAPEDRAWING_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <random>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "properties.h"


void drawCircle(float x, float y, float radiusX, float radiusY);

#endif // SHAPEDRAWING_H