// ==========================================
// Name: Matthew Hamilton
// Date: Mar.26,2016
// ==========================================

#include "Ride.h"

#ifndef HorizontalRide_H
#define HorizontalRide_H

class HorizontalRide:public Ride{

private:
	int moveDirection; //0 is left to right, 1 is right to left

public:
	//
	// HorizontalRide
	//
	// Purpose: Initialize default a value to the member variable
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The horizonal ride member variable is initialized to valid values
	//
	HorizontalRide();

	//
	// HorizontalRide
	//
	// Purpose: Copy one horizontal ride's values to another
	// Parameter(s):
	// const Ride& original: Horizontal ride to copy from
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The horizontal ride being created has its values changed to the original ride passed in
	//
	HorizontalRide(const HorizontalRide& original);

	//
	// ~HorizontalRide
	//
	// Purpose: Deletes any dynamically allocated variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: Dynamically allocated variables are deleted
	//
	~HorizontalRide(){};

	//
	// operator=
	//
	// Purpose: Set one Horizontal ride's values equal to another
	// Parameter(s):
	// const HorizontalRide& original:  Horizontal ride to set equal to
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The  Horizontal ride calling the function has its values changed to the original ride passed in
	//
	HorizontalRide& operator= (const HorizontalRide& original);

	//
	// getEntranceRow
	//
	// Purpose: Entrance row position of Horizontal ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Entrance row position of Horizontal Ride
	// Side Effect: N/A
	//
	virtual int getEntranceRow() const;

	//
	// getEntranceCol
	//
	// Purpose: Entrance column position of the Horizontal ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Entrance column position of Horizontal Ride
	// Side Effect: N/A
	//
	virtual int getEntranceCol() const;

	//
	// getExitRow
	//
	// Purpose: Exit row position of the Horizontal ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Exit row position of Horizontal Ride
	// Side Effect: N/A
	//
	virtual int getExitRow() const;

	//
	// getExitColumn
	//
	// Purpose: Exit column position of the of Horizontal ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Exit column position of Horizontal Ride
	// Side Effect: N/A
	//
	virtual int getExitCol() const;

	//
	// calculateMove
	//
	// Purpose: Determines which direction to move by increasing or decreasing the row and col position while in a horizontal ride
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
	// Purpose: Prints the Horizontal ride and ride member variable values to the screen
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void debugPrint() const;

	//
	// save
	//
	// Purpose: Saves values from Horizontal Ride and Ride member variables to a file
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
	// Purpose: Loads in values from a file into Horizontal Ride and Ride member variables
	// Parameter(s):
	// ifstream& game_in: file name to load from and open
	//
	// Precondition(s): game_in must be a valid file name
	// Return: N/A
	// Side Effect: The Horizontal Ride and Ride member variables are initialized to the read in file values
	//
	virtual void load(ifstream& game_in);

};

#endif