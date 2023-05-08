/*H***********************************************************
* FILENAME :  empty.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for Class Empty
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

#ifndef EMPTY_H
#define EMPTY_H
#include "living.h"

/**
 * @brief The Empty class inherit from class Living.
 *        It contains two methodes, one gives back the Role Empty and the action
 *        method do nothing.
 */
class Empty : public Living
{
public:
    Empty(int x, int y);
    Role who();
    void action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]);
    void draw();
};

#endif // EMPTY_H
