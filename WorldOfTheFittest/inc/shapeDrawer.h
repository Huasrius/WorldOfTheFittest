/*H***********************************************************
* FILENAME :  shapeDrawer.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for Class shapeDrawer
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
#ifndef SHAPEDRAWER_H
#define SHAPEDRAWER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <random>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

class shapeDrawer
{
public:
	const double M_PI = std::acos(-1);
	shapeDrawer();
	void drawCircle(float x, float y, float radius, int num_segments);
};

#endif // SHAPEDRAWER_H