/*H***********************************************************
* FILENAME :  grass.h        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The header File for Class Grass
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
    Grass(int x, int y);
    Role who();
    unsigned growLevel;
    void action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]);
};

#endif // GRASS_H
