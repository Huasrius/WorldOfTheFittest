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

#include "OpenGL.h"

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}