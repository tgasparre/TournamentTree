/**
 * Tatiana Gasparre
 * CPSC350-01
 */

#ifndef MONSTER_H
#define MONSTER_H
#include <string>

/**
 * the monster class creates the monster object and impliments operators to help with determining the winner of the tournament
 */
class Monster {
    public:
    /**
    * Monster - the constructor, creates a monster object from the given name and power level
    * @param name - a string representing the name of the monster
    * @param screamPowerLevel - an integer representing the power level of the monster
    */
        Monster(std::string name, int screamPowerLevel);

    /**
    * ~Monster - the destructor, destroys the monster object
    */
        ~Monster();

    /**
    * operator< - overloads the less than comparison operator
    * @return a boolean: true if the monster on the left hand side has a smaller scream power value than the one on the right hand side 
    * and false otherwise
    * @param monsterToCompare - the monster object that would be on the right hand side of the operator
    */
        bool operator<(const Monster& monsterToCompare);

    /**
    * operator> - overloads the greater than comparison operator
    * @return a boolean: true if the monster on the left hand side has a larger scream power value than the one on the right hand side 
    * and false otherwise
    * @param monsterToCompare - the monster object that would be on the right hand side of the operator
    */
        bool operator>(const Monster& monsterToCompare);

    /**
    * operator== - overloads the equality comparison operator
    * @return a boolean: true if the scream power of the two monsters are equal
    * and false otherwise
    * @param monsterToCompare - the monster object that would be on the right hand side of the operator
    */
        bool operator==(const Monster& monsterToCompare);

    /**
    * operator= - overloads the assignment operator, overwriting the left hand side monster's scream power and 
    * name with the scream power and name of the right hand side monster
    * @param monsterToCompare - the monster object that would be on the right hand side of the operator
    */
        void operator=(const Monster& monsterToCompare);

    /**
     * name - string member variable representing the name of the monster
     */
        std::string name;
    /**
     * screamPower - int member variable representing the scream power of the monster
     */
        int screamPower;
};

#endif
