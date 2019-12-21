/********************************************************************* 
** Program name: Character Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: Character.hpp is the Character class specification 
**				file. It is part of	a fantasy combat game, that 
**				contains Vampire, Barbarian, Blue Men, Medusa, and 
**				Harry Potter. Each character has attributes of attack, 
**				defense, armor, and strength points.  The attack
**				and defend methods are virtual, with the defend
**				method being purely virtual.  This is an abstract
**				class.  It uses the Die class to simulate the rolling
**				of dice for all Character children.
*********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Die.hpp"
#include <string>

class Character{

public:
	/********************************************************************* 
	** Description: Constructor for the Character class.
	*********************************************************************/
	Character();

	/********************************************************************* 
	** Description: Destructor for the Character class.
	*********************************************************************/
	virtual ~Character();

	/********************************************************************* 
	** Description: doAttack function that calculates the full attack
	**				value for a respective character based on the dice
	**				rolled by the attacker.
	*********************************************************************/
	virtual int doAttack();

	/********************************************************************* 
	** Description: defend function that calculates the effect of an
	**				attack from a different character, damage, that
	**				subtracts the defending character's dice roll and
	**				armor from the attackers dice roll. 
	*********************************************************************/
	virtual void defend(int) = 0;

	/********************************************************************* 
	** Description: getArmor function returns the character's armor value.
	*********************************************************************/
	int getArmor();

	/********************************************************************* 
	** Description: getAttackerType returns the name of the character
	**				type.
	*********************************************************************/
	std::string getCharacterType();

	/********************************************************************* 
	** Description: getStrength function returns the character's damage.
	*********************************************************************/
	int getDamage();

	/********************************************************************* 
	** Description: getStrength function returns the character's strength.
	*********************************************************************/
	std::string getDefense();

	/********************************************************************* 
	** Description: getStrength function returns the character's strength.
	*********************************************************************/
	int getStrength();

	/********************************************************************* 
	** Description: getName function returns the name for a character.
	*********************************************************************/
	std::string getName();

	/********************************************************************* 
	** Description: setStrength function that sets the strength of the
	**				character to the specified value.
	*********************************************************************/
	void setStrength(int);

	/********************************************************************* 
	** Description: setDefense function that sets the defense of the 
	**				character.
	*********************************************************************/
	void setDefense(std::string);

	/********************************************************************* 
	** Description: setName function sets the name for a character.
	*********************************************************************/
	void setName(std::string);

	/********************************************************************* 
	** Description: recovery function adds some strength to the character
	**				after winning a battle.
	*********************************************************************/
	void recover();

protected:
	std::string charType,
				attack,
				defense,
				name;

	Die **attackDice,
		**defenseDice;

	int armor,
		damage,
		strength;

	/********************************************************************* 
	** Description: setupDice function that sets up the attack and 
	**				defense dice.
	*********************************************************************/
	void setupDice();

	/********************************************************************* 
	** Description: getNumDice function returns the number of dice that
	**				will be rolled based on the attack/defense string.
	*********************************************************************/
	int getNumDice(std::string);

	/********************************************************************* 
	** Description: getNumSides function returns the number of sides
	**				of the dice that will be rolled based on the 
	**				attack/defense string.
	*********************************************************************/
	int getNumSides(std::string);

};

#endif