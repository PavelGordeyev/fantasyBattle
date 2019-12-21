/********************************************************************* 
** Program name: CharQueue Class
** Author: Pavel Gordeyev
** Date: 11/17/19
** Description: CharQueue.hpp is the CharQueue class specification 
**				file. The CharQueue class contains a CharNode 
**				structure.
*********************************************************************/
#ifndef CHARQUEUE_HPP
#define CHARQUEUE_HPP

#include "Character.hpp"

/********************************************************************* 
** Description: QueueNode struct that contains the next, previous &
**				value of the node.
*********************************************************************/
struct CharNode{
	CharNode *next,
			 *prev;
	Character *character;
};

class CharQueue{

private:
	CharNode *head;

	/********************************************************************* 
	** Description: isEmpty function checks if the queue is empty. Returns
	**				true if it is empty and false otherwise.
	*********************************************************************/
	bool isEmpty();

public:
	/********************************************************************* 
	** Description: Constructor for the Queue class.
	*********************************************************************/
	CharQueue();

	/********************************************************************* 
	** Description: Destructor for the Queue class.
	*********************************************************************/
	~CharQueue();

	/********************************************************************* 
	** Description: addBack function adds a CharNode object to the end
	**				of the queue.
	*********************************************************************/
	void addBack(Character*&);

	/********************************************************************* 
	** Description: getFront function returns the value of the front node.
	*********************************************************************/
	Character * getFront();

	/********************************************************************* 
	** Description: moveHeadForward function moves the head forward to 
	**				next node.
	*********************************************************************/
	void moveHeadForward();

	/********************************************************************* 
	** Description: removeFront node removes the front node from the queue
	**				and adjusts to point to the new front node, if any.
	*********************************************************************/
	void removeFront(bool);

	/********************************************************************* 
	** Description: printQueue function prints out the values in the 
	**				queue.
	*********************************************************************/
	void printQueue();

};

#endif