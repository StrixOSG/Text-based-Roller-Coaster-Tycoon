// ==========================================
// Name: Matthew Hamilton
// Date: Mar.26,2016
// ==========================================

#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Canvas.h"
#include "Game.h"
#include "HorizontalRide.h"
#include "CyclicRide.h"
#include "RollerCoaster.h"

using namespace std;

static const int GUEST_INITIAL_TIMER = 10;
static const int GUEST_INITIAL_HAPPINESS = 50;
static const int GUEST_RIDE_HAPPINESS = 5;


Game::Game(){

	rideCount = 0;
	guestCount = 0;

	for (int i = 0; i < MAX_RIDES; i++){

		ride1[i] = nullptr;

	}

}

void Game::load(const string& game_name){

	ifstream myInFile;
	int numRidesRead = 0;

	//InFile Initialization
	myInFile.open(game_name + ".txt");

	if (!myInFile){

		cout << game_name << ": Game file is not available" << endl;
		exit(1);

	}

	myInFile >> rideCount;

	if (!myInFile && (rideCount > 0) && (rideCount < MAX_RIDES)){

		cout << game_name << ": Invalid ride count" << endl;
		exit(1);

	}


	for (int i = 0; i < rideCount; i++){
		
		char rideLetter;
		myInFile >> rideLetter;

		if (rideLetter == 'h' || rideLetter == 'c' || rideLetter == 'r'){

			for (int j = 0; j < rideCount; j++){

				if (ride1[j] == nullptr){

					if (rideLetter == 'h'){

						ride1[j] = new HorizontalRide;
						ride1[j]->load(myInFile);
						break;

					}
					else if (rideLetter == 'c'){

						ride1[j] = new CyclicRide;
						ride1[j]->load(myInFile);
						break;

					}
					else if (rideLetter == 'r'){

						ride1[j] = new RollerCoaster;
						ride1[j]->load(myInFile);
						break;

					}

				}

				Canvas::isValidRideForCanvas(ride1[j]->getRowPos(), ride1[j]->getColPos(), ride1[j]->getRowSize(), ride1[j]->getColSize());

			}

			numRidesRead++;

		}
		else{
			myInFile.ignore(256,'\n');
		}

	

		if (!myInFile){

			cout << game_name << ": Problem reading ride " << i << endl;
			delete ride1[i];
			ride1[i] = nullptr;
			exit(1);

		}

	}

	rideCount = numRidesRead;

	myInFile >> guestCount;

	for (int i = 0; i < guestCount; i++){

		guest1[i].load(myInFile);

		if (!myInFile){

			cout << game_name << ": Problem reading guest " << i << endl;
			exit(1);

		}

	}

	myInFile.close();

	if (guestCount == 0)
	{

		do {

			cout << "Enter the number of guests (Between 1-500): ";
			cin >> guestCount;
			cout << endl;

		} while (guestCount < 1 || guestCount > 500);

		for (int i = 0; i < guestCount; i++){

			int rdmRow = rand() % (Canvas::CANVAS_ROWS - 1);
			int rdmCol = rand() % (Canvas::CANVAS_COLUMNS - 1);
			int rdmRide = rand() % rideCount;
			char rdmLetter;

			do {

				int tempNum = (int)'A' + (rand() % 57);
				rdmLetter = (char)tempNum;

			} while (((int)rdmLetter >= (int)'Z') && ((int)rdmLetter <= (int)'a'));

			guest1[i].init(rdmLetter, GUEST_INITIAL_HAPPINESS, rdmRow, rdmCol, rdmRide, false);
			guest1[i].debugPrint();

		}

	}

	myInFile.close();

	assert(invariant());

}

void Game::display(int game_time1)const{

	Canvas canvas1;
	canvas1.clear();

	for (int i = 0; i < rideCount; i++){

		canvas1.addRide(ride1[i]->getRowPos(), ride1[i]->getColPos(), ride1[i]->getRowSize(), ride1[i]->getColSize());
		canvas1.addTrack(ride1[i]->getRideTrack());

	}


	for (int i = 0; i < guestCount; i++){

		canvas1.addGuest(guest1[i].getRowPos(), guest1[i].getColPos(), guest1[i].getName());

	}

	canvas1.display();

	//debugPrint(); //Uncomment if debug is wanted

}

void Game::debugPrint()const{

	cout << "Guest Count: " << guestCount << endl;

	for (int i = 0; i < guestCount; i++){

		guest1[i].debugPrint();

	}

	cout << "Ride Count: " << rideCount << endl;

	for (int i = 0; i < rideCount; i++){

		ride1[i]->debugPrint();

	}

}

void Game::update(){

	totalTime++; //Every step is 1 second
	display(totalTime); //displays the game canvas and current game information

	for (int i = 0; i < guestCount; i++){

		int tempRide = guest1[i].getRideNum();

		//Arguements for isInside the ride function and ride time is greater than 0
		if (guest1[i].isOnRide()){

			guest1[i].changeHappiness(GUEST_RIDE_HAPPINESS);

			guest1[i].moveAlongRideTrack();

			if (!guest1[i].isOnRide()){

				int randomRide = (rand() % rideCount);
				guest1[i].reset(randomRide);

			}

		}
		else{

				guest1[i].changeHappiness(-1);

				//Guest Row Positon Change
				if (guest1[i].getRowPos() < ride1[tempRide]->getEntranceRow()){

					guest1[i].changeRowPos(1);

				}
				else if (guest1[i].getRowPos() > ride1[tempRide]->getEntranceRow()){

					guest1[i].changeRowPos(-1);

				}

				//Guest Column Positon Change
				if (guest1[i].getColPos() < ride1[tempRide]->getEntranceCol()){

					guest1[i].changeColPos(1);

				}
				else if (guest1[i].getColPos() > ride1[tempRide]->getEntranceCol()){

					guest1[i].changeColPos(-1);

				}

				if (ride1[tempRide]->isEntrance(guest1[i].getRowPos(), guest1[i].getColPos()) &&
					(isInside(guest1[i].getRowPos(), guest1[i].getColPos(), ride1[tempRide]->getRowPos(), ride1[tempRide]->getColPos(), ride1[tempRide]->getRowSize(), ride1[tempRide]->getColSize()))){

					guest1[i].setCurrentRideTrack(ride1[tempRide]->getRideTrack());

				}

			}

		}
	
	
	assert(invariant());

}


bool Game::isInside(

	int r, int c,
	int row_pos1, int col_pos1,
	int row_size1, int col_size1){

	bool rIsInside = false;
	bool cIsInside = false;

	for (int i = row_pos1; i < row_pos1 + row_size1; i++){

		if (r == i){

			rIsInside = true;

		}

	}

	for (int j = col_pos1; j < col_pos1 + col_size1; j++){

		if (c == j){

			cIsInside = true;

		}

	}

	if ((rIsInside == true) && (cIsInside == true)){

		return true;

	}
	else{

		return false;

	}

}

bool Game::invariant(){

	if (((guestCount > 0) && (guestCount < GUEST_MAX)) && ((rideCount > 0) && (rideCount <= MAX_RIDES))){
		return true;
	}
	else{
		return false;
	}


}

void Game::save(string game_name) const{

	ofstream game_out;
	game_out.open((game_name + ".txt"));

	game_out << rideCount << endl;

	for (int i = 0; i < rideCount; i++){

		ride1[i]->save(game_out);

	}

	game_out << guestCount << endl;

	for (int i = 0; i < guestCount; i++){

		guest1[i].save(game_out);

	}

	game_out.close();

}

Game::~Game(){

	for (int i = 0; i < MAX_RIDES; i++){
		
		if (ride1[i] != nullptr){
			
			delete ride1[i];

		}

	}

}