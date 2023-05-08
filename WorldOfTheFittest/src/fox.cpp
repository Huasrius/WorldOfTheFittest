/*H***********************************************************
* FILENAME :  fox.cpp
*
* PROJECT :
*  World of the fittest
*
* DESCRIPTION :
*   The .cpp File descripes all Methodes of the class header File
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
void Fox::action(Living** neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]) {
    repletionLevel--;

    // If the Fox is pregnant it giving birth to new Foxes
    // The new Foxes replace an empty or a grass Class
    if(isPregnant) {
        for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ ) {
            if(*neighborhood[ABOVE][i] != nullptr) {
                if((*neighborhood[ABOVE][i])->who() == EMPTY) {
                    Living* temp = *neighborhood[ABOVE][i];
                    *neighborhood[ABOVE][i] = new Fox((*neighborhood[ABOVE][i])->location.x,(*neighborhood[ABOVE][i])->location.y,0);
                    delete temp;
                }
            }
        }
        isPregnant = false;
    }

    for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ ){
        if(*neighborhood[ABOVE][i] != nullptr) {
            // If it has rabbits in the neigborhood and the fox is still hungry, he eats rabbits
            // The rabbits place is replaced by an empty class
            if((*neighborhood[ABOVE][i])->who() == RABBIT && repletionLevel <= FOX_MAX_REPLETION_LEVEL) {
                Living *temp = *neighborhood[ABOVE][i];
                *neighborhood[ABOVE][i]= new Empty((*neighborhood[ABOVE][i])->location.x,(*neighborhood[ABOVE][i])->location.y);
                delete temp;
                repletionLevel+= 2;
            }
            // If the fox genders is female and it reached sexual maturity and it has Male foxes with sexual maturity
            // in the neigborhood, the fox gets pregnant.
            if((*neighborhood[ABOVE][i])->who() == FOX && static_cast<Animal*>(*neighborhood[ABOVE][i])->getGender() == MALE
                    && gender == FEMALE && static_cast<Animal*>(*neighborhood[ABOVE][i])->getAge() >= FOX_SEXUAL_MATURITY
                    && age >= FOX_SEXUAL_MATURITY) {
                isPregnant = true;
            }
        }
    }
    age++;
}


void Fox::draw() {

}