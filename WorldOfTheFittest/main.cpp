/*H***********************************************************
* FILENAME :  main.cpp        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The mini-project is about a simulator of the interaction between predators and pray written in C++.
*   The life forms interact with each otheron a simulation cycle basis.The simulator shows what happens
*   when one life form dominates the others. Beside of the core business logic – the simulator,
*   there is a builder which holds all together and a visualization of the world of living thing.
*
* DATE:
*    06.2018
*
* NOTES :
*
*   Copyright Valerio MOLLET, Tobias HUSY 2018.  All rights reserved.
*
* AUTHOR:
*    Valerio MOLLET <valerio.mollet@students.bfh.ch>
*    Tobias HUSY <tobias.husy@students.bfh.ch>
*
*H*/
#include "simulation.h"
#include "OpenGL.h"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShader1Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
const char* fragmentShader2Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0";

int main()
{
    unsigned int cycles = 30;
    // cout<<"Enter the number of cycles: ";
    // cin>>cycles;
    Simulation sim;

    // for (unsigned i = 1; i <= cycles; i++){
    //     Test.oneCycle();
    //     system("clear");
    //     Test.display();
    //     cout<<"      Cycle: "<<i<<endl;
    //     Sleep(1000);
    // }
    // cout<<"END OF PROGRAMM";

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "World", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();

    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;

    }


    // build and compile our shader program
    // ------------------------------------
    // we skipped compile log checks this time for readability (if you do encounter issues, add the compile-checks! see previous code samples)
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER); // the first fragment shader that outputs the color orange
    unsigned int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER); // the second fragment shader that outputs the color yellow
    unsigned int shaderProgramOrange = glCreateProgram();
    unsigned int shaderProgramYellow = glCreateProgram(); // the second shader program
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glShaderSource(fragmentShaderOrange, 1, &fragmentShader1Source, NULL);
    glCompileShader(fragmentShaderOrange);
    glShaderSource(fragmentShaderYellow, 1, &fragmentShader2Source, NULL);
    glCompileShader(fragmentShaderYellow);
    // link the first program object
    glAttachShader(shaderProgramOrange, vertexShader);
    glAttachShader(shaderProgramOrange, fragmentShaderOrange);
    glLinkProgram(shaderProgramOrange);
    // then link the second program object using a different fragment shader (but same vertex shader)
    // this is perfectly allowed since the inputs and outputs of both the vertex and fragment shaders are equally matched.
    glAttachShader(shaderProgramYellow, vertexShader);
    glAttachShader(shaderProgramYellow, fragmentShaderYellow);
    glLinkProgram(shaderProgramYellow);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    unsigned int VBOs[SCR_SQUARES], VAOs[SCR_SQUARES], EBOs[SCR_SQUARES];
    unsigned int bufferIndex = 0;
    glGenVertexArrays(SCR_SQUARES, VAOs);
    glGenBuffers(SCR_SQUARES, VBOs);
    glGenBuffers(SCR_SQUARES, EBOs);
    // 3D Array Points of all the Squares
    float squares[SCR_SQUARES_X][SCR_SQUARES_Y][SCR_POINTS_PER_SQUARE]{};
    unsigned int sizOfSquare = sizeof(squares[0][0]);
    // Points to create a square from two triangles
    unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
    };
    unsigned int sizeOfIndices = sizeof(indices);
    // Delta in X and Y for the Squares
    float deltaX = SCR_GLFW_Range / SCR_SQUARES_X;
    float deltaY = SCR_GLFW_Range / SCR_SQUARES_Y;
    float sizeSquareXHalf = deltaX / 2;
    float sizeSquareYHalf = deltaY / 2;
    float centerX = 0.0;
    float centerY = 0.0;

    for (int x = 0; x < SCR_SQUARES_X; x++) {
        centerX = deltaX * x + deltaX / 2 - SCR_GLFW_Range / 2;
        for (int y = 0; y < SCR_SQUARES_Y; y++) {
            centerY = deltaY * y + deltaY / 2 - SCR_GLFW_Range / 2;
            // calculate the points of the square
            float squareCoordinates[] = {
                centerX + sizeSquareXHalf, centerY + sizeSquareYHalf, 0.0f,  // top right
                centerX + sizeSquareXHalf, centerY - sizeSquareYHalf, 0.0f,  // bottom right
                centerX - sizeSquareXHalf, centerY - sizeSquareYHalf, 0.0f,  // bottom left
                centerX - sizeSquareXHalf, centerY + sizeSquareYHalf, 0.0f   // top left 
            };
            // fill in the Points of the square
            for (int i = 0; i < SCR_POINTS_PER_SQUARE; i++) {
                squares[x][y][i] = squareCoordinates[i];
                // cout << "Coordinates " << squares[x][y][i] << endl
            }
            //cout << "Bufferindex " << bufferIndex << endl;
            glBindVertexArray(VAOs[bufferIndex]);
            glBindBuffer(GL_ARRAY_BUFFER, VBOs[bufferIndex]);
            glBufferData(GL_ARRAY_BUFFER, sizOfSquare, squares[x][y], GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[bufferIndex]);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfIndices, indices, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	// Vertex attributes stay the same
            glEnableVertexAttribArray(0);
            // glBindVertexArray(0); // no need to unbind at all as we directly bind a different VAO the next few lines.
            // but beware of calls that could affect VAOs while this one is bound (like binding element buffer objects, or enabling/disabling vertex attributes)
            bufferIndex++;
        }

    }

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
        bufferIndex = 0;

        for (int x = 0; x < SCR_SQUARES_X; x++) {
            for (int y = 0; y < SCR_SQUARES_Y; y++) {
                
                switch (sim.worldPlayground[x+1][y+1]->who()) {
                case EMPTY:
                    glUseProgram(shaderProgramOrange);
                    break;
                case GRASS:
                    glUseProgram(shaderProgramYellow);
                    break;
                case RABBIT:
                    if (static_cast<Animal*>(sim.worldPlayground[x][y])->getGender())
                        glUseProgram(shaderProgramYellow);
                    else
                        glUseProgram(shaderProgramYellow);
                    break;
                case FOX:
                    if (static_cast<Animal*>(sim.worldPlayground[x][y])->getGender())
                        glUseProgram(shaderProgramYellow);
                    else
                        glUseProgram(shaderProgramYellow);
                    break;
                default:
                    break;
                }
                glBindVertexArray(VAOs[bufferIndex]);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                bufferIndex++;
            }
        }

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteProgram(shaderProgramOrange);
    glDeleteProgram(shaderProgramYellow);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}
