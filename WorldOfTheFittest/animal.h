/*H***********************************************************
* FILENAME :  animal.h        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The header File for Class Animal
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

#ifndef ANIMAL_H
#define ANIMAL_H
#include "living.h"

/**
 * @brief The Animal class inherit from class Living.
 *        Animal is a base class for all possible animals. It contains
 *        age, repletion Level, gender and a boolean variable for pregnancy
 *        it has four methodes, three for getting the protected memberes and
 *        one virtual action methode for do some action on the Playground.
 */
class Animal: public Living
{
protected:
    unsigned int age, repletionLevel;
    enum Gender{MALE,FEMALE,MAX_GENDER}gender;
public:
    bool isPregnant;
    Animal();
    virtual Role who() = 0;
    virtual void action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]) = 0;
    unsigned int getAge();
    unsigned int getGender();
    unsigned int getRepletionLevel();
};

#endif // ANIMAL_H
