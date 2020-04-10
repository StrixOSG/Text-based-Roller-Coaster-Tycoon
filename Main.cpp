// ==========================================
// Name: Matthew Hamilton
// Course: CS115-001
// Course#: 10666
// LabSection: 095
// Date: Mar.26,2016
// ==========================================
// Purpose: Refactor code in the Canvas, Ride, HorizontalRide and CyclicRide to use linked lists.
// Gain an understanding of how to use linked lists.
// ==========================================

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>	 //includes time for srand
#include <unistd.h>  //If on windows instead of linux use <windows.h> || on linux use <unistd.h>
#include "Game.h"
#include "PositionList.h"

using namespace std;

void waitTime(double time_in_seconds);

int main(){
	
	string playerName;
	string gameName;
	int numOfSteps;
	Game game;

	srand((unsigned int) time(NULL));

	cout << "Enter a username: ";
	cin >> playerName;
	cout << endl;
	cout << "Enter a name for the game: ";
	cin >> gameName;
	cout << endl;

	game.load(gameName); //Loads information about the rides from the textfile tycoon.txt

	cout << "Enter the amount of steps you want to move: ";
	cin >> numOfSteps;
	cout << endl;

	//Runs the main sequence for the amount of steps entered
	for (int i = 0; i < numOfSteps; i++){
		game.update();
		waitTime(1.0);

	}

	cout << "Game name: " << gameName << endl;
	cout << "Enter name for save: ";
	cin >> gameName;
	game.save(gameName);


	return 0;
}

void waitTime(double time_in_seconds){

	usleep(time_in_seconds * 1000000); //If on windows instead of linux use Sleep(time_in_seconds*1000); || on linux use usleep(time_in_seconds * 1000000);

}

