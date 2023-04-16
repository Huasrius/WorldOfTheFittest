/*H***********************************************************
* FILENAME :  simulation.cpp        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The .cpp File descripes all Methodes of the class header File
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
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// settings for disaplay
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;
const unsigned int SCR_SQUARES_X = 39;
const unsigned int SCR_SQUARES_Y = 39;
const unsigned int SCR_SQUARES = SCR_SQUARES_X * SCR_SQUARES_Y;
const unsigned int SCR_POINTS_PER_SQUARE = 12;
const float SCR_GLFW_Range = 2.0;

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

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

/**
 * @brief The Simulation::Simulation constructor initialize the hole simulation, that means a worldplayground
 *        is filled with each role on randomly location
 */
Simulation::Simulation() {

    srand(static_cast<unsigned>(clock()));

    //set the limit for WorldPlayground
    for (unsigned ix = 0; ix < EDGE_LENGTH_GAME_BOARD + 2; ix++){
        worldPlayground[ix][0] = nullptr;
        worldPlayground[ix][EDGE_LENGTH_GAME_BOARD + 1] = nullptr;
    }
    for (unsigned iy = 1; iy < EDGE_LENGTH_GAME_BOARD + 1; iy++){
        worldPlayground[0][iy] = nullptr;
        worldPlayground[EDGE_LENGTH_GAME_BOARD + 1][iy] = nullptr;
    }
    //fill the whole WorldPlayground with the Class Empty
    for (unsigned ix = 1; ix <= EDGE_LENGTH_GAME_BOARD; ix++)
        for (unsigned iy = 1; iy <= EDGE_LENGTH_GAME_BOARD; iy++){
            worldPlayground[ix][iy] = new Empty(ix,iy);
        }
    //fill randomly the WorldPlayground with the CLass Grass times GRASS_START_POPULATION
    setStart(GRASS);

    //fill randomly the WorldPlayground with the CLass Rabbit times RABBIT_START_POPULATION
    setStart(RABBIT);

    //fill randomly the WorldPlayground with the CLass FOX times FOX_START_POPULATION
    setStart(FOX);
    display();
}

/**
 * @brief Simulation::oneCycle simulate one cycle of the simulation and does action for all roles except empty.
 */
void Simulation::oneCycle(void){
    unsigned i = 0;
    //do action for all Fox Classes
    for(i = 0; i < statics.numberOfFoxes; i++){
        setNeighbors((*vec.fox[i])->location.x,(*vec.fox[i])->location.y);
        (*vec.fox[i])->action(neighbor);
        //  if the role dies, because of starvation or senility the place is replaced by an empty class
        if(static_cast<Animal*>(*vec.fox[i])->getAge() == LIFESPAN_FOX || static_cast<Animal*>(*vec.fox[i])->getRepletionLevel() == 0) {
            Living* temp = worldPlayground[(*vec.fox[i])->location.x][(*vec.fox[i])->location.y];
            worldPlayground[(*vec.fox[i])->location.x][(*vec.fox[i])->location.y] = new Empty((*vec.fox[i])->location.x,(*vec.fox[i])->location.y);
            delete temp;
        }
    }

    //do action for all Rabbit Classes
    for(i = 0; i < statics.numberOfRabbits; i++){
        // in the rabbits vector could be empty classes, beacause a fox has eaten them, so it's necessary to check if it is a rabbit
        if((*vec.rabbit[i])->who() == RABBIT){
            setNeighbors((*vec.rabbit[i])->location.x,(*vec.rabbit[i])->location.y);
            (*vec.rabbit[i])->action(neighbor);
            //  if the role dies, because of starvation or senility the place is replaced by an empty class
            if(static_cast<Animal*>(*vec.rabbit[i])->getAge() == LIFESPAN_FOX || static_cast<Animal*>(*vec.rabbit[i])->getRepletionLevel() == 0) {
                Living* temp = worldPlayground[(*vec.rabbit[i])->location.x][(*vec.rabbit[i])->location.y];
                worldPlayground[(*vec.rabbit[i])->location.x][(*vec.rabbit[i])->location.y] = new Empty((*vec.rabbit[i])->location.x,(*vec.rabbit[i])->location.y);
                delete temp;
            }
        }
    }

    //do action for all Grass Classes
    for(i = 0; i < statics.numberOfGrass; i++){
        // in the grass vector could be empty classes, beacause a rabbit has eaten them, so it's necessary to check if it is a grass
        if((*vec.grass[i])->who() == GRASS){
            setNeighbors((*vec.grass[i])->location.x,(*vec.grass[i])->location.y);
            (*vec.grass[i])->action(neighbor);
        }
    }
    // fill the vectors again
    fillVectors();
}

/**
 * @brief Simulation::setNeighbors fills the array neighbor with the location's neigborhood
 * @param x
 * @param y
 */
void Simulation::setNeighbors(unsigned x, unsigned y){
    neighbor[0] = &worldPlayground[x-1][y-1];
    neighbor[1] = &worldPlayground[x][y-1];
    neighbor[2] = &worldPlayground[x+1][y-1];
    neighbor[3] = &worldPlayground[x+1][y];
    neighbor[4] = &worldPlayground[x+1][y+1];
    neighbor[5] = &worldPlayground[x][y+1];
    neighbor[6] = &worldPlayground[x-1][y+1];
    neighbor[7] = &worldPlayground[x-1][y];
}

/**
 * @brief Simulation::display displays the hole worldPlayground
 */
void Simulation::display(void) const {
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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
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
    int Test = SCR_SQUARES_Y % 2;
    cout << "Bufferindex " << (Test) << endl;
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
                if (bufferIndex % 2 == 0) {
                    glUseProgram(shaderProgramOrange);
                }
                else {
                    glUseProgram(shaderProgramYellow);
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

/**
 * @brief Simulation::setStart this is a function, which is called by the constructor and it initialize the
 *        world Playground randomly for each role
 * @param an Enumeration role
 */
void Simulation::setStart(Role role){
    unsigned x ,y;
    size_t startPopulation = 0;

    switch(role){
    case GRASS:
        startPopulation = GRASS_START_POPULATION;
        break;
    case RABBIT :
        startPopulation = RABBIT_START_POPULATION;
        break;
    case FOX :
        startPopulation = FOX_START_POPULATION;
        break;
    default :
        break;
    }

    //set a new grass, rabbit or fox at a random location and fill a vector for each role
    for(unsigned i = 0; i < startPopulation; i++){
        do{
            x = 1 + rand()%EDGE_LENGTH_GAME_BOARD;
            y = 1 + rand()%EDGE_LENGTH_GAME_BOARD;
        }while(EMPTY != worldPlayground[x][y]->who());

        switch(role){
        case GRASS:
            worldPlayground[x][y] = new Grass(x,y);
            vec.grass.push_back(&worldPlayground[x][y]);
            break;
        case RABBIT :
            worldPlayground[x][y] = new Rabbit(x,y,rand()%LIFESPAN_RABBIT);
            vec.rabbit.push_back(&worldPlayground[x][y]);
            break;
        case FOX :
            worldPlayground[x][y] = new Fox(x,y,rand()%LIFESPAN_RABBIT);
            vec.fox.push_back(&worldPlayground[x][y]);
            break;
        default :
            break;
        }
        statics.numberOfFoxes = vec.fox.size();
        statics.numberOfRabbits = vec.rabbit.size();
        statics.numberOfGrass = vec.grass.size();
    }
}

/**
 * @brief Simulation::fillVectors filles a vector from the worldPlayground for each role
 */
void Simulation::fillVectors(void){

    vec.fox.erase(vec.fox.begin(),vec.fox.end());
    vec.rabbit.erase(vec.rabbit.begin(),vec.rabbit.end());
    vec.grass.erase(vec.grass.begin(),vec.grass.end());

    for (unsigned x = 1; x <= EDGE_LENGTH_GAME_BOARD; x++)
        for (unsigned y = 1; y <= EDGE_LENGTH_GAME_BOARD; y++){
            switch(worldPlayground[x][y]->who()){
            case GRASS:
                vec.grass.push_back(&worldPlayground[x][y]);
                break;
            case RABBIT :
                vec.rabbit.push_back(&worldPlayground[x][y]);
                break;
            case FOX :
                vec.fox.push_back(&worldPlayground[x][y]);
                break;
            default :
                break;
            }
        }
    statics.numberOfFoxes = vec.fox.size();
    statics.numberOfRabbits = vec.rabbit.size();
    statics.numberOfGrass = vec.grass.size();
}


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