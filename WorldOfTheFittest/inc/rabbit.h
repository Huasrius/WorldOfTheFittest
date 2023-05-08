/*H***********************************************************
* FILENAME :  rabbit.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for Class Rabbit
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

#ifndef RABBIT_H
#define RABBIT_H

#include "animal.h"
#include "grass.h"
#include "empty.h"

/**
 * @brief The Rabbit class inherit from class Animal.
 *        It contains two methodes, one gives back the Role Rabbit and the action
 *        method for do some action on the Playground.
 */
class Rabbit : public Animal
{
public:
    Rabbit(int x,int y,int age);
    Role who();
    void action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]);
    void draw();
};

#endif // RABBIT_H
