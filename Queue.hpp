/********************************************************************* 
** Program name: CharQueue Class
** Author: Pavel Gordeyev
** Date: 11/12/19
** Description: CharQueue.hpp is the Queue class specification file.
**				The CharQueue class contains a QueueNode structure.
*********************************************************************/
#ifndef CHARQUEUE_HPP
#define CHARQUEUE_HPP

/********************************************************************* 
** Description: QueueNode struct that contains the next, previous &
**				value of the node.
*********************************************************************/
struct CharNode{
	CharNode *next,
			 *prev;
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
	** Description: addBack function adds a QueueNode object to the end
	**				of the queue.
	*********************************************************************/
	void addBack(Character*);

	/********************************************************************* 
	** Description: getFront function returns the value of the front node.
	*********************************************************************/
	int getFront();

	/********************************************************************* 
	** Description: removeFront node removes the front node from the queue
	**				and adjusts to point to the new front node, if any.
	*********************************************************************/
	void removeFront();

	/********************************************************************* 
	** Description: printQueue function prints out the values in the 
	**				queue.
	*********************************************************************/
	void printQueue();

};

#endif