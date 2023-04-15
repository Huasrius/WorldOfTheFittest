/*H***********************************************************
* FILENAME :  rabbit.h        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The header File for Class Rabbit
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
    void action(Living** neighborhood[NEIGHBORHOOD_SIZE]);
};

#endif // RABBIT_H
