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

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);



#endif // WINDOWHANDLING_H