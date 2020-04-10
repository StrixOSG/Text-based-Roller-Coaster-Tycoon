// ==========================================
// Name: Matthew Hamilton
// Date: Mar.26,2016
// ==========================================
#include <string>
#include "Guest.h"
#include "Ride.h"
using namespace std;

#ifndef GAME_H
#define GAME_H

class Game{

public:
	static const int GUEST_MAX = 500;
	static const int MAX_RIDES = 20;

private:
	int guestCount;
	int rideCount;
	Ride *ride1[MAX_RIDES];
	Guest guest1[GUEST_MAX];
	int totalTime;

public:
	//
	// Game
	//
	// Purpose: Initialize default values to member variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: rideCount and guestCount are intialized to 0
	//
	Game();

	//
	// load
	//
	// Purpose: Load in values from a file for member variables
	// Parameter(s): 
	// const string& game_name: name of the file to load from
	//
	// Precondition(s): game_name must be a valid file name
	// Return: N/A
	// Side Effect: member variables except totalTime are changed to the values loaded from the file
	//
	void load(const string& game_name);

	//
	// display
	//
	// Purpose: Displays the current canvas to the user
	// Parameter(s):
	// int game_time: current time in seconds the game has been running for
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: Canvas is cleared and has rides and guests added to it
	//
	void display(int game_time)const;

	//
	// update
	//
	// Purpose: Updates guests once every step
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: guest1[] values are updated
	//
	void update();

	//
	// invariant
	//
	// Purpose: Ensures guest and ride count are greater than 0 and less than or equal to their max values
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: True if guest and ride count values are proper otherwise False
	// Side Effect: N/A
	//
	bool invariant();

	//
	// save
	//
	// Purpose: saves Game member variable values to a file name chosen by the user
	// Parameter(s): 
	// string game_name: name of the file to create and/or save to
	//
	// Precondition(s): game_name must a value
	// Return: N/A
	// Side Effect: N/A
	//
	void save(string game_name) const;

	//
	// debugPrint
	//
	// Purpose: Displays detailed information about the rides and guests and the total amount of them
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: N/A
	//
	void debugPrint() const;

	//
	// ~Game
	//
	// Purpose: Deletes any dynamically allocated variables
	// Parameter(s): N/A
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: Dynamically allocated variables are deleted
	//
	~Game();

private:
	//
	// isInside
	//
	// Purpose: checks if the position given is inside a ride (position and size) 
	// Parameter(s): 
	// int r: row position to check if inside ride
	// int c: column position to check if inside ride
	// int row_pos1: ride row position
	// int col_pos1: ride column position
	// int row_size1: ride row size
	// int col_size1: ride column size
	//
	// Precondition(s): integer values must be assigned and ride values for position and size within canvas boundaries
	// Return: True if position is inside the ride otherwise False
	// Side Effect: N/A
	//
	bool isInside(int r, int c, int row_pos1, int col_pos1, int row_size1, int col_size1);

	//
	// Game
	//
	// Purpose: Copy one Game's values to another
	// Parameter(s):
	// const Ride& game2: Game to copy from
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The Game being created has its values changed to the original Game passed in
	//
	Game(const Game& game2);

	//
	// operator=
	//
	// Purpose: Set one Game's values equal to another
	// Parameter(s):
	// const HorizontalRide& original: Game to set equal to
	//
	// Precondition(s): N/A
	// Return: N/A
	// Side Effect: The Game calling the function has its values changed to the original Game passed in
	//
	Game& operator=(const Game& game2);

};

#endif