/*H***********************************************************
* FILENAME :  main.cpp
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The mini-project is about a simulator of the interaction between predators and pray written in C++.
*   The life forms interact with each otheron a simulation cycle basis.The simulator shows what happens
*   when one life form dominates the others. Beside of the core business logic – the simulator,
*   there is a builder which holds all together and a visualization of the world of living thing.
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
#include "simulation.h"
#include "windowHandling.h"
#include "shapeDrawer.h"



int main()
{
    unsigned int cycles = 30;
    // Initialise Simulation
    Simulation sim;

    // Initialise shapeDrawer
    shapeDrawer drawer;

    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "World", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
    }

    //// set up vertex data (and buffer(s)) and configure vertex attributes
    //// ------------------------------------------------------------------
    //unsigned int VBOs[BOARD_LEVELS][SCR_SQUARES], VAOs[BOARD_LEVELS][SCR_SQUARES], EBOs[BOARD_LEVELS][SCR_SQUARES];
    //unsigned int bufferIndex = 0;


    //for (unsigned boardLevel = 0; boardLevel < BOARD_LEVELS; boardLevel++) {
    //    glGenVertexArrays(SCR_SQUARES, VAOs[boardLevel]);
    //    glGenBuffers(SCR_SQUARES, VBOs[boardLevel]);
    //    glGenBuffers(SCR_SQUARES, EBOs[boardLevel]);
    //}

    //// 3D Array Points of all the Squares
    //float squares[SCR_SQUARES_X][SCR_SQUARES_Y][SCR_POINTS_PER_SQUARE]{};
    //unsigned int sizOfSquare = sizeof(squares[0][0]);
    //// Points to create a square from two triangles
    //unsigned int indices[] = {  // note that we start from 0!
    //0, 1, 3,   // first triangle
    //1, 2, 3    // second triangle
    //};
    //unsigned int sizeOfIndices = sizeof(indices);
    //// Delta in X and Y for the Squares
    //float deltaX = SCR_GLFW_Range / SCR_SQUARES_X;
    //float deltaY = SCR_GLFW_Range / SCR_SQUARES_Y;
    //float sizeSquareXHalf = deltaX / 2;
    //float sizeSquareYHalf = deltaY / 2;
    //float centerX = 0.0;
    //float centerY = 0.0;
    //for (unsigned boardLevel = 1; boardLevel < BOARD_LEVELS; boardLevel++) {
    //    for (int x = 0; x < SCR_SQUARES_X; x++) {
    //        centerX = deltaX * x + deltaX / 2 - SCR_GLFW_Range / 2;
    //        for (int y = 0; y < SCR_SQUARES_Y; y++) {
    //            centerY = deltaY * y + deltaY / 2 - SCR_GLFW_Range / 2;
    //            // calculate the points of the square
    //            float squareCoordinates[] = {
    //                centerX + sizeSquareXHalf, centerY + sizeSquareYHalf, 0.0f,  // top right
    //                centerX + sizeSquareXHalf, centerY - sizeSquareYHalf, 0.0f,  // bottom right
    //                centerX - sizeSquareXHalf, centerY - sizeSquareYHalf, 0.0f,  // bottom left
    //                centerX - sizeSquareXHalf, centerY + sizeSquareYHalf, 0.0f   // top left 
    //            };
    //            // fill in the Points of the square
    //            for (int i = 0; i < SCR_POINTS_PER_SQUARE; i++) {
    //                squares[x][y][i] = squareCoordinates[i];
    //                // cout << "Coordinates " << squares[x][y][i] << endl
    //            }
    //            //cout << "Bufferindex " << bufferIndex << endl;
    //            glBindVertexArray(VAOs[boardLevel][bufferIndex]);
    //            glBindBuffer(GL_ARRAY_BUFFER, VBOs[boardLevel][bufferIndex]);
    //            glBufferData(GL_ARRAY_BUFFER, sizOfSquare, squares[x][y], GL_STATIC_DRAW);
    //            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[boardLevel][bufferIndex]);
    //            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfIndices, indices, GL_STATIC_DRAW);
    //            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	// Vertex attributes stay the same
    //            glEnableVertexAttribArray(0);
    //            // glBindVertexArray(0); // no need to unbind at all as we directly bind a different VAO the next few lines.
    //            // but beware of calls that could affect VAOs while this one is bound (like binding element buffer objects, or enabling/disabling vertex attributes)
    //            bufferIndex++;
    //        }

    //    }
    //}

    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
         
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);



        for (unsigned iGrass = 0; iGrass < sim.statics.numberOfGrass; iGrass++) {

            drawer.drawCircle(0, 0, 0.1, 500);
        }




        //bufferIndex = 0;
        //for (unsigned boardLevel = 1; boardLevel < BOARD_LEVELS; boardLevel++) {
        //    for (int x = 0; x < SCR_SQUARES_X; x++) {
        //        for (int y = 0; y < SCR_SQUARES_Y; y++) {

        //            switch (sim.worldPlayground[boardLevel][x + 1][y + 1]->who()) {
        //            case EMPTY:
        //                glUseProgram(shaderProgramHumus);
        //                break;
        //            case GRASS:
        //                glUseProgram(shaderProgramGras);
        //                break;
        //            case RABBIT:
        //                if (static_cast<Animal*>(sim.worldPlayground[boardLevel][x + 1][y + 1])->getGender())
        //                    glUseProgram(shaderProgramRabbitFemale);
        //                else
        //                    glUseProgram(shaderProgramRabbitMale);
        //                break;
        //            case FOX:
        //                if (static_cast<Animal*>(sim.worldPlayground[boardLevel][x + 1][y + 1])->getGender())
        //                    glUseProgram(shaderProgramFoxFemale);
        //                else
        //                    glUseProgram(shaderProgramFoxMale);
        //                break;
        //            default:
        //                break;
        //            }
        //            glBindVertexArray(VAOs[boardLevel][bufferIndex]);
        //            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //            bufferIndex++;
        //        }
        //    }
        //}

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
        sim.oneCycle();
        Sleep(CYCLE_TIME_MS);
    }

    //// optional: de-allocate all resources once they've outlived their purpose:
    //// ------------------------------------------------------------------------
    //for (unsigned boardLevel = 0; boardLevel < BOARD_LEVELS; boardLevel++) {
    //    glDeleteVertexArrays(SCR_SQUARES, VAOs[boardLevel]);
    //    glDeleteBuffers(SCR_SQUARES, VBOs[boardLevel]);
    //    glDeleteBuffers(SCR_SQUARES, EBOs[boardLevel]);
    //}
    //glDeleteProgram(shaderProgramHumus);
    //glDeleteProgram(shaderProgramGras);
    //glDeleteProgram(shaderProgramFoxMale);
    //glDeleteProgram(shaderProgramFoxFemale);
    //glDeleteProgram(shaderProgramRabbitMale);
    //glDeleteProgram(shaderProgramRabbitFemale);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}
