// ==========================================
// Name: Matthew Hamilton
// Date: Apr.7,2016
// ==========================================

#include "Ride.h"

#ifndef CyclicRide_H
#define CyclicRide_H

class CyclicRide:public Ride{

private:
	int entranceRowPos;
	int entranceColPos;
	int exitRowPos;
	int exitColPos;

public:
	//
	// CyclicRide
	//
	// Purpose: Initialize default values to the member variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The Cyclic Ride member variables are initialized to valid values
	//
	CyclicRide();

	//
	// CyclicRide
	//
	// Purpose: Copy one Cyclic Ride's values to another
	// Parameter(s):
	// const Ride& original: Cyclic Ride to copy from
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The Cyclic Ride being created has its values changed to the original ride passed in
	//
	CyclicRide(const CyclicRide& original);

	//
	// ~CyclicRide
	//
	// Purpose: Deletes any dynamically allocated variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: Dynamically allocated variables are deleted
	//
	~CyclicRide(){};

	//
	// operator=
	//
	// Purpose: Set one Cyclic Ride's values equal to another
	// Parameter(s):
	// const CyclicRide& original:  Horizontal ride to set equal to
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The  Cyclic Ride calling the function has its values changed to the original ride passed in
	//
	CyclicRide& operator= (const CyclicRide& original);

	//
	// getEntranceRow
	//
	// Purpose: Entrance row position of the Cyclic Ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Entrance row position of Cyclic Ride
	// Side Effect: N/A
	//
	virtual int getEntranceRow() const;

	//
	// getEntranceCol
	//
	// Purpose: Entrance column position of the Cyclic Ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Entrance column position of Cyclic Ride
	// Side Effect: N/A
	//
	virtual int getEntranceCol() const;

	//
	// getExitRow
	//
	// Purpose: Exit row position of the Cyclic Ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Exit row position of Cyclic Ride
	// Side Effect: N/A
	//
	virtual int getExitRow() const;

	//
	// getExitColumn
	//
	// Purpose: Exit column position of the of Cyclic Ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Exit column position of Cyclic Ride
	// Side Effect: N/A
	//
	virtual int getExitCol() const;

	//
	// calculateMove
	//
	// Purpose: Determines which direction to move by increasing or decreasing the row and col position while in a cyclic ride
	// Parameter(s):
	// int row: row position to be modified 
	// int col: column position to be modified 
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: row and col are either added or subtracted to by one
	//
	virtual void calculateMove(int& row, int& col) const;

	//
	// debugPrint
	//
	// Purpose: Prints the Cyclic Ride and Ride member variable values to the screen
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void debugPrint() const;

	//
	// save
	//
	// Purpose: Saves values from Cyclic Ride and Ride member variables to a file
	// Parameter(s):
	// ifstream& game_out: file name to save to and open
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void save(ofstream& game_out) const;

	//
	// load
	//
	// Purpose: Loads in values from a file into Cyclic Ride and Ride member variables
	// Parameter(s):
	// ifstream& game_in: file name to load from and open
	//
	// Precondition(s): game_in must be a valid file name
	// Return: N/A
	// Side Effect: The Cyclic Ride and Ride member variables are initialized to the read in file values
	//
	virtual void load(ifstream& game_in);

};

#endif