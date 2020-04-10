// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#ifndef POSITION_H
#define POSITION_H

#include <fstream>
using namespace std;

class PositionList{

private:

	struct Node{
	
		int row;
		int col;
		Node* next;
	
	};
	
	Node* tail;
	Node* head;
	unsigned int numOfElements;

public:
	//
	// PositionList
	//
	// Purpose: Initialize default values to tail, head, and numOfElements
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: tail, head, and NumOfElements have values assigned
	//
	PositionList();

	//
	// isEmpty
	//
	// Purpose: Checks if numOfElements in the PositionList is equal to 0
	// Parameter(s): N/A
	// Precondition(s): must agree with the invariant function
	// Return: True if numOfElements == 0 otherwise False
	// Side Effect: N/A
	//
	bool isEmpty() const;

	//
	// addToBack
	//
	// Purpose: adds a new Node onto the back of the Linked List with row and col values provided assigned to it
	// Parameter(s):
	// int row: row position to assign
	// int col: column position to assign
	//
	// Precondition(s): must agree with the invariant function
	// Return: N/A
	// Side Effect: new Node is created, and head and/or tail value is modified
	//
	void addToBack(int row, int col);

	//
	// debugPrint
	//
	// Purpose: Prints member variable values to the screen
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void debugPrint() const;

	//
	// getFrontRow
	//
	// Purpose: The head pointer variable's row is returned 
	// Parameter(s): N/A
	// Precondition(s): must agree with the invariant function and head can't equal nullptr
	// Return: In the first Node of the linked list, row is returned
	// Side Effect: N/A
	//
	int getFrontRow() const;

	//
	// getFrontCol
	//
	// Purpose: The head pointer variable's col is returned 
	// Parameter(s): N/A
	// Precondition(s): must agree with the invariant function and head can't equal nullptr
	// Return: In the first Node of the linked list, col is returned
	// Side Effect: N/A
	//
	int getFrontCol() const;

	//
	// removeFront
	//
	// Purpose: First Node in the linked list is removed
	// Parameter(s): N/A
	// Precondition(s): must agree with the invariant function
	// Return: N/A
	// Side Effect: head is set equal to the next node and tail is possibly set to nullptr
	//
	void removeFront();

	//
	// removeAll
	//
	// Purpose: LinkedList is deleted
	// Parameter(s): N/A
	// Precondition(s): must agree with the invariant function
	// Return: N/A
	// Side Effect: head and tail are set equal nullptr and all Nodes are deleted
	//
	void removeAll();

	//
	// PositionList
	//
	// Purpose: Copy one PositionList's values to another
	// Parameter(s):
	// const PositionList& original: PositionList to copy from
	//
	// Precondition(s): must agree with the invariant function
	// Return: N/A
	// Side Effect: The PositionList being created has it's values set to the PositonList passed in
	//
	PositionList(const PositionList& original);

	//
	// PositionList
	//
	// Purpose: Delete all member values
	// Parameter(s): N/A
	// Precondition(s): must agree with the invariant function
	// Return: N/A
	// Side Effect: All member values are deleted
	//
	~PositionList();

	//
	// operator=
	//
	// Purpose: Set one PositionList's values equal to another
	// Parameter(s):
	// const PositionList& original: PositionList to set equal to
	//
	// Precondition(s): must agree with the invariant function
	// Return: N/A
	// Side Effect: A PositionList has it's values set equal to the value on the right (original)
	//
	PositionList& operator= (const PositionList& original);

	//
	// getSize
	//
	// Purpose: The numOfElements member variable is returned
	// Parameter(s): N/A
	// Precondition(s): must agree with the invariant function
	// Return: numOfElements is returned
	// Side Effect: N/A
	//
	unsigned int getSize() const;

	//
	// save
	//
	// Purpose: Saves values from PositionList to a file
	// Parameter(s):
	// ifstream& game_out: file name to save to and open
	//
	// Precondition(s): must agree with the invariant function
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void save(ofstream& game_out) const;

	//
	// load
	//
	// Purpose: Loads in values from a file into PositionList member variables
	// Parameter(s):
	// ifstream& game_in: file name to load from and open
	//
	// Precondition(s): must agree with the invariant function and game_in must be a valid file name
	// Return: N/A
	// Side Effect: The PositionList member variables are initialized to the read in file values
	//
	virtual void load(ifstream& game_in);

private:

	//
	// invariant
	//
	// Purpose: Checks if the PositionList is either completely empty or has some values assigned to all member variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: True if PositionList is either completely empty or has some values assigned to all member variables otherwise False
	// Side Effect: N/A
	//
	bool invariant()const;

	//
	// copy
	//
	// Purpose: Copy one PositionList's values to another helper function for the class's other copy like functions
	// Parameter(s):
	// const PositionList& list2: PositionList to copy from
	//
	// Precondition(s): must agree with the invariant function
	// Return: N/A
	// Side Effect: The PositionList has it's values set to the PositonList passed in
	//
	void copy(const PositionList& list2);

};

#endif