/********************************************************************* 
** Program name: Medusa Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: Medusa.cpp is the Medusa class implementation 
**				file. Scrawny lady with snakes for hair which helps 
**				her during combat. Just don’t look at her! If a 
**				Medusa rolls a 12 when attacking then the target 
**				instantly gets turned into stone and Medusa wins! 
**				If Medusa uses Glare on Harry Potter on his first 
**				life, then Harry Potter comes back to life.
*********************************************************************/
#include "Medusa.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the Medusa class.
*********************************************************************/
Medusa::Medusa() : Character(){
	this->charType = "Medusa";
	this->attack = "2d6";
	this->defense = "1d6";
	
	this->armor = 3;
	this->strength = 8;

	this->setupDice();
}

/********************************************************************* 
** Description: doAttack function that calculates the full attack
**				value for the Medusa character based on the dice
**				rolled by the attacker.  Wins if it rolls a 12.
*********************************************************************/
int Medusa::doAttack(){
	int numDice = this->getNumDice(this->attack),
		sumAttack = 0,
		dieRoll;

	// Sum up the total value of the defense roll
	for(int i=0;i<numDice;i++){

		// Roll the die
		dieRoll = this->attackDice[i]->rollingDie();

		// Sum the defense roll
		sumAttack += dieRoll;
	}

	// Glare ability of Medusa to turn to stone, aka kill the 
	// opponent immediately
	if(sumAttack == 12){
		return 100;
	}

	return sumAttack;
}

/********************************************************************* 
** Description: defend function that calculates the effect of an
**				attack from a different character, damage, that
**				subtracts the defending character's dice roll and
**				armor from the attackers dice roll. 
*********************************************************************/
void Medusa::defend(int attackVal){

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