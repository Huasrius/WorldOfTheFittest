/*H***********************************************************
* FILENAME :  fox.cpp        REF : BTF3231
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

#include "fox.h"

/**
 * @brief The constructor Fox::Fox initialize the position of the fox class
 *        and the age. Age is by birth 0 and by first initialization random
 * @param x
 * @param y
 * @param age
 */
Fox::Fox(int x, int y, int age)
{
    location.x = x;
    location.y = y;
    this->age = age;
}

/**
 * @brief  Fox::who returns the role fox
 * @return an enumeration role
 */
Role Fox::who(){
    return FOX;
}

/**
 * @brief Fox::action can destroy the neighborhood or set a new fox in neigborhood
 * @param an Array neighborhood of size NEIGHBORHOOD_SIZE with living double Pointer
 */
void Fox::action(Living** neighborhood[NEIGHBORHOOD_SIZE]) {
    repletionLevel--;

    // If the Fox is pregnant it giving birth to new Foxes
    // The new Foxes replace an empty or a grass Class
    if(isPregnant) {
        for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ ) {
            if(*neighborhood[i] != nullptr) {
                if((*neighborhood[i])->who() == EMPTY || (*neighborhood[i])->who() == GRASS) {
                    Living* temp = *neighborhood[i];
                    *neighborhood[i] = new Fox((*neighborhood[i])->location.x,(*neighborhood[i])->location.y,0);
                    delete temp;
                }
            }
        }
        isPregnant = false;
    }

    for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ ){
        if(*neighborhood[i] != nullptr) {
            // If it has rabbits in the neigborhood and the fox is still hungry, he eats rabbits
            // The rabbits place is replaced by an empty class
            if((*neighborhood[i])->who() == RABBIT && repletionLevel <= FOX_MAX_REPLETION_LEVEL) {
                Living *temp = *neighborhood[i];
                *neighborhood[i]= new Empty((*neighborhood[i])->location.x,(*neighborhood[i])->location.y);
                delete temp;
                repletionLevel+= 2;
            }
            // If the fox genders is female and it reached sexual maturity and it has Male foxes with sexual maturity
            // in the neigborhood, the fox gets pregnant.
            if((*neighborhood[i])->who() == FOX && static_cast<Animal*>(*neighborhood[i])->getGender() == MALE
                    && gender == FEMALE && static_cast<Animal*>(*neighborhood[i])->getAge() >= FOX_SEXUAL_MATURITY
                    && age >= FOX_SEXUAL_MATURITY) {
                isPregnant = true;
            }
        }
    }
    age++;
}
