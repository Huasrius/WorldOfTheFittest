/*H***********************************************************
* FILENAME :  fox.h
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The header File for Class Fox
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
    Fox(int x, int y, int age, Shader* shader);
    Role who();
    void action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]);
    void draw();
};

#endif // FOX_H
