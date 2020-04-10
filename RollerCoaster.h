// ==========================================
// Name: Matthew Hamilton
// Date: Mar.26,2016
// ==========================================

#include "Ride.h"

#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

class RollerCoaster:public Ride{

private:
	PositionList rideTrack;

public:
	//
	// RollerCoaster
	//
	// Purpose: Initialize default values to the member variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The RollerCoaster Ride member variables are initialized to valid values
	//
	RollerCoaster();

	//
	// RollerCoaster
	//
	// Purpose: Copy one RollerCoaster Ride's values to another
	// Parameter(s):
	// const RollerCoaster& original: RollerCoaster Ride to copy from
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The RollerCoaster Ride being created has its values changed to the original ride passed in
	//
	RollerCoaster(const RollerCoaster& original);

	//
	// ~RollerCoaster
	//
	// Purpose: Deletes any dynamically allocated variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: Dynamically allocated variables are deleted
	//
	virtual ~RollerCoaster(){};

	//
	// operator=
	//
	// Purpose: Set one RollerCoaster Ride's values equal to another
	// Parameter(s):
	// const RollerCoaster& original: RollerCoaster ride to set equal to
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The RollerCoaster calling the function has its values changed to the original ride passed in
	//
	RollerCoaster& operator= (const RollerCoaster& original);

	//
	// getEntranceRow
	//
	// Purpose: Entrance row position of the RollerCoaster Ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Entrance row position of RollerCoaster
	// Side Effect: N/A
	//
	virtual int getEntranceRow() const;

	//
	// getEntranceCol
	//
	// Purpose: Entrance column position of the RollerCoaster Ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Entrance column position of RollerCoaster Ride
	// Side Effect: N/A
	//
	virtual int getEntranceCol() const;

	//
	// getExitRow
	//
	// Purpose: Exit row position of the RollerCoaster Ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Exit row position of RollerCoaster Ride
	// Side Effect: N/A
	//
	virtual int getExitRow() const;

	//
	// getExitColumn
	//
	// Purpose: Exit column position of the of RollerCoaster Ride is returned
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: Exit column position of RollerCoaster Ride
	// Side Effect: N/A
	//
	virtual int getExitCol() const;

	//
	// calculateMove
	//
	// Purpose: Outputs an error message if used
	// Parameter(s):
	// int row: row position to be modified 
	// int col: column position to be modified 
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void calculateMove(int& row, int& col) const;

	virtual PositionList getRideTrack() const;

	//
	// debugPrint
	//
	// Purpose: Prints the RollerCoaster Ride and Ride member variable values to the screen
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	virtual void debugPrint() const;

	//
	// save
	//
	// Purpose: Saves values from RollerCoaster Ride and Ride member variables to a file
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
	// Purpose: Loads in values from a file into RollerCoaster and Ride member variables
	// Parameter(s):
	// ifstream& game_in: file name to load from and open
	//
	// Precondition(s): game_in must be a valid file name
	// Return: N/A
	// Side Effect: The RollerCoaster Ride and Ride member variables are initialized to the read in file values
	//
	virtual void load(ifstream& game_in);

};

#endif