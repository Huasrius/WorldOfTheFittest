/*H***********************************************************
* FILENAME :  empty.cpp
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
* The .cpp File descripes all Methodes of the class header File
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
inline void Empty::action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE])
{
     static_cast<void>(neighborhood);
}
