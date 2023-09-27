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

void drawCircle(float x, float y, float radiusX, float radiusY)
{

    const float angleIncrement = 2.0f * M_PI / static_cast<float>(CIRCLE_SEGMENTS_NUM);
    const int vertexCount = CIRCLE_SEGMENTS_NUM;
    GLfloat* vertices = new GLfloat[2 * vertexCount];

    vertices[0] = x;
    vertices[1] = y;

    for (int i = 0; i < vertexCount; i++)
    {
        const float angle = angleIncrement * static_cast<float>(i);
        const float px = x + radiusX * std::cos(angle);
        const float py = y + radiusY * std::sin(angle);

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
