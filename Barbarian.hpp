/********************************************************************* 
** Program name: Barbarian Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: Barbarian.hpp is the Barbarian class specification 
**				file. Think Conan or Hercules from the movies. 
**				Big sword, big muscles, bare torso. No special
**				abilities.
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character{

public:

	/********************************************************************* 
	** Description: Constructor for the Barbarian class.
	*********************************************************************/
	Barbarian();
	
	/********************************************************************* 
	** Description: defend function that calculates the effect of an
	**				attack from a different character, damage, that
	**				subtracts the defending character's dice roll and
	**				armor from the attackers dice roll. 
	*********************************************************************/
	void defend(int);

};

#endif