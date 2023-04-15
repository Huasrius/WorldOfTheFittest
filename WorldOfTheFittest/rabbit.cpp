/*H***********************************************************
* FILENAME :  rabbit.cpp        REF : BTF3231
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

#include "rabbit.h"

/**
 * @brief The constructor Rabbit::Rabbit initialize the position of the rabbit class
 *        and the age. Age is by birth 0 and by first initialization random
 * @param x
 * @param y
 * @param age
 */
Rabbit::Rabbit(int x, int y, int age)
{
    location.x = x;
    location.y = y;
    this->age = age;
}

/**
 * @brief  Rabbit::who returns the role rabbit
 * @return an enumeration role
 */
Role Rabbit::who(){
    return RABBIT;
}


/**
 * @brief Rabbit::action can destroy the neighborhood or set a new rabbit in Neigborhood
 * @param an Array neighborhood of size NEIGHBORHOOD_SIZE with living double Pointer
 */
void Rabbit::action(Living **neighborhood[]){
    repletionLevel--;

    if(isPregnant) {
        for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ ) {
            if(*neighborhood[i] != nullptr) {
                if((*neighborhood[i])->who() == EMPTY || (*neighborhood[i])->who() == GRASS) {
                    //if(rand()%2 == 0){
                    Living* temp = *neighborhood[i];
                    *neighborhood[i] = new Rabbit((*neighborhood[i])->location.x,(*neighborhood[i])->location.y,0);
                    delete temp;
                    //}
                }
            }
        }
        isPregnant = false;
    }

    for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ ){
        if(*neighborhood[i] != nullptr) {
            // If it has grass in the neigborhood and the rabbit is still hungry, he eats grass
            // The Grass growLevel is decremented
            if((*neighborhood[i])->who() == GRASS && repletionLevel <= MAX_REPLETION_LEVEL_RABBIT) {
                static_cast<Grass*>(*neighborhood[i])->growLevel--;
                repletionLevel++;
                // If the growLevel is 0 the grass is replaced by an empty class
                if(static_cast<Grass*>(*neighborhood[i])->growLevel == 0) {
                    Living* temp = *neighborhood[i];
                    *neighborhood[i]= new Empty((*neighborhood[i])->location.x,(*neighborhood[i])->location.y);
                    delete temp;
                }
            }
            // If the rabbit genders is female and it reached sexual maturity and it has Male rabbits with sexual maturity
            // in the neigborhood, the rabbit gets pregnant.
            if((*neighborhood[i])->who() == RABBIT && static_cast<Animal*>(*neighborhood[i])->getGender() == MALE
                    && gender == FEMALE && static_cast<Animal*>(*neighborhood[i])->getAge() >= SEXUAL_MATURITY_RABBIT
                    && age >= SEXUAL_MATURITY_RABBIT) {
                isPregnant = true;
            }
        }
    }
    age++;
}

