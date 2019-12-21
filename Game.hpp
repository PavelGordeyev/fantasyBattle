/********************************************************************* 
** Program name: Game Class
** Author: Pavel Gordeyev
** Date: 11/18/19
** Description: Game.hpp is the Game class specification file. It is
**				a fantasy combat game, that contains Vampire, 
**				Barbarian, Blue Men, Medusa, and Harry Potter. 
**				Each character has attributes of attack, defense, 
**				armor, and strength points.  Two characters battle
**				for each match, and alternate attacking within the
**				rounds.  The first attacker of the round is chosen at 
**				random.  Once a character's strength is <=0, then the 
**				respective character dies.  Two characters battle
**				for each match, and alternate attacking within the
**				rounds.  It asks user for 2 teams to battle each
**				other, and outputs which team won or if it was a draw. 
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "CharQueue.hpp"
#include <iostream>
#include <string>

class Game{

private:
	int sizeAlpha,
		sizeBravo,
		sizeLosers,
		scoreAlpha,
		scoreBravo;

	Character *attacker,
		  *defender,
		  *mediator;

	CharQueue *teamAlpha,
			  *teamBravo,
			  *losers;

	Menu *startMenu,
		 *endMenu;

	/********************************************************************* 
	** Description: resetTournament function removes all the characters
	**				from Team Alpha, Team Bravo and losers to play the 
	**				tournament again.
	*********************************************************************/
	void resetTournament();

	/********************************************************************* 
	** Description: moveCharacters function moves the winner to the end
	**				of its queue and the loser to the front of the  loser 
	**				queue
	*********************************************************************/
	void moveCharacters(std::string);

	/********************************************************************* 
	** Description: playRound function plays one round of the game. Each
	**				round consists of the each character taking a turn
	**				to attack the other character.  If the damage kills
	**				the other character on either turn, the round will
	**				be over and false will be returned.
	*********************************************************************/
	bool playRound(Character*,Character*);

	/********************************************************************* 
	** Description: teamSetup function that setups up the teams that will
	**				be battling.
	*********************************************************************/
	void teamSetup();

	/********************************************************************* 
	** Description: characterSetup function sets up a character that
	**				will be battling.
	*********************************************************************/
	void characterSetup(Character*&);

	/********************************************************************* 
	** Description: createCharacter function creates attacker/defender
	**				for the current game being played.
	*********************************************************************/
	void createCharacter(int,Character*&);

	/********************************************************************* 
	** Description: randomNumGenerator function outputs a random number
	**				between specified low and high integers >= 0.
	*********************************************************************/
	int randomNumGenerator(int,int);

	/********************************************************************* 
	** Description: playGame function that runs the game.  It sets up
	**				the characters that will play, and then loops until
	**				a round is reached when a player dies.  It allows
	**				the user to either play again or exit the game.  Play
	**				again will ask the user for 2 new characters to battle.
	*********************************************************************/
	void playGame(int);

	/********************************************************************* 
	** Description: getInput function that prompts user for an integer
	**				input and validates the input.
	*********************************************************************/
	int getInput(std::string prompt);

	
public:
	/********************************************************************* 
	** Description: Constructor for the Game class. Takes menus as the 
	**				parameters.
	*********************************************************************/
	Game(Menu*,Menu*);

	/********************************************************************* 
	** Description: Destructor for the Game class.
	*********************************************************************/
	~Game();

	/********************************************************************* 
	** Description: playTournament function that runs the tournament.
	**				It sets up the teams from user inputs, battles the
	**				characters and outputs the results.  It gives an 
	**				option to see the losers.  
	*********************************************************************/
	void playTournament();

};

#endif