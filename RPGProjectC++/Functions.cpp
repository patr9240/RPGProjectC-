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
		PrintPrisonPuzzleDesc();
		return 2;
	}
	else if (inputMaps.LocationMap.at(4) + 1 == inputMaps.GameMap.at(4)) {
		//boss battle
		PrintPrisonBossDesc();
		return 3;
	}
	else if (inputMaps.LocationMap.at(0) == 1 && element == 0) {
		//just entered the dungeon/whatever this place is
		PrintPrisonHallwayDesc();		
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
	cout << "In the Age of the Ancients the world\n was unformed, shrouded in mist.\n A land of grey crags, ancient trees and age old dragons.\n Then came the Flame, and with it disparity.\nHot and cold, life and death, and\n most importantly light and dark.\nFrom the darkness they came and they discovered\n the Great Lord Souls within the fire.\nNeeto, the Lord of Death, The Wizard of Ozalith\n and his sons of Chaos, and Guinevere the\nLady of Sunlight with her knights of the Sun.\n With the strength of the lords they challenged the dragons.\nGuinevere’s great bolts pierced their great scales.\n The wizards conjured mighty storms of fire.\nNeeto let loose death and disease across the land.\n The great dragon Seth the Scaleless,\n betrayed his own kin, and thus the dragons\n were no more. Then came the Age of the Flame.\n But soon the fire will fade and\n there will be only darkness. Among the\n living are seen carriers of the Darksigil." << endl;
}// end of PrintIntroDesc

//prints the Start descrtiption
void PrintStartDesc() {
	cout << "You awake from a deep slumber, not knowing who you are or\n where you came from. You look around and you see you’re in a cell.\n You see the door in front of you, is wide open.\n What do you do?\n";
}//end of PrintStartDesc

//-----------Halls---------------------
 //prints the PrisonHallway descrtiption ---- Perhaps make it a switch depending if we do different map locations?
void PrintPrisonHallwayDesc() {
	cout << "You see a long corridor, lined with more locked cell doors.\n";
}//end of PrintPrisonHallway

//-----------Rooms-----------------------
void PrintPrisonPuzzleDesc() {
	cout << "You enter into a large room with a small bonfire at\n its centre. As you look around you see everything is\n in ruins, walls crumbled over, wooden benches\n and chairs scattered and scattered all over.\n You can hear feint cries and moans off in the distance,\n but you are unable to decipher which direction\n they are coming from. You also see a large metal gate\n located on your right, centred in the wall.";
}//end of PrintPrisonPuzzleDesc

//---------Traps------------------------
//prints the SandwichWall description
void PrintSandwichWallsDesc() {
	cout << "As you are walking, you step on a pressure plate,\n then you hear and audible click from behind\n the walls as\n they start to move closer together\n and the doors at the ends of the hallway slam shut.\n You hear a demonic voice ask, 'What is the wind speed\n velocity of an unladen swallow?'";
}//end of SandwichWall

//prints the Pitfall description
void PrintPitfall() {
	cout << "As you are walking, you step on a pressure plate,\n the floor then falls out beneath you.\n You reach your hand out to grab onto the ledge...\n";
}//end of Pitfall

//prints the PoisonDarts description
void PrintPoisonDarts() {
	cout << "As you are walking, you activate a trip wire!\n The gate behind you slams down and then you\n see what appear to be darts shooting across\n the hallway in front of you, and systematically making\n their way towards you. You must make your way\n through it by rolling.";
}//end of PoisonDarts

//-----------Mob Encounters------------
 //prints the RandomEncounter description ---- again a switch case depending on their map location?
void PrintRandomEncounter() {
	cout << "As you were walking down the hallway,\n barely being able to see 10ft in front of you.\n You hear a loud groaning and hissing sound.\n Then you see a pair of glowing yellow eyes,\n piercing the darkness. Then the savage \n undead lunges at you and attacks....\n";
}//end of PrintRandomEncounter

// ----------Bosses -------------
 //prints the Boss Encounter description ---- switch again?
void PrintPrisonBossDesc() {
	cout << "You open the massive iron gates, hearing\n the hinges make loud groaning sound as the rust\n is disturbed after years of being unused.\n You see a great room with two levels to it,\n the top level only being a catwalk around\n the outside with cells all around it.\n The air smells of rotting eggs, and burnt\n flesh, you then feel as if the very warmth\n of you body has gone. You then see a\n great sythe fall from seemingly out of no where,\n and then a hand come through the floor\n and grasp it. Slowly you see more and more\n of the great beast. Snarling and shrouded\n in a great cloak that seemed to be made\n of darkness itself, it raises its great\n sythe and prepares to attack.\n";
}//end of PrintPrisonBossDesc