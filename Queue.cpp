/********************************************************************* 
** Program name: Queue Class
** Author: Pavel Gordeyev
** Date: 11/12/19
** Description: Queue.hpp is the Queue class specification file. The
**				Queue class contains a QueueNode structure.
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
** Description: addBack function adds a QueueNode object to the end
**				of the queue.
*********************************************************************/
void CharQueue::addBack(Character *character){

	// Add first node to the queue
	QueueNode *qn = new QueueNode();

	// Check if queue is empty
	if(this->isEmpty()){

		// Set the next and previous nodes to itself
		(*qn).next = qn;
		(*qn).prev = qn;

		// Point the head to the new node
		this->head = qn;

	}else{

		// New node's previous node is head's previous node
		(*qn).prev = (*this->head).prev;

		// Head's previous node's next node is the new node
		(*(*qn).prev).next = qn;

		// Point new node to current head node
		(*qn).next = this->head;

		// Head's new previous node is the new node
		(*this->head).prev = qn;
	}

	// Set to the specified value
	(*qn).val = val;
}

/********************************************************************* 
** Description: getFront function returns the value of the front node.
*********************************************************************/
int CharQueue::getFront(){

	// Check if the queue is not empty
	if(!this->isEmpty()){

		return (*head).val;

	}else{

		std::cout << "\nThe queue is empty!!!\n" << std::endl;
		return -1;

	}
}

/********************************************************************* 
** Description: removeFront node removes the front node from the queue
**				and adjusts to point to the new front node, if any.
*********************************************************************/
void CharQueue::removeFront(){

	// Check if queue is empty
	if(this->isEmpty()){

		std::cout << "\nThe queue is empty!!!\n" << std::endl;

	}else{

		QueueNode *nextNode = (*this->head).next,
				  *prevNode = (*this->head).prev;

		// Only 1 node exists
		if(this->head == nextNode){

			// Delete the node the head is pointing to
			delete this->head;

			// Point the head to null
			this->head = nullptr;

		}else{

			// Delete the node the head is pointing to
			delete this->head;

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
		
		std::cout << "\nThe queue is empty!!!\n" << std::endl;
	
	}else{

		// Create a pointer to the current node to print
		QueueNode *curNode = this->head;

		std::cout << "\nThe queue is: ";

		do{	
			// Print the value at the current node
			std::cout << (*curNode).val;

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
		removeFront();
	}

}