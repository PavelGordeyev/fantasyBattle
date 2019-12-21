/********************************************************************* 
** Program name: BlueMen Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: BlueMen.hpp is the BlueMen class specification 
**				file. They are small, 6 inch tall, but fast and tough. 
**				They are hard to hit so they can take some damage. 
**				They can also do a LOT of damage when they crawl 
**				inside enemies’ armor or clothing. Blue Men are 
**				actually a swarm of small individuals. For every 4 
**				points of damage, they lose one defense die. 
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character{

public:

	/********************************************************************* 
	** Description: Constructor for the BlueMen class.
	*********************************************************************/
	BlueMen();
	
	/********************************************************************* 
	** Description: defend function that calculates the effect of an
	**				attack from a different character, damage, that
	**				subtracts the defending character's dice roll and
	**				armor from the attackers dice roll. For every 4 
	**				points of damage, they lose one defense die. 
	*********************************************************************/
	void defend(int);

};

#endif