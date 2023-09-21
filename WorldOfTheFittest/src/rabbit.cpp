/*H***********************************************************
* FILENAME :  rabbit.cpp
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

#include "rabbit.h"

/**
 * @brief The constructor Rabbit::Rabbit initialize the position of the rabbit class
 *        and the age. Age is by birth 0 and by first initialization random
 * @param x
 * @param y
 * @param age
 */
Rabbit::Rabbit(int x, int y, int age, int replitationLevel, Shader* shader)
{
    location.x = x;
    location.y = y;
    this->age = age;
    this->shader = shader;
    this->repletionLevel = replitationLevel;
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
void Rabbit::action(Living **neighborhood[BOARD_LEVELS][NEIGHBORHOOD_SIZE]){
    repletionLevel--;

    if(isPregnant) {
        for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ ) {
            if(*neighborhood[ABOVE][i] != nullptr) {
                if((*neighborhood[ABOVE][i])->who() == EMPTY) {
                    //if(rand()%2 == 0){
                    Living* temp = *neighborhood[ABOVE][i];
                    *neighborhood[ABOVE][i] = new Rabbit((*neighborhood[ABOVE][i])->location.x, (*neighborhood[ABOVE][i])->location.y, 0, RABBIT_BIRTH_REPLETION_LEVEL, shader);
                    delete temp;
                    //}
                }
            }
        }
        isPregnant = false;
    }

    for (size_t i = 0; i < NEIGHBORHOOD_SIZE; i++ ){
        if(*neighborhood[GROUND][i] != nullptr) {
            // If it has grass in the neigborhood and the rabbit is still hungry, he eats grass
            // The Grass growLevel is decremented
            if((*neighborhood[GROUND][i])->who() == GRASS && repletionLevel <= RABBIT_MAX_REPLETION_LEVEL) {
                static_cast<Grass*>(*neighborhood[GROUND][i])->growLevel--;
                repletionLevel++;
                // If the growLevel is 0 the grass is replaced by an empty class
                if(static_cast<Grass*>(*neighborhood[GROUND][i])->growLevel == 0) {
                    Living* temp = *neighborhood[GROUND][i];
                    *neighborhood[GROUND][i]= new Empty((*neighborhood[GROUND][i])->location.x, (*neighborhood[GROUND][i])->location.y);
                    delete temp;
                }
            }
            // If the rabbit genders is female and it reached sexual maturity and it has Male rabbits with sexual maturity
            // in the neigborhood, the rabbit gets pregnant.
            if((*neighborhood[ABOVE][i])->who() == RABBIT && static_cast<Animal*>(*neighborhood[ABOVE][i])->getGender() == MALE
                    && gender == FEMALE && static_cast<Animal*>(*neighborhood[ABOVE][i])->getAge() >= RABBIT_SEXUAL_MATURITY
                    && age >= RABBIT_SEXUAL_MATURITY) {
                isPregnant = true;
            }
        }
    }
    age++;
}

void Rabbit::draw() {

    // Set the color
    this->shader->setUniform4f("ourColor", 0.0f, 0.0f, 0.8f, 1.0f);
    // Calculate the center of the Rabbit to the screen range
    double centerX = SCR_LIVING_DELTA_X * location.x - SCR_LIVING_DELTA_X / 2 - SCR_GLFW_RANGE / 2;
    double centerY = SCR_LIVING_DELTA_Y * location.y - SCR_LIVING_DELTA_Y / 2 - SCR_GLFW_RANGE / 2;
    // Calculate a random offset for a more livly design
    centerX += (rand() / (RAND_MAX + 1.) - 0.5) * SCR_LIVING_DELTA_X * SCR_LIVING_OFFSET_FACTOR;
    centerY += (rand() / (RAND_MAX + 1.) - 0.5) * SCR_LIVING_DELTA_Y * SCR_LIVING_OFFSET_FACTOR;
    double radiusX = SCR_LIVING_DELTA_X * 0.4;
    double radiusY = SCR_LIVING_DELTA_Y * 0.4;

    drawCircle(centerX, centerY, radiusX, radiusY);

}