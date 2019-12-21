/********************************************************************* 
** Program name: HarryPotter Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: HarryPotter.cpp is the HarryPotter class implementation 
**				file. Harry Potter is a wizard. If Harry Potter's 
**				strength reaches 0 or below, he immediately recovers 
**				and his total strength becomes 20. If he were to die 
**				again, then he’s dead.
*********************************************************************/
#include "HarryPotter.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the HarryPotter class.
*********************************************************************/
HarryPotter::HarryPotter() : Character(){
	this->charType = "Harry Potter";
	this->attack = "2d6";
	this->defense = "2d6";
	
	this->armor = 0;
	this->strength = 10;

	this->revive = true;

	this->setupDice();
}

/********************************************************************* 
** Description: defend function that calculates the effect of an
**				attack from a different character, damage, that
**				subtracts the defending character's dice roll and
**				armor from the attackers dice roll. If Harry Potter's 
**				strength reaches 0 or below, he immediately recovers 
**				and his total strength becomes 20. If he were to die 
**				again, then he’s dead.
*********************************************************************/
void HarryPotter::defend(int attackVal){

	int numDice = this->getNumDice(this->defense),
		sumDefense = 0,
		damageCheck = 0,
		dieRoll;

	// Sum up the total value of the defense roll
	for(int i=0;i<numDice;i++){

		// Roll the die
		dieRoll = this->defenseDice[i]->rollingDie();

		// Sum the defense roll
		sumDefense += dieRoll;
	}
	
	// Calculate the damage; cannot be less than 0
	damageCheck = attackVal - sumDefense - this->armor;

	if(damageCheck < 0){
		this->damage = 0;
	}else{
		this->damage = damageCheck;
	}

	// Update strength
	if((this->strength - this->damage < 0) && this->revive){
		this->setStrength(20);
		this->revive = false;
	}else{
		this->setStrength(this->strength - this->damage);
	}
		
}