/********************************************************************* 
** Program name: HarryPotter Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: HarryPotter.hpp is the HarryPotter class specification 
**				file. Harry Potter is a wizard. If Harry Potter's 
**				strength reaches 0 or below, he immediately recovers 
**				and his total strength becomes 20. If he were to die 
**				again, then he’s dead.
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character{

private:
	bool revive;

public:

	/********************************************************************* 
	** Description: Constructor for the HarryPotter class.
	*********************************************************************/
	HarryPotter();
	
	/********************************************************************* 
	** Description: defend function that calculates the effect of an
	**				attack from a different character, damage, that
	**				subtracts the defending character's dice roll and
	**				armor from the attackers dice roll. If Harry Potter's 
	**				strength reaches 0 or below, he immediately recovers 
	**				and his total strength becomes 20. If he were to die 
	**				again, then he’s dead.
	*********************************************************************/
	void defend(int);

};

#endif