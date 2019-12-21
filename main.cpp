/********************************************************************* 
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Pavel Gordeyev
** Date: 11/19/19
** Description: main.cpp is the main function implementation file for
**              Project 4 - Fantasy Combat Tournament. It is a fantasy 
**				combat game, that contains Vampire, Barbarian, Blue
**				Men, Medusa, and Harry Potter. 
**				Each character has attributes of attack, defense, 
**				armor, and strength points.  Two characters battle
**				for each match, and alternate attacking within the
**				rounds.  It asks user for 2 teams to battle each
**				other, and outputs which team won or if it was a draw.  
*********************************************************************/
#include "Game.hpp"
#include "Menu.hpp"
#include <string>
#include <iostream>

using std::string;

int main(){

	int startMenuSize = 2,
		charMenuSize = 5,
		endMenuSize = 2,
		validOption1 = 1,
		validOption2 = 2,
		validOption3 = 3,
		validOption4 = 4,
		validOption5 = 5;

	//**********************//
	//      START MENU      //
	//**********************//

	// End options menu
	string *startMenuItems = new string[startMenuSize];
	startMenuItems[0] = "1 - Play Fantasy tournament";
	startMenuItems[1] = "2 - Exit";

	// End of day options menu valid user selections
	int *vInputsStart= new int[startMenuSize];
	vInputsStart[0] = validOption1;
	vInputsStart[1] = validOption2;

	//**************************//
	//  CHARACTER OPTIONS MENU  //
	//**************************//

	// Start options menu items
	string *charMenuItems = new string[charMenuSize];
	charMenuItems[0] = "1 - Vampire";
	charMenuItems[1] = "2 - Barbarian";
	charMenuItems[2] = "3 - Blue Men";
	charMenuItems[3] = "4 - Medusa";
	charMenuItems[4] = "5 - Harry Potter";

	// Options menu valid user option selections
	int *vInputsChar = new int[charMenuSize];
	vInputsChar[0] = validOption1;
	vInputsChar[1] = validOption2;
	vInputsChar[2] = validOption3;
	vInputsChar[3] = validOption4;
	vInputsChar[4] = validOption5;

	//**********************//
	//      END MENU        //
	//**********************//

	// End options menu
	string *endMenuItems = new string[endMenuSize];
	endMenuItems[0] = "1 - Play Again";
	endMenuItems[1] = "2 - Exit";

	// End of day options menu valid user selections
	int *vInputsEnd = new int[endMenuSize];
	vInputsEnd[0] = validOption1;
	vInputsEnd[1] = validOption2;

	//**********************//
	//      Play game       //
	//**********************//

	// Create the menus
	Menu *startMenu = new Menu(startMenuItems,nullptr,vInputsStart,startMenuSize,OPTIONS);
	Menu *charMenu = new Menu(charMenuItems,nullptr,vInputsChar,charMenuSize,OPTIONS);
	Menu *endMenu = new Menu(endMenuItems,nullptr,vInputsEnd,endMenuSize,OPTIONS);

	// Create new game
	Game *game = new Game(charMenu,endMenu);

	// Check if user wants to play the game
	if(startMenu->runMenu()[0] == 1){

		game->playTournament();
	}

	//**********************//
	//     Free Memory      //
	//**********************//
	delete game;
	delete startMenu;
	delete charMenu;
	delete endMenu;
	delete [] startMenuItems;
	delete [] vInputsStart;
	delete [] charMenuItems;
	delete [] vInputsChar;
	delete [] endMenuItems;
	delete [] vInputsEnd;

	return 0;
}