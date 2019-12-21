/********************************************************************* 
** Program name: Medusa Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: Medusa.hpp is the Medusa class specification 
**				file. Scrawny lady with snakes for hair which helps 
**				her during combat. Just don’t look at her! If a 
**				Medusa rolls a 12 when attacking then the target 
**				instantly gets turned into stone and Medusa wins! 
**				If Medusa uses Glare on Harry Potter on his first 
**				life, then Harry Potter comes back to life.
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character{

public:

	/********************************************************************* 
	** Description: Constructor for the Medusa class.
	*********************************************************************/
	Medusa();
	
	/********************************************************************* 
	** Description: doAttack function that calculates the full attack
	**				value for a respective character based on the dice
	**				rolled by the attacker.
	*********************************************************************/
	int doAttack();

	/********************************************************************* 
	** Description: defend function that calculates the effect of an
	**				attack from a different character, damage, that
	**				subtracts the defending character's dice roll and
	**				armor from the attackers dice roll. 
	*********************************************************************/
	void defend(int);

};

#endif