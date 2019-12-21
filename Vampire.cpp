/********************************************************************* 
** Program name: Vampire Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: Vampire.cpp is the Vampire class implementation 
**				file. The Vampire is suave, debonair, but vicious 
**				and surprisingly resilient. Vampires can charm an 
**				opponent into not attacking. For a given attack 
**				there is a 50% chance that their opponent does not 
**				actually attack them.
*********************************************************************/
#include "Vampire.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the Vampire class.
*********************************************************************/
Vampire::Vampire() : Character(){
	this->charType = "Vampire";
	this->attack = "1d12";
	this->defense = "1d6";
	
	this->armor = 1;
	this->strength = 18;

	this->setupDice();

}

/********************************************************************* 
** Description: defend function that calculates the effect of an
**				attack from a different character, damage, that
**				subtracts the defending character's dice roll and
**				armor from the attackers dice roll. For a given attack 
**				there is a 50% chance that their opponent does not 
**				actually attack them.
*********************************************************************/
void Vampire::defend(int attackVal){

	int numDice = this->getNumDice(this->defense),
		sumDefense = 0,
		damageCheck = 0,
		dieRoll;

	if(this->charm()){
		// Charm worked; No attack occurred
	}else{

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
}

/********************************************************************* 
** Description: charm function for the Vampire that can charm the 
**				opponent into not attacking.  For a given attack,
**				there is a 50% chance that the opponent will attack.
*********************************************************************/
bool Vampire::charm(){

	// Determine if attack will take place
	if(randomNumGenerator(1,100) <= 50){
		return false;
	}else{
		return true;
	}
}

/********************************************************************* 
** Description: randomNumGenerator function outputs a random number
**				between specified low and high integers >= 0.
*********************************************************************/
int Vampire::randomNumGenerator(int low, int high){

	static int randInt;

	randInt = low + rand() % (high-low + 1);
	
	return randInt;
}