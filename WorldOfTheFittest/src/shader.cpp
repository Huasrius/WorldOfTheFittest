/*H***********************************************************
* FILENAME :  shader.cpp
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The .cpp File descripes all Methodes of the class header File
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

#include "shader.h"

/**
 * @brief The Simulation::Simulation constructor initialize the hole shaders
 * which are used by the living classes to draw their appearances
 */


    // Constructor
Shader::Shader(const char* vertexPath, const char* fragmentPath)
    {
        // Load shader source code from files
        vertexCode = loadShaderCode(vertexPath);
        fragmentCode = loadShaderCode(fragmentPath);

        // Compile shaders
        vertexShader = compileShader(GL_VERTEX_SHADER, vertexCode.c_str());
        fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentCode.c_str());

        // Create shader program
        m_ProgramID = createShaderProgram(vertexShader, fragmentShader);

        // Delete the shader objects
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    // Use the shader program
    void Shader::use()
    {
        glUseProgram(m_ProgramID);
    }

    // Load shader code from a file
    std::string Shader::loadShaderCode(const char* filePath)
    {
        std::string code;
        std::ifstream fileStream(filePath, std::ios::in);

        if (fileStream.is_open())
        {
            std::stringstream sstr;
            sstr << fileStream.rdbuf();
            code = sstr.str();
            fileStream.close();
        }
        else
        {
            std::cerr << "Failed to open shader file: " << filePath << std::endl;
        }

        return code;
    }

    // Compile a shader
    GLuint Shader::compileShader(GLenum shaderType, const char* source)
    {
        GLuint shaderID = glCreateShader(shaderType);
        glShaderSource(shaderID, 1, &source, nullptr);
        glCompileShader(shaderID);

        // Check for compilation errors
        GLint success;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            GLchar infoLog[512];
            glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
            std::cerr << "Shader compilation error: " << infoLog << std::endl;
        }

        return shaderID;
    }

    // Create a shader program and link the shaders
    GLuint Shader::createShaderProgram(GLuint vertexShader, GLuint fragmentShader)
    {
        GLuint programID = glCreateProgram();
        glAttachShader(programID, vertexShader);
        glAttachShader(programID, fragmentShader);
        glLinkProgram(programID);

        // Check for linking errors
        GLint success;
        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success)
        {
            GLchar infoLog[512];
            glGetProgramInfoLog(programID, 512, nullptr, infoLog);
            std::cerr << "Shader program linking error: " << infoLog << std::endl;
        }
        return programID;
    }

    // Set a uniform variable of type vec4 (4-component vector)
    void Shader::setUniform4f(const char* name, float v1, float v2, float v3, float v4) {
        GLuint uniformLocation = glGetUniformLocation(m_ProgramID, name);
        if (uniformLocation != -1) {
            glUniform4f(uniformLocation, v1, v2, v3, v4);
        }
        else {
            std::cerr << "Uniform variable not found in shader: " << name << std::endl;
        }
    }

