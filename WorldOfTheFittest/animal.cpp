/*H***********************************************************
* FILENAME :  animal.cpp        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The .cpp File descripes all Methodes of the class header File
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

#include "animal.h"

/**
 * @brief Animal::Animal
 *        The Animal Constructor initialize the members age, repletionLevel,
 *        gender and the boolean isPregnant
 */
Animal::Animal():
    age(0), repletionLevel(2),isPregnant(false)
{
    gender = static_cast<Gender>(rand()%MAX_GENDER);
}

/**
 * @brief Animal::getAge
 *        getAge returns the protected age of the Animal
 * @return age
 */
unsigned int Animal::getAge()
{
    return age;
}

/**
 * @brief Animal::getGender
 * @return getGender returns the protected gender of the Animal
 */
unsigned int Animal::getGender()
{
    return gender;
}

/**
 * @brief Animal::getRepletionLevel
 * @return returns the protected repletionLevel
 */
unsigned int Animal::getRepletionLevel()
{
    return repletionLevel;
}

