/*H***********************************************************
* FILENAME :  empty.cpp        REF : BTF3231
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

#include "empty.h"

/**
 * @brief The Constructor Empty::Empty initialize the position of the empty Class
 * @param x
 * @param y
 */
Empty::Empty(int x, int y)
{
    location.x = x;
    location.y = y;
}

/**
 * @brief  Empty::who returns the Role Empty
 * @return an enumeration Role
 */
Role Empty::who(){
    return EMPTY;
}

/**
 * @brief Empty::action make a static_cast to void from the array neighborhood prevent a warning
 * @param an Array neighborhood of size NEIGHBORHOOD_SIZE with Living double Pointer
 */
inline void Empty::action(Living** neighborhood[NEIGHBORHOOD_SIZE])
{
     static_cast<void>(neighborhood);
}
