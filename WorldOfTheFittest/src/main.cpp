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

int main()
{

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

    // Create Shader Object
    Shader shader("resources/shaders/vertexShader.glsl", "resources/shaders/fragmentShader.glsl");
    shader.use();

    // Initialise Simulation
    Simulation sim(&shader);

    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);
        // render
        // color of the Background
        glClearColor(0.345f, 0.247f, 0.066f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //shader.setUniform4f("ourColor", 0.0f, 0.0f, 1.0f, 1.0f);
        for (unsigned i = 0; i < sim.statics.numberOfGrass; i++) {
            (*sim.vec.grass[i])->draw();
        }
        for (unsigned i = 0; i < sim.statics.numberOfFoxes; i++) {
            (*sim.vec.fox[i])->draw();
        }
        for (unsigned i = 0; i < sim.statics.numberOfRabbits; i++) {
            (*sim.vec.rabbit[i])->draw();
        }

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
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
