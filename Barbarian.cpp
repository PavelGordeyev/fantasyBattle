/********************************************************************* 
** Program name: Barbarian Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: Barbarian.cpp is the Barbarian class implementation 
**				file. Think Conan or Hercules from the movies. 
**				Big sword, big muscles, bare torso. No special
**				abilities.
*********************************************************************/
#include "Barbarian.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the Barbarian class.
*********************************************************************/
Barbarian::Barbarian() : Character(){
	this->charType = "Barbarian";
	this->attack = "2d6";
	this->defense = "2d6";
	
	this->armor = 0;
	this->strength = 12;

	this->setupDice();
}

/********************************************************************* 
** Description: defend function that calculates the effect of an
**				attack from a different character, damage, that
**				subtracts the defending character's dice roll and
**				armor from the attackers dice roll. 
*********************************************************************/
void Barbarian::defend(int attackVal){

	int numDice = this->getNumDice(this->defense),
		sumDefense = 0,
		damageCheck,
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
	this->setStrength(this->strength - this->damage);
}