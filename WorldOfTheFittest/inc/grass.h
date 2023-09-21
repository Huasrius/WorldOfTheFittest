/*H***********************************************************
* FILENAME :  grass.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for Class Grass
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

#ifndef GRASS_H
#define GRASS_H
#include "living.h"

/**
 * @brief The Grass class inherit from class Living.
 *        It contains two methodes, one gives back the Role Grass and the action
 *        method for let grow som more grass in the neighborhood.
 */
class Grass : public Living
{
public:
    Grass(int x, int y, Shader* shader);
    Role who();
    unsigned growLevel;
    void action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]);
    void draw();
};

#endif // GRASS_H
