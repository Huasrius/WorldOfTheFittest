/*H***********************************************************
* FILENAME :  living.h        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The header File for Class Living
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

#ifndef LIVING_H
#define LIVING_H

#include "properties.h"
#include <cstddef>

/**
 * @brief The Living Class is a base Class for all possible living objects. It contains
 *        the location, where the object is and it has two virtual methodes,
 *        one for giving back the role of the object and one for doing some action
 */
class Living {
public :
    Living();
    virtual ~Living() {}
    virtual Role who() = 0;
    virtual void action(Living** neighborhood[NEIGHBORHOOD_SIZE]) = 0;
    struct  {
        unsigned x;
        unsigned y;
    }location;
};

#endif // LIVING_H
