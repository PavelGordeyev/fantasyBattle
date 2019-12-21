/********************************************************************* 
** Program name: Character Class
** Author: Pavel Gordeyev
** Date: 11/16/19
** Description: Character.cpp is the Character class implementation 
**				file. It is part of	a fantasy combat game, that 
**				contains Vampire, Barbarian, Blue Men, Medusa, and 
**				Harry Potter. Each character has attributes of attack, 
**				defense, armor, and strength points.  The attack
**				and defend methods are virtual, with the defend
**				method being purely virtual.  This is an abstract
**				class.  It uses the Die class to simulate the rolling
**				of dice for all Character children.
*********************************************************************/
#include "Character.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the Character class.
*********************************************************************/
Character::Character(){
	this->damage = 0;
}

/********************************************************************* 
** Description: setupDice function that sets up the attack and 
**				defense dice.
*********************************************************************/
void Character::setupDice(){

	// Set up the dice
	this->attackDice = new Die*[this->getNumDice(this->attack)];
	this->defenseDice = new Die*[this->getNumDice(this->defense)];

	// Create attack dice
	for(int i =0;i<getNumDice(this->attack);i++){
		this->attackDice[i] = new Die(this->getNumSides(this->attack));	
	}

	// Create defense dice
	for(int i =0;i<getNumDice(this->defense);i++){
		this->defenseDice[i] = new Die(this->getNumSides(this->defense));	
	}
}

/********************************************************************* 
** Description: getNumDice function returns the number of dice that
**				will be rolled based on the attack/defense string.
*********************************************************************/
int Character::getNumDice(std::string dieType){

	// Get the number of dice
	return stoi(dieType.substr(0,1));
}

/********************************************************************* 
** Description: getNumSides function returns the number of sides
**				of the dice that will be rolled based on the 
**				attack/defense string.
*********************************************************************/
int Character::getNumSides(std::string dieType){

	int dPos;

	// Find the position of the 'd'
	dPos = dieType.find('d');

	// Get the number of sides of the dice
	return stoi(dieType.substr(dPos + 1));
}

/********************************************************************* 
** Description: doAttack function that calculates the full attack
**				value for a respective character based on the dice
**				rolled by the attacker.
*********************************************************************/
int Character::doAttack(){
	
	int numDice = getNumDice(this->attack),
		sumAttack = 0,
		dieRoll;

	// Get the sum for all the dice rolled
	for(int i=0;i<numDice;i++){
		
		// Roll the die
		dieRoll = this->attackDice[i]->rollingDie();

		// Add to the total attack
		sumAttack += dieRoll;
	}

	return sumAttack;
	
}

/********************************************************************* 
** Description: getArmor function returns the character's armor value.
*********************************************************************/
int Character::getArmor(){
	return this->armor;
}

/********************************************************************* 
** Description: getAttackerType returns the name of the character
**				type.
*********************************************************************/
std::string Character::getCharacterType(){
	return this->charType;
}


/********************************************************************* 
** Description: getStrength function returns the character's strength.
*********************************************************************/
int Character::getDamage(){
	return this->damage;
}

/********************************************************************* 
** Description: getStrength function returns the character's strength.
*********************************************************************/
std::string Character::getDefense(){
	return this->defense;
}

/********************************************************************* 
** Description: getStrength function returns the character's strength.
*********************************************************************/
int Character::getStrength(){
	return this->strength;
}

/********************************************************************* 
** Description: getName function returns the name for a character.
*********************************************************************/
std::string Character::getName(){
	return this->name;
}

/********************************************************************* 
** Description: setStrength function that sets the strength of the
**				character to the specified value.
*********************************************************************/
void Character::setStrength(int strength){
	this->strength = strength;
}

/********************************************************************* 
** Description: setDefense function that sets the defense of the 
**				character.
*********************************************************************/
void Character::setDefense(std::string defense){
	this->defense = defense;
}

/********************************************************************* 
** Description: setName function sets the name for a character.
*********************************************************************/
void Character::setName(std::string name){
	this->name = name;
}

/********************************************************************* 
** Description: recovery function adds some strength to the character
**				after winning a battle.
*********************************************************************/
void Character::recover(){

	Die *recDie = new Die(5);

	// Roll a die
	int randInt  = recDie->rollingDie();

	// Set the new strength
	this->setStrength(this->getStrength() + randInt);

	// Delete the die
	delete recDie;
}

/********************************************************************* 
** Description: Destructor for the Character class.
*********************************************************************/
Character::~Character(){
	
	// Delete attack dice
	for(int i =0;i<this->getNumDice(this->attack);i++){
		delete attackDice[i];
	}

	delete [] attackDice;

	// Delete defense dice
	for(int i =0;i<this->getNumDice(this->defense);i++){
		delete defenseDice[i];	
	}

	delete [] defenseDice;
}