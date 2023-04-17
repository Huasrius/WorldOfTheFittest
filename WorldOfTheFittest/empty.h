/*H***********************************************************
* FILENAME :  empty.h        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The header File for Class Empty
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
};

#endif // EMPTY_H
