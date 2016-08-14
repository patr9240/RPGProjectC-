#include <stdlib.h>
#include "Header.h"

/*
Author: Chad Ostler - D'Arcey Taylor - Patrick Ross - Ryan Jameson
Date: August 9, 2016.
Project 2
Professor: Matt Wilson
*/
#pragma warning(disable:4715)
//Class selection
string SelectClass() {
	
	//Variables
	string choice;

	//Player selects class
	do {
		cout << "Select your class... These have small flavour changes throughout your adventure. \n";
		cout << "1. Ranger \n";
		cout << "2. Blade Master \n";
		cout << "3. Illusionist \n";
		cout << "\nPlease select a number: \n";

		getline(cin, choice);

		//checks if user entered a digit
		if (all_of(choice.begin(), choice.end(), isdigit)) {

		}
		else {
			choice = "0";
		}
	} while (stoi(choice) < 1 || stoi(choice) > 3);
	switch (stoi(choice)) {
	case 1:
		return "Ranger";
		break;
	case 2:
		return "Blade Master";
		break;
	case 3:
		return "Illusionist";
		break;
	}//end of switch
}//end of SelectClass function

 //race Selection
string SelectRace() {
	string choice;

	
	//Player selects race
	do {
		cout << "Select your race... These give small benefits to your stats.\n";
		cout << "1. Human \n";
		cout << "2. Elf \n";
		cout << "3. Orc \n";
		cout << "4. Dwarf \n";
		cout << "\nPlease select a number: \n";

		getline(cin, choice);
		if (all_of(choice.begin(), choice.end(), isdigit)) {

		}
		else {
			choice = "0";
		}
	} while (stoi(choice) < 1 || stoi(choice) > 4);
	switch (stoi(choice)) {
	case 1:
		return "Human";
		break;
	case 2:
		return "Elf";
		break;
	case 3:
		return "Orc";
		break;
	case 4:
		return "Dwarf";
		break;
	}//end of switch
}//end of SelectRace function
#pragma warning(default:4715)

//prints main menu
void PrintActionMenu() {
	cout << "Action Menu \n";
	cout << "1. Move \n";
	cout << "2. View Health \n";
	cout << "3. View Humanity \n";
	cout << "4. Save \n";
	cout << "5. Quit \n";
	cout << "\nPlease select a number: \n";
}//end of PrintActionMenu function

//return values:
	//0 = Entered the dungeon thing
	//1 = continue down the hallway (random event idk)
	//2 = puzzle room! Fun event time!
	//3 = boss event
//starts event based on where player moved
int MoveEvent(EventMaps inputMaps) {
	int element = 0;
	//catches CurrLocation element index up to the GameMap element index
	for (element = 0; inputMaps.LocationMap.at(element) == inputMaps.GameMap.at(element); element++) {
	}
	if (inputMaps.LocationMap.at(element) == 1 && element != 0) {
		//in a puzzle room
		cout << "Puzzleroom! \n";
		return 2;
	}
	else if (inputMaps.LocationMap.at(4) + 1 == inputMaps.GameMap.at(4)) {
		//boss battle
		cout << "Boss fight! \n";
		return 3;
	}
	else if (inputMaps.LocationMap.at(0) == 1 && element == 0) {
		//just entered the dungeon/whatever this place is
		cout << "You walk through the door and enter into an earily lit hallway that has a sour smell to it \n";
		return 0;
	}
	else {
		cout << "You walk down the hallway, fretting what next surprise awaits \n";
		return 1;
	}
	return 0;
}//end of MoveEvent Function