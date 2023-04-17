/*H***********************************************************
* FILENAME :  grass.cpp        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
* The .cpp File descripes all Methodes of the class header File
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

#include "grass.h"

/**
 * @brief The Constructor Grass::Grass initialize the position of the grass Class,
 *        and set the growLevel to an DEFAULT_GROW_LEVEL
 * @param x
 * @param y
 */
Grass::Grass(int x, int y):
    growLevel(DEFAULT_GROW_LEVEL)
{
    location.x = x;
    location.y = y;
}

/**
 * @brief Grass::who returns the Role Grass
 * @return an enumeration Role
 */
Role Grass::who() {
    return GRASS;
}

/**
 * @brief Grass::action can replace an empty class in the neighborhood with a class grass
 * @param an Array neighborhood of size NEIGHBORHOOD_SIZE with Living double Pointer
 */
void Grass::action(Living **neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]){
    for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ )
        if(*neighborhood[GROUND][i]!= nullptr)
            // If the neighborhood is empty a new grass grows with a chance of a half
            if((*neighborhood[GROUND][i])->who() == EMPTY){
                if(rand()%2 == 0){
                    Living* temp = *neighborhood[GROUND][i];
                    *neighborhood[GROUND][i] = new Grass((*neighborhood[GROUND][i])->location.x,(*neighborhood[GROUND][i])->location.y);
                    delete temp;
                }
            }
    if (growLevel < MAX_GROW_LEVEL)
        growLevel++;
}
