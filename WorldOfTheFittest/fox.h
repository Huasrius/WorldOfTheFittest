/*H***********************************************************
* FILENAME :  fox.h        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The header File for Class Fox
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

#ifndef FOX_H
#define FOX_H

#include "animal.h"
#include "empty.h"
#include "rabbit.h"

/**
 * @brief The Fox classThe Fox class inherit from class Animal.
 *        It contains two methodes, one gives back the Role Fox and the action
 *        method for do some action on the Playground.
 */
class Fox : public Animal
{

public:
    Fox(int x, int y, int age);
    Role who();
    void action(Living** neighborhood[NEIGHBORHOOD_SIZE]);
};

#endif // FOX_H
