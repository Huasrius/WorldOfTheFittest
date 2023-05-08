/*H***********************************************************
* FILENAME :  shapeDrawer.cpp
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The .cpp File descripes all functions of the header File
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

#include "shapeDrawing.h"

void drawCircle(float x, float y, float radius)
{

    const float angleIncrement = 2.0f * M_PI / static_cast<float>(CIRCLE_SEGMENTS_NUM);
    const int vertexCount = CIRCLE_SEGMENTS_NUM;
    GLfloat* vertices = new GLfloat[2 * vertexCount];

    vertices[0] = x;
    vertices[1] = y;

    for (int i = 0; i < vertexCount; i++)
    {
        const float angle = angleIncrement * static_cast<float>(i);
        const float px = x + radius * std::cos(angle);
        const float py = y + radius * std::sin(angle);

        vertices[2 * i] = px;
        vertices[2 * i + 1] = py;
    }

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 2 * vertexCount * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, static_cast<GLvoid*>(0));
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    delete[] vertices;
}





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


//// build and compile our shader program
//// ------------------------------------
//// we skipped compile log checks this time for readability (if you do encounter issues, add the compile-checks! see previous code samples)
//unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//unsigned int fragmentShaderHumus = glCreateShader(GL_FRAGMENT_SHADER);
//unsigned int fragmentShaderFoxMale = glCreateShader(GL_FRAGMENT_SHADER);
//unsigned int fragmentShaderFoxFemale = glCreateShader(GL_FRAGMENT_SHADER);
//unsigned int fragmentShaderGras = glCreateShader(GL_FRAGMENT_SHADER);
//unsigned int fragmentShaderRabbitMale = glCreateShader(GL_FRAGMENT_SHADER);
//unsigned int fragmentShaderRabbitFemale = glCreateShader(GL_FRAGMENT_SHADER);
//unsigned int shaderProgramHumus = glCreateProgram();
//unsigned int shaderProgramFoxMale = glCreateProgram();
//unsigned int shaderProgramFoxFemale = glCreateProgram();
//unsigned int shaderProgramGras = glCreateProgram();
//unsigned int shaderProgramRabbitMale = glCreateProgram();
//unsigned int shaderProgramRabbitFemale = glCreateProgram();
//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//glCompileShader(vertexShader);
//glShaderSource(fragmentShaderHumus, 1, &fragmentShaderHumusSource, NULL);
//glCompileShader(fragmentShaderHumus);
//glShaderSource(fragmentShaderFoxMale, 1, &fragmentShaderFoxMaleSource, NULL);
//glCompileShader(fragmentShaderFoxMale);
//glShaderSource(fragmentShaderFoxFemale, 1, &fragmentShaderFoxFemaleSource, NULL);
//glCompileShader(fragmentShaderFoxFemale);
//glShaderSource(fragmentShaderGras, 1, &fragmentShaderGrasSource, NULL);
//glCompileShader(fragmentShaderGras);
//glShaderSource(fragmentShaderRabbitMale, 1, &fragmentShaderRabbitMaleSource, NULL);
//glCompileShader(fragmentShaderRabbitMale);
//glShaderSource(fragmentShaderRabbitFemale, 1, &fragmentShaderRabbitFemaleSource, NULL);
//glCompileShader(fragmentShaderRabbitFemale);
//// link the first program object
//glAttachShader(shaderProgramHumus, vertexShader);
//glAttachShader(shaderProgramHumus, fragmentShaderHumus);
//glLinkProgram(shaderProgramHumus);
//// then link the second program object using a different fragment shader (but same vertex shader)
//// this is perfectly allowed since the inputs and outputs of both the vertex and fragment shaders are equally matched.
//glAttachShader(shaderProgramFoxMale, vertexShader);
//glAttachShader(shaderProgramFoxMale, fragmentShaderFoxMale);
//glLinkProgram(shaderProgramFoxMale);
//glAttachShader(shaderProgramFoxFemale, vertexShader);
//glAttachShader(shaderProgramFoxFemale, fragmentShaderFoxFemale);
//glLinkProgram(shaderProgramFoxFemale);
//glAttachShader(shaderProgramGras, vertexShader);
//glAttachShader(shaderProgramGras, fragmentShaderGras);
//glLinkProgram(shaderProgramGras);
//glAttachShader(shaderProgramRabbitMale, vertexShader);
//glAttachShader(shaderProgramRabbitMale, fragmentShaderRabbitMale);
//glLinkProgram(shaderProgramRabbitMale);
//glAttachShader(shaderProgramRabbitFemale, vertexShader);
//glAttachShader(shaderProgramRabbitFemale, fragmentShaderRabbitFemale);
//glLinkProgram(shaderProgramRabbitFemale);