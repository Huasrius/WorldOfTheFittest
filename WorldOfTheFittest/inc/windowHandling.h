/*H***********************************************************
* FILENAME :  windowHandling.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for the windowHandling functions
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
#ifndef WINDOWHANDLING_H
#define WINDOWHANDLING_H

#include "properties.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// settings for disaplay
const size_t SCR_WIDTH = BOARD_LENGTH_X*12;
const size_t SCR_HEIGHT = BOARD_LENGTH_Y*12;
const size_t SCR_SQUARES_X = BOARD_LENGTH_X;
const size_t SCR_SQUARES_Y = BOARD_LENGTH_Y;
const size_t SCR_SQUARES = SCR_SQUARES_X * SCR_SQUARES_Y;
const size_t SCR_POINTS_PER_SQUARE = 12;
const float SCR_GLFW_Range = 2.0;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);



#endif // WINDOWHANDLING_H