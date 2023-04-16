/*H***********************************************************
* FILENAME :  OpenGL.h
*
* PROJECT :
*  World of the fittest
* 
*
* DESCRIPTION :
*
*
* DATE:
*    04.2023
*
* NOTES :
*
*   Copyright Tobias HUSY 2022.  All rights reserved.
*
* AUTHOR:
*    Tobias HUSY <tobias.husy@students.bfh.ch>
*
*H*/
#ifndef OPENGL_H
#define OPENGL_H

#include "properties.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// settings for disaplay
const unsigned int SCR_WIDTH = BOARD_LENGTH_X*15;
const unsigned int SCR_HEIGHT = BOARD_LENGTH_Y*15;
const unsigned int SCR_SQUARES_X = BOARD_LENGTH_X;
const unsigned int SCR_SQUARES_Y = BOARD_LENGTH_Y;
const unsigned int SCR_SQUARES = SCR_SQUARES_X * SCR_SQUARES_Y;
const unsigned int SCR_POINTS_PER_SQUARE = 12;
const float SCR_GLFW_Range = 2.0;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

#endif // OPENGL_H