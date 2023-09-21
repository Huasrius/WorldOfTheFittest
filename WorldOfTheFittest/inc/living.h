/*H***********************************************************
* FILENAME :  living.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for Class Living
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

#ifndef LIVING_H
#define LIVING_H

#include <cstddef>
#include "properties.h"
#include "shapeDrawing.h"
#include "shader.h"

/**
 * @brief The Living Class is a base Class for all possible living objects. It contains
 *        the location, where the object is and it has two virtual methodes,
 *        one for giving back the role of the object and one for doing some action
 */
class Living {
public :
    Living();
    virtual ~Living() {}
    virtual Role who() = 0;
    virtual void action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]) = 0;
    virtual void draw() = 0;
    Shader* shader;
    struct  {
        unsigned x;
        unsigned y;
    }location;
};

#endif // LIVING_H
