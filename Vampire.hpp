/********************************************************************* 
** Program name: Vampire Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: Vampire.hpp is the Vampire class specification 
**				file. The Vampire is suave, debonair, but vicious 
**				and surprisingly resilient. Vampires can charm an 
**				opponent into not attacking. For a given attack 
**				there is a 50% chance that their opponent does not 
**				actually attack them.
*********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character{

public:

	/********************************************************************* 
	** Description: Constructor for the Vampire class.
	*********************************************************************/
	Vampire();
	
	/********************************************************************* 
	** Description: defend function that calculates the effect of an
	**				attack from a different character, damage, that
	**				subtracts the defending character's dice roll and
	**				armor from the attackers dice roll. For a given attack 
	**				there is a 50% chance that their opponent does not 
	**				actually attack them.
	*********************************************************************/
	void defend(int);

	/********************************************************************* 
	** Description: charm function for the Vampire that can charm the 
	**				opponent into not attacking.  For a given attack,
	**				there is a 50% chance that the opponent will attack.
	*********************************************************************/
	bool charm();

	/********************************************************************* 
	** Description: randomNumGenerator function outputs a random number
	**				between specified low and high integers >= 0.
	*********************************************************************/
	int randomNumGenerator(int,int);

};

#endif