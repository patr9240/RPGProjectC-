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
		PrintBossEncounter();
		return 3;
	}
	else if (inputMaps.LocationMap.at(0) == 1 && element == 0) {
		//just entered the dungeon/whatever this place is
		PrintPrisonHallway();
		return 0;
	}
	else {
		cout << "You walk down the hallway, fretting what next surprise awaits \n";
		return 1;
	}
	return 0;
}//end of MoveEvent Function

//prints the Intro Description
void PrintIntroDesc() {
	cout << "In the Age of the Ancients the world\n was unformed, shrouded in mist.\n A land of grey crags, ancient trees and age old dragons.\n Then came the Flame, and with it disparity.\nHot and cold, life and death, and\n most importantly light and dark.\nFrom the darkness they came and they discovered\n the Great Lord Souls within the fire.\nNeeto, the Lord of Death, The Wizard of Ozalith\n and his sons of Chaos, and Guinevere the\nLady of Sunlight with her knights of the Sun.\n With the strength of the lords they challenged the dragons.\nGuinevere�s great bolts pierced their great scales.\n The wizards conjured mighty storms of fire.\nNeeto let loose death and disease across the land.\n The great dragon Seth the Scaleless,\n betrayed his own kin, and thus the dragons\n were no more. Then came the Age of the Flame.\n But soon the fire will fade and\n there will be only darkness. Among the\n living are seen carriers of the Darksigil." << endl;
}// end of the Intro Description

//prints the Start descrtiption
void PrintStart() {
	cout << "You awake from a deep slumber, not knowing who you are or\n where you came from. You look around and you see you�re in a cell.\n You see the door in front of you, is wide open.\n What do you do?\n";
}//end of PrintStart

 //prints the PrisonHallway descrtiption ---- Perhaps make it a switch depending if we do different map locations?
void PrintPrisonHallway() {
	cout << "You see a long corridor, lined with more locked cell doors.\n";
}//end of PrintPrisonHallway()

 //prints the RandomEncounter description ---- again a switch case depending on their map location?
void PrintRandomEncounter() {
	cout << "As you were walking down the hallway,\n barely being able to see 10ft in front of you.\n You hear a loud groaning and hissing sound.\n Then you see a pair of glowing yellow eyes,\n piercing the darkness. Then the savage \n undead lunges at you and attacks....\n";
}//end of PrintRandomEncounter()

 //prints the BossEncounter description ---- switch again?
void PrintBossEncounter() {
	cout << "You open the massive iron gates, hearing\n the hinges make loud groaning sound as the rust\n is disturbed after years of being unused.\n You see a great room with two levels to it,\n the top level only being a catwalk around\n the outside with cells all around it.\n The air smells of rotting eggs, and burnt\n flesh, you then feel as if the very warmth\n of you body has gone. You then see a\n great sythe fall from seemingly out of no where,\n and then a hand come through the floor\n and grasp it. Slowly you see more and more\n of the great beast. Snarling and shrouded\n in a great cloak that seemed to be made\n of darkness itself, it raises its great\n sythe and prepares to attack.\n";
}//end of PrintBossEncounter()