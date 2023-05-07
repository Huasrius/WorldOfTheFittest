/*H***********************************************************
* FILENAME :  openGL.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for the OpenGL functions
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
#ifndef OPENGL_H
#define OPENGL_H

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

//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char* fragmentShaderHumusSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(0.8f, 0.4f, 0.0f, 1.0f);\n"
//"}\n\0";
//const char* fragmentShaderGrasSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(0.0f, 0.4f, 0.0f, 1.0f);\n"
//"}\n\0";
//const char* fragmentShaderFoxMaleSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(0.8f, 0.0f, 0.0f, 1.0f);\n"
//"}\n\0";
//const char* fragmentShaderFoxFemaleSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(0.8f, 0.0f, 0.3f, 1.0f);\n"
//"}\n\0";
//const char* fragmentShaderRabbitMaleSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(0.0f, 0.0f, 0.8f, 1.0f);\n"
//"}\n\0";
//const char* fragmentShaderRabbitFemaleSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(0.2f, 0.0f, 1.0f, 1.0f);\n"
//"}\n\0";

#endif // OPENGL_H