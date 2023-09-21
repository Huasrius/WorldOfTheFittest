/*H***********************************************************
* FILENAME :  shader.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for Class Shader
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

#ifndef SHADER_H
#define SHADER_H

#include "properties.h"
#include "shapeDrawing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/**
 * @brief The Living Class is a base Class for all possible living objects. It contains
 *        the location, where the object is and it has two virtual methodes,
 *        one for giving back the role of the object and one for doing some action
 */
class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setUniform4f(const char* name, float v1, float v2, float v3, float v4);
    std::string vertexCode;
    std::string fragmentCode;
    GLuint vertexShader;
    GLuint fragmentShader;;
private:
    GLuint m_ProgramID;
    std::string loadShaderCode(const char* filePath);
    GLuint compileShader(GLenum shaderType, const char* source);
    GLuint createShaderProgram(GLuint vertexShader, GLuint fragmentShader);
};

    //int main()
    //{
    //    // Initialize GLFW and create a window

    //    // Initialize GLAD

    //    // Create shader object
    //    Shader shader("vertex_shader.glsl", "fragment_shader.glsl");

    //    // Use the shader program
    //    shader.use();

    //    // Rendering loop

    //    // Clean up GLFW and exit
    //}


    //const char* vertexShaderSource;
    //const char* fragmentShaderHumusSource;
    //const char* fragmentShaderGrasSource;
    //const char* fragmentShaderFoxMaleSource;
    //const char* fragmentShaderFoxFemaleSource;
    //const char* fragmentShaderRabbitMaleSource;
    //const char* fragmentShaderRabbitFemaleSource;
    //unsigned int vertexShader;
    //unsigned int fragmentShaderHumus;
    //unsigned int fragmentShaderFoxMale;
    //unsigned int fragmentShaderFoxFemale;
    //unsigned int fragmentShaderGras;
    //unsigned int fragmentShaderRabbitMale;
    //unsigned int fragmentShaderRabbitFemale;
    //unsigned int shaderProgramHumus;
    //unsigned int shaderProgramFoxMale;
    //unsigned int shaderProgramFoxFemale;
    //unsigned int shaderProgramGras;
    //unsigned int shaderProgramRabbitMale;
    //unsigned int shaderProgramRabbitFemale;

#endif // SHADER_H



//// for the living class
//glUseProgram(shaderProgramGras);