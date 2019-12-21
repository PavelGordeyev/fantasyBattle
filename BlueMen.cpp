/********************************************************************* 
** Program name: BlueMen Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: BlueMen.cpp is the BlueMen class implementation 
**				file. They are small, 6 inch tall, but fast and tough. 
**				They are hard to hit so they can take some damage. 
**				They can also do a LOT of damage when they crawl 
**				inside enemies’ armor or clothing. Blue Men are 
**				actually a swarm of small individuals. For every 4 
**				points of damage, they lose one defense die. 
*********************************************************************/
#include "BlueMen.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the BlueMen class.
*********************************************************************/
BlueMen::BlueMen() : Character(){
	this->charType = "BlueMen";
	this->attack = "2d10";
	this->defense = "3d6";
	
	this->armor = 3;
	this->strength = 12;

	this->setupDice();
}

/********************************************************************* 
** Description: defend function that calculates the effect of an
**				attack from a different character, damage, that
**				subtracts the defending character's dice roll and
**				armor from the attackers dice roll. For every 4 
**				points of damage, they lose one defense die. 
*********************************************************************/
void BlueMen::defend(int attackVal){

	int numDice,
		sumDefense = 0,
		damageCheck,
		pos,
		dieRoll;

	std::string def = this->getDefense();
	
	numDice = this->getNumDice(def);

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
	this->setStrength(this->getStrength() - this->getDamage());

	// Update the defense move
	// Lose 1 defense die for every 4 damage
	if(this->getStrength() != 12 && this->getStrength() % 4 == 0){

		// Get the position of the 'd' in the defense string
		pos = def.find('d');

		// Won't leave bluemen with less than 1 die
		if(numDice > 1){
			// Set the defense to 1 die lower
			this->setDefense(std::to_string(numDice - 1) + def.substr(pos));

			// Remove the die from the defenseDice array
			delete this->defenseDice[numDice-1];
		}

	}	

}