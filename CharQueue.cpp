/********************************************************************* 
** Program name: CharQueue Class
** Author: Pavel Gordeyev
** Date: 11/17/19
** Description: CharQueue.cpp is the CharQueue class implementation
**				file. The CharQueue class contains a CharNode 
**				structure.
*********************************************************************/
#include "CharQueue.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the Queue class.
*********************************************************************/
CharQueue::CharQueue(){
	head = nullptr;
}

/********************************************************************* 
** Description: isEmpty function checks if the queue is empty. Returns
**				true if it is empty and false otherwise.
*********************************************************************/
bool CharQueue::isEmpty(){

	// Check if the head points to null
	if(this->head){
		return false;
	}

	// Queue is empty
	return true;
}

/********************************************************************* 
** Description: addBack function adds a CharNode object to the end
**				of the queue.
*********************************************************************/
void CharQueue::addBack(Character *&character){

	// Add first node to the queue
	CharNode *cn = new CharNode();

	(*cn).character = character;

	// Check if queue is empty
	if(this->isEmpty()){

		// Set the next and previous nodes to itself
		(*cn).next = cn;
		(*cn).prev = cn;

		// Point the head to the new node
		this->head = cn;

	}else{

		// New node's previous node is head's previous node
		(*cn).prev = (*this->head).prev;

		// Head's previous node's next node is the new node
		(*(*cn).prev).next = cn;

		// Point new node to current head node
		(*cn).next = this->head;

		// Head's new previous node is the new node
		(*this->head).prev = cn;
	}
}

/********************************************************************* 
** Description: getFront function returns the value of the front node.
*********************************************************************/
Character * CharQueue::getFront(){

	return (*this->head).character;
}

/********************************************************************* 
** Description: moveHeadForward function moves the head forward to 
**				next node.
*********************************************************************/
void CharQueue::moveHeadForward(){

	if(this->isEmpty()){

	}else{
		this->head = (*this->head).next;
	}
}

/********************************************************************* 
** Description: removeFront node removes the front node from the queue
**				and adjusts to point to the new front node, if any.
*********************************************************************/
void CharQueue::removeFront(bool moving){

	// Check if queue is empty
	if(this->isEmpty()){

	}else{

		CharNode *nextNode = (*this->head).next,
				  *prevNode = (*this->head).prev;

		if(!moving){
			// Delete the character in the node
			delete (*this->head).character;
		}
			
		// Delete the node the head is pointing to
		delete this->head;

		// Only 1 node exists
		if(this->head == nextNode){

			// Point the head to null
			this->head = nullptr;

		}else{

			// Point the head to the next node from the old head node
			this->head = nextNode;

			// Reset the previous node of the new head node
			(*this->head).prev = prevNode;

			// Point the next node of the old head node's previous node
			(*prevNode).next = nextNode;
		}
	}
}

/********************************************************************* 
** Description: printQueue function prints out the values in the 
**				queue.
*********************************************************************/
void CharQueue::printQueue(){

	// Check if queue is empty
	if(this->isEmpty()){
		
		std::cout << "\nNo one on the team!!!\n" << std::endl;
	
	}else{

		// Create a pointer to the current node to print
		CharNode *curNode = this->head;

		do{	
			// Print the value at the current node
			std::cout << (*curNode).character->getName();

			// Spacing
			std::cout << " ";

			// Set the current node to the next node
			curNode = (*curNode).next;

		}while(curNode != this->head);


		// End the line
		std::cout << "\n" << std::endl;

	}
}

/********************************************************************* 
** Description: Destructor for the Queue class.
*********************************************************************/
CharQueue::~CharQueue(){

	// Free memory by removing all nodes using the removeFront method
	while(this->head){
		removeFront(false);
	}

}