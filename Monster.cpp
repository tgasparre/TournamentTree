/**
 * Tatiana Gasparre
 * CPSC350-01
 */
#include "Monster.h"
using namespace std;
/**
 * the monster class creates the monster object and impliments operators to help with determining the winner of the tournament
 */

/**
 * Monster - the constructor, creates a monster object from the given name and power level
 * @param name - a string representing the name of the monster
 * @param screamPowerLevel - an integer representing the power level of the monster
 */
Monster::Monster(string name, int screamPowerLevel)
{
    this->name = name;
    screamPower = screamPowerLevel;    
}

/**
 * ~Monster - the destructor, destroys the monster object
 */
Monster::~Monster()
{

}

/**
 * operator< - overloads the less than comparison operator
 * @return a boolean: true if the monster on the left hand side has a smaller scream power value than the one on the right hand side 
 * and false otherwise
 * @param monsterToCompare - the monster object that would be on the right hand side of the operator
 */
bool Monster::operator<(const Monster& monsterToCompare)
{
    return this->screamPower < monsterToCompare.screamPower;
}

/**
 * operator> - overloads the greater than comparison operator
 * @return a boolean: true if the monster on the left hand side has a larger scream power value than the one on the right hand side 
 * and false otherwise
 * @param monsterToCompare - the monster object that would be on the right hand side of the operator
 */
bool Monster::operator>(const Monster& monsterToCompare)
{
    return this->screamPower > monsterToCompare.screamPower;
}

/**
 * operator== - overloads the equality comparison operator
 * @return a boolean: true if the scream power of the two monsters are equal
 * and false otherwise
 * @param monsterToCompare - the monster object that would be on the right hand side of the operator
 */
bool Monster::operator==(const Monster& monsterToCompare)
{
    return this->screamPower == monsterToCompare.screamPower;
}

/**
 * operator= - overloads the assignment operator, overwriting the left hand side monster's scream power and 
 * name with the scream power and name of the right hand side monster
 * @param monsterToCompare - the monster object that would be on the right hand side of the operator
 */
void Monster::operator=(const Monster& monsterToCompare)
{
    this->screamPower = monsterToCompare.screamPower;
    this->name = monsterToCompare.name;

}
