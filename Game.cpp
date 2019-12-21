/********************************************************************* 
** Program name: Game Class
** Author: Pavel Gordeyev
** Date: 11/17/19
** Description: Game.cpp is the Game class implementation file. It is
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
#include "Game.hpp"
#include "checkInput.hpp"

/********************************************************************* 
** Description: Constructor for the Game class. Takes menus as the 
**				parameters.
*********************************************************************/
Game::Game(Menu *startMenu, Menu *endMenu){

	this->startMenu = startMenu;
	this->endMenu = endMenu;

	this->sizeAlpha = -1;
	this->sizeBravo = -1;
	this->sizeLosers = -1;
	this->scoreAlpha = 0;
	this->scoreBravo = 0;

	this->attacker = nullptr;
	this->defender = nullptr;
	this->mediator = nullptr;

	this->teamAlpha = new CharQueue();
	this->teamBravo = new CharQueue();
	this->losers = new CharQueue();

}

/********************************************************************* 
** Description: playTournament function that runs the tournament.
**				It sets up the teams from user inputs, battles the
**				characters and outputs the results.  It gives an 
**				option to see the losers.  
*********************************************************************/
void Game::playTournament(){

	int endMenuResult,
		round = 1;

	std::string seeLosers;

	bool input;

	srand(time(NULL));

	do{	

		// Setup the teams
		this->teamSetup();

		// Print the tournament start
		std::cout << "\n---------------------------" << std::endl;
		std::cout << "Let the tournament begin!!!" << std::endl;
		std::cout << "---------------------------\n" << std::endl;

		// Print the teams
		std::cout << "On Team Alpha we have: ";
		this->teamAlpha->printQueue();

		std::cout << "On Team Bravo we have: ";
		this->teamBravo->printQueue();

		// Play game between the two front characters from 
		// Team Alpha and Team Bravo until one team has no more 
		// characters
		do{
			
			this->playGame(round);

			round++;

		}while(this->sizeAlpha > 0 && this->sizeBravo > 0);

		// Print the game results
		std::cout << "\n----------------------" << std::endl;
		std::cout << "TOURNAMENT IS OVER!!!!" << std::endl;
		std::cout << "----------------------\n" << std::endl;

		std::cout << "\nRESULTS" << std::endl;
		std::cout << "-------\n" << std::endl;

		std::cout << "Team Alpha SCORE: " << this->scoreAlpha 
		<< " points" << std::endl;
		std::cout << "\nTeam Bravo SCORE: " << this->scoreBravo 
		<< " points" << std::endl;

		std::cout << "\n******************" << std::endl;

		if(this->scoreAlpha > this->scoreBravo){
			std::cout << "Team Alpha WINS!!!" << std::endl;
		}else if(this->scoreAlpha < this->scoreBravo){
			std::cout << "Team Bravo WINS!!!" << std::endl;
		}else{
			std::cout << "IT'S A TIE!!!" << std::endl;
		}

		std::cout << "******************\n" << std::endl;

		// Ask if the user wants to see the losers; validate input
		do{
			input = false;

			std::cout << "\nWould you like to see the characters who lost? (Y/N)" 
			<< std::endl;
			std::cout << "> ";

			std::getline(std::cin,seeLosers);

			if(seeLosers == "y" or seeLosers == "Y"){
				input = true;
				std::cout << "\nThe losing characters were: ";
				this->losers->printQueue();
				std::cout << std::endl;
			}else if(seeLosers == "n" or seeLosers == "N"){
				input = true;
				std::cout << "\nOK. We won't show the losers... " << std::endl;
			}else{
				std::cout << "Not a valid choice!!" << std::endl;
			}
		}while(!input);

		// Show the end menu
		endMenuResult = this->endMenu->runMenu()[0];

		// Delete the last tournament's characters
		if(endMenuResult == 1){
			this->resetTournament();
		}

	}while(endMenuResult == 1);

}

/********************************************************************* 
** Description: resetTournament function removes all the characters
**				from Team Alpha, Team Bravo and losers to play the 
**				tournament again.
*********************************************************************/
void Game::resetTournament(){

	// Reset Team Alpha
	for(int i=0;i<this->sizeAlpha;i++){
		this->teamAlpha->removeFront(false);
	}

	// Reset Team Bravo
	for(int i=0;i<this->sizeBravo;i++){
		this->teamBravo->removeFront(false);
	}

	// Reset losers
	for(int i=0;i<this->sizeLosers;i++){
		this->losers->removeFront(false);
	}
}

/********************************************************************* 
** Description: playGame function that runs the game.  It sets up
**				the characters that will play, and then loops until
**				a round is reached when a player dies.  It allows
**				the user to either play again or exit the game.  Play
**				again will ask the user for 2 new characters to battle.
*********************************************************************/
void Game::playGame(int round){

	bool alive;

	srand(time(NULL));
	
	// Print the round information
	std::cout << "\nRound - " << round << std::endl;
	std::cout <<"-----------" << std::endl;
	std::cout << this->teamAlpha->getFront()->getName()
	<< "(" << this->teamAlpha->getFront()->getCharacterType() << ") vs "
	<< this->teamBravo->getFront()->getName() << "(" 
	<< this->teamBravo->getFront()->getCharacterType() << ")" << std::endl;

	// Loop until 1 of the characters die
	do{
		// Play round and check that both characters are alive
		// through the entire round
		alive = playRound(this->teamAlpha->getFront(),this->teamBravo->getFront());

	}while(alive);

}

/********************************************************************* 
** Description: playRound function plays one round of the game. Each
**				round consists of the each character taking a turn
**				to attack the other character.  If the damage kills
**				the other character on either turn, the round will
**				be over and false will be returned.
*********************************************************************/
bool Game::playRound(Character *alphaChar, Character *bravoChar){

	int turn = 1;

	// Randomly pick the first character to attack
	if(randomNumGenerator(1,100) <= 50){
		this->attacker = alphaChar;
		this->defender = bravoChar;
	}else{
		this->attacker = bravoChar;
		this->defender = alphaChar;
	}
	
	do{
		// Defender defends against attacker's attack
		this->defender->defend(this->attacker->doAttack());

		// If the defending character is alive and it is the first turn
		// of the round, swap the attacking and defending characters
		if(this->defender->getStrength() > 0){
			if(turn == 1){
				// Swap the defending & attacking characters
				this->mediator = this->attacker;
				this->attacker = this->defender;
				this->defender = this->mediator;
			}else{ // Set first attack character for next round
				if(randomNumGenerator(1,100) <= 50){
					// Swap the defending & attacking characters
					this->mediator = this->attacker;
					this->attacker = this->defender;
					this->defender = this->mediator;
				}else{
					// Keeps the attacker and defender the same as the
					// end of the previous round
				}
			}
		}else{
			// Output the winner
			std::cout << "..." << this->attacker->getName() << " WON!!\n"
			<< std::endl;

			// Check which team member won
			if(this->attacker == alphaChar){
				// Move characters; team bravo character to losers
				this->moveCharacters("alpha");
			}else{
				// Move characters; team alpha character to losers
				this->moveCharacters("bravo");
			}

			return false;
		}

		// Increment the turns
		turn++;

	}while(turn < 3);

	// No character died
	return true;
}

/********************************************************************* 
** Description: moveCharacters function moves the winner to the end
**				of its queue and the loser to the front of the  loser 
**				queue
*********************************************************************/
void Game::moveCharacters(std::string winner){

	Character *tempChar;

	if(winner == "alpha"){

		// Character recovery
		this->teamAlpha->getFront()->recover();

		// Move the head forward
		this->teamAlpha->moveHeadForward();

		// Temporarily save front of bravo team
		tempChar = this->teamBravo->getFront();

		// Move bravo team member to losers
		this->losers->addBack(tempChar);

		// Remove loser from front of its queue
		this->teamBravo->removeFront(true);

		// Adjust the size of team bravo
		this->sizeBravo--;

		// Add to the score of team alpha
		this->scoreAlpha++;

	}else{

		// Character recovery
		this->teamBravo->getFront()->recover();

		// Move the head forward
		this->teamBravo->moveHeadForward();

		// Temporarily save front of alpha team
		tempChar = this->teamAlpha->getFront();

		// Move alpha team member to losers
		this->losers->addBack(tempChar);

		// Remove loser from front of its queue
		this->teamAlpha->removeFront(true);

		// Adjust the size of team bravo
		this->sizeAlpha--;

		// Add to the score of team alpha
		this->scoreBravo++;
	}
	
}

/********************************************************************* 
** Description: getInput function that prompts user for an integer
**				input and validates the input.
*********************************************************************/
int Game::getInput(std::string prompt){

	// Initialize input string
	std::string errorStr = "Invalid input!\n",
		   str;
    bool input = false;

	// Ask user for a positive integer & validate input
	do{
		std::cout << "\n" << prompt << std::endl;
		std::cout << "> ";
		std::getline(std::cin,str);

		if(checkInputInt(str,false)){
			if(stoi(str) == 0){
				std::cout << "\nCannot have 0 characters!!!" << std::endl;
			}else{
				input = true;
				std::cout << "\n" << std::endl;
			}
		}else{ // Error message
			std::cout << errorStr << std::endl;
		}

	}while(!input);

	return stoi(str);
}

/********************************************************************* 
** Description: teamSetup function that setups up the teams that will
**				be battling.
*********************************************************************/
void Game::teamSetup(){

	std::cout << "\n*************************************" << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << "Let's setup Team Alpha" << std::endl;

	// Get the number of characters for first team
	this->sizeAlpha = this->getInput("Please enter # of characters for Team Alpha");

	// Loop through the number of characters the user wanted in Team Alpha
	for(int i=0;i<sizeAlpha;i++){

		Character *character;

		// Prompt user to pick Characer
		std::cout << "\nSelect Character # " << i + 1 
		<< " for team Alpha\n" << std::endl;

		// Display menu & setup character for first team
		this->characterSetup(character);

		// Add the character to character queue
		teamAlpha->addBack(character);

	}

	std::cout << "\n*************************************" << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << "Let's setup Team Bravo" << std::endl;

	// Get the number of characters for first team
	this->sizeBravo = this->getInput("Please enter # of characters for Team Bravo");

	// Loop through the number of characters the user wanted in Team Alpha
	for(int i=0;i<sizeBravo;i++){

		Character *character;

		// Prompt user to pick Characer
		std::cout << "\nSelect Character # " << i + 1 
		<< " for team Bravo\n" << std::endl;

		// Display menu & setup character for first team
		this->characterSetup(character);

		// Add the character to character queue
		teamBravo->addBack(character);

	}
}

/********************************************************************* 
** Description: characterSetup function sets up a character that
**				will be battling.
*********************************************************************/
void Game::characterSetup(Character *&character){

	int userInput;
	std::string name;

	// Show the menu with the characters and save result
	userInput = this->startMenu->runMenu()[0];

	// Create the character
	createCharacter(userInput,character);

	// Ask for the character's name
	std::cout << "\nGive the " << character->getCharacterType() 
	<< " a name" << std::endl;
	std::cout << "> ";

	std::getline(std::cin,name);

	// Assign the name to the character
	character->setName(name);
}

/********************************************************************* 
** Description: createCharacter function creates attacker/defender
**				for the current game being played.
*********************************************************************/
void Game::createCharacter(int option, Character *&character){

	switch(option){
		case 1:
			character = new Vampire();
			break;
		case 2:
			character = new Barbarian();
			break;
		case 3:
			character = new BlueMen();
			break;
		case 4:
			character = new Medusa();
			break;
		case 5:
			character = new HarryPotter();
			break;
		default:
			break;
	}
	
}

/********************************************************************* 
** Description: randomNumGenerator function outputs a random number
**				between specified low and high integers >= 0.
*********************************************************************/
int Game::randomNumGenerator(int low, int high){

	static int randInt;

	randInt = low + rand() % (high-low + 1);
	
	return randInt;
}

/********************************************************************* 
** Description: Destructor for the Game class.
*********************************************************************/
Game::~Game(){

	// Free memory
	delete teamAlpha;
	delete teamBravo;
	delete losers;
}