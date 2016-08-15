#include <stdlib.h>
#include "Header.h"

/*
Author: Chad Ostler - D'Arcey Taylor - Patrick Ross - Ryan Jameson
Date: August 9, 2016.
Project 2
Professor: Matt Wilson
*/

//Global Variable
vector<int> eventTracker;

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
		cout << "		Act " << element + 1 << "\n";
		//in a puzzle room
		return 2;
	}
	else if (inputMaps.LocationMap.at(4) + 1 == inputMaps.GameMap.at(4)) {
		//boss battle
		return 3;
	}
	else if (inputMaps.LocationMap.at(0) == 1 && element == 0) {
		//just entered the dungeon/whatever this place is
		return 0;
	}
	else {
		//walked normally
		return 1;
	}
	return 0;
}//end of MoveEvent Function

 //prints the Intro Description
void PrintIntroDesc(CharacterType player) {
	cout << "In the Age of the Ancients the world \nwas unformed, shrouded in mist. \nA land of grey crags, ancient trees and age old dragons. \nThen came the Flame, and with it disparity. \nHot and cold, life and death, and \nmost importantly light and dark. \nFrom the darkness they came and they discovered \nthe Great Lord Souls within the fire. \nNeeto, the Lord of Death, The Wizard of Ozalith \nand his sons of Chaos, and Guinevere the \nLady of Sunlight with her Knights of the Sun. \nWith the strength of the lords they challenged the dragons. \nGuinevere’s great bolts pierced their great scales. \nThe wizards conjured mighty storms of fire. \nNeeto let loose death and disease across the land. \nThe great dragon Seth the Scaleless, \nbetrayed his own kin, and thus the dragons \nwere no more. Then came the Age of the Flame. \nBut soon the fire will fade and \nthere will be only darkness. Among the \nliving is the carrier of the Darksigil, \na " << player.CharRace.getRace() << " " << player.CharClass.getClass() << " called " << player.getName() << ".\n\n\n";
}// end of PrintIntroDesc

 //prints the Start descrtiption
void PrintStartDesc() {
	cout << "		Act 1\n" << "You awake from a deep slumber, not knowing who you are or \nwhere you came from. You look around and you see you’re in a cell. \nYou see the door in front of you is wide open. \nPeering out the open door, You see a long \ndimly lit corridor, lined with more locked cell doors.\n\n\n";
}//end of PrintStartDesc

 //Starts a random event, affects players character based on result code returned from RandomEvent
CharacterType RandomEventAction(CharacterType playerChar) {

	int eventResult;
	eventResult = RandomEvent(playerChar);
	switch (eventResult) {
		//1 = Lose 1 humanity, return to beginning of current act IF your current humanity is > 0, else you lose the game.
		case 1:
			if (playerChar.getHumanity() > 0) {
				playerChar.setHumanity(playerChar.getHumanity() - 1);
				int element;
				//catches CurrLocation element index up to the GameMap element index
				for (element = 0; playerChar.CurrLocation.at(element) == playerChar.CurrGameMap.at(element); element++) {
					
				}
				if (playerChar.CurrLocation.at(element) == 0) {
					element = element - 1;
				}
				playerChar.CurrLocation.at(element) = 1;
				cout << "You have died, luckily you still have some humanity \nleft in you, " << playerChar.getName() << ". I will start you at the beginning of Act " << element +1 << ". \nDon't fail again, or else you may not be so lucky next time.\n";
			}
			else {
				cout << "You have died on your last Humanity " << playerChar.getName() << ", \nthe " << playerChar.CharRace.getRace() << " " << playerChar.CharClass.getClass() << ". \nYou have failed your adventure, leaving the world to succumb to its fate. \n";
				playerChar.setHumanity(-1);
			}
			break;
		//2 = lose 20 hp, continue on your way IF your current health > 21, else Lose 1 humanity, return to beginning of current act IF your current humanity is > 0, else you lose the game.
		case 2:
			if (playerChar.getHealth() < 21) {
				if (playerChar.getHumanity() > 0) {
					playerChar.setHumanity(playerChar.getHumanity() - 1);
					int element;
					//catches CurrLocation element index up to the GameMap element index
					for (element = 0; playerChar.CurrLocation.at(element) == playerChar.CurrGameMap.at(element); element++) {

					}
					if (playerChar.CurrLocation.at(element) == 0) {
						element = element - 1;
					}
					playerChar.CurrLocation.at(element) = 1;
					cout << "You have died, luckily you still have some humanity \nleft in you, " << playerChar.getName() << ". I will start you at the beginning of Act " << element - 1 << ". \nDon't fail again, or else you may not be so lucky next time.\n";
				}
				else {
					cout << "You have died on your last Humanity " << playerChar.getName() << ", \nthe " << playerChar.CharRace.getRace() << " " << playerChar.CharClass.getClass() << ". \nYou have failed your adventure, leaving the world to succumb to its fate. \n";
					playerChar.setHumanity(-1);
				}
			}
			else {
				playerChar.setCurrHealth(playerChar.getHealth() - 20);
				cout << "You have taken minor damage\n";
			}
			break;
		//3 = lose 40 hp, continue on your way IF your current health > 41, else Lose 1 humanity, return to beginning of current act IF your current humanity is > 0, else you lose the game.
		case 3:
			if (playerChar.getHealth() < 41) {
				if (playerChar.getHumanity() > 0) {
					playerChar.setHumanity(playerChar.getHumanity() - 1);
					int element;
					//catches CurrLocation element index up to the GameMap element index
					for (element = 0; playerChar.CurrLocation.at(element) == playerChar.CurrGameMap.at(element); element++) {

					}
					if (playerChar.CurrLocation.at(element) == 0) {
						element = element - 1;
					}
					playerChar.CurrLocation.at(element) = 1;
					cout << "You have died, luckily you still have some humanity \nleft in you, " << playerChar.getName() << ". I will start you at the beginning of Act " << element + 1 << ". \nDon't fail again, or else you may not be so lucky next time.\n";
				}
				else {
					cout << "You have died on your last Humanity " << playerChar.getName() << ", \nthe " << playerChar.CharRace.getRace() << " " << playerChar.CharClass.getClass() << ". \nYou have failed your adventure, leaving the world to succumb to its fate. \n";
					playerChar.setHumanity(-1);
				}
			}
			else {
				playerChar.setCurrHealth(playerChar.getHealth() - 40);
				cout << "You have taken moderate damage\n";
			}
			break;
		//4 = lose 60 hp, continue on your way IF your current health > 61, else Lose 1 humanity, return to beginning of current act IF your current humanity is > 0, else you lose the game.
		case 4:
			if (playerChar.getHealth() < 61) {
				if (playerChar.getHumanity() > 0) {
					playerChar.setHumanity(playerChar.getHumanity() - 1);
					int element;
					//catches CurrLocation element index up to the GameMap element index
					for (element = 0; playerChar.CurrLocation.at(element) == playerChar.CurrGameMap.at(element); element++) {

					}
					if (playerChar.CurrLocation.at(element) == 0) {
						element = element - 1;
					}
					playerChar.CurrLocation.at(element) = 1;
					cout << "You have died, luckily you still have some humanity \nleft in you, " << playerChar.getName() << ". I will start you at the beginning of Act " << element + 1 << ". \nDon't fail again, or else you may not be so lucky next time.\n";
				}
				else {
					cout << "You have died on your last Humanity " << playerChar.getName() << ", \nthe " << playerChar.CharRace.getRace() << " " << playerChar.CharClass.getClass() << ". \nYou have failed your adventure, leaving the world to succumb to its fate. \n";
					playerChar.setHumanity(-1);
				}
			}
			else {
				playerChar.setCurrHealth(playerChar.getHealth() - 60);
				cout << "You have taken severe damage\n";
			}
			break;
		//5 = No effect on character, continue on your way.
		case 5:
			break;
		//6 = lose 50% of current hp, continue on your way IF your current health > 1, else Lose 1 humanity, return to beginning of current act IF your current humanity is > 0, else you lose the game.
		case 6:
			if (playerChar.getHealth() < 1) {
				if (playerChar.getHumanity() > 0) {
					playerChar.setHumanity(playerChar.getHumanity() - 1);
					int element;
					//catches CurrLocation element index up to the GameMap element index
					for (element = 0; playerChar.CurrLocation.at(element) == playerChar.CurrGameMap.at(element); element++) {
					}
					if (playerChar.CurrLocation.at(element) == 0) {
						element = element - 1;
					}
					playerChar.CurrLocation.at(element) = 1;
					cout << "You have died, luckily you still have some humanity \nleft in you, " << playerChar.getName() << ". I will start you at the beginning of Act " << element + 1 << ". \nDon't fail again, or else you may not be so lucky next time.\n";
				}
				else {
					cout << "You have died on your last Humanity " << playerChar.getName() << ", \nthe " << playerChar.CharRace.getRace() << " " << playerChar.CharClass.getClass() << ". \nYou have failed your adventure, leaving the world to succumb to its fate. \n";
					playerChar.setHumanity(-1);
				}
			}
			else {
				playerChar.setCurrHealth(playerChar.getHealth() / 2);
				cout << "You are at half of your previous strength\n";
			}
			break;
		//7 = gain 1 humanity, continue on your way.
		case 7:
			playerChar.setHumanity(playerChar.getHumanity() + 1);
			cout << "You gain 1 humanity for out smarting the foul demon in your path.\n";
			break;
	}
	//returns any changes to the players character to main
	return playerChar;
}

#pragma warning(disable:4244)
#pragma warning(disable:4018)
//random event is going to commence an event, returns the result code to RandomEventAction 
int RandomEvent(CharacterType playerChar) {
	//variables
	srand(time(NULL));
	bool randNumLoop;
	int randEvent;
	int randNum;
	string choice;

	//while false, generates a new number until it hits an unused event, if left true then uses that number for the next event
	do {
		randNumLoop = true;
		//random number generator to pick event
		randEvent = rand() % 5 + 1;
			for (int count = 0; count < eventTracker.size(); count++) {
				if (randEvent == eventTracker.at(count)) {
					randNumLoop = false;
				}
			}
	} while (!randNumLoop);
	
	//adds the event case number to the event tracker vector
	eventTracker.push_back(randEvent);
	//if all event cases have been used, reset eventTracker vector
	if (eventTracker.size() == 4) {
		eventTracker.clear();
	}
	//switch case to determine which event to run
	switch (randEvent) {
		//case 1: spike trap
	case 1:
		cout << "As you are walking, you step on a pressure plate, \nthe floor then falls out beneath you. \nYou reach your hand out to grab onto the ledge...\n";
		system("PAUSE");
		cout << "\n";
		randNum = rand() % 100 + 1;
		if (randNum > 80) {
			cout << "Your hand slips off the ledge, causing you to plunge into the pit below. \nYou are impaled on sharpened sticks that were \ndug into the ground long ago, leaving your \nmangled " << playerChar.CharRace.getRace() << " body to rot in the depths of the pit for eternity... \n";
			system("PAUSE");
			cout << "\n";
			return 1;
		}
		else {
			cout << "Your hand grasps the ledge of the pit with all of your strength, \nallowing you to crawl to safety to continue your adventure...\n";
			system("PAUSE");
			cout << "\n";
			return 5;
		}
		break;
		//case 2: walk sandwich
	case 2:
		cout << "As you are walking, you hear thunderous laughter \nechoing through the dungeon. You also notice the walls \nstart to move closer together, and the doors at \nthe ends of the hallway slam shut...\n";
		system("PAUSE");
		cout << "\n";
		cout << " A booming demonic voice rings through your ears, \n'What is the wind speed velocity of an unladen swallow?'\n";
		system("PAUSE");
		cout << "\n";

		//Player selects answer
		do {
			cout << "Multiple Choice Answer \n";
			cout << "1. 24 miles per hour. \n";
			cout << "2. African or European swallow? \n";
			cout << "3. What is a unladen swallow? \n";
			cout << "4. 19 miles per hour. \n";
			cout << "\nPlease select a number: \n";
			cin >> choice;

			//checks if user entered a digit
			if (all_of(choice.begin(), choice.end(), isdigit)) {
			}
			else {
				choice = "0";
			}
		} while (stoi(choice) < 1 || stoi(choice) > 4);

		if (stoi(choice) == 2) {
			cout << "The demon looks around confused, \n'What? hmmm... uhm, I don't know what that mea-' \nBefore the demon is able to finish his thought, he explodes into a gory mess \nall around you. The walls stop in their place, and you hear a \nsharp boom as the doors on either end of the hallway fly open.\n";
			system("PAUSE");
			cout << "\n";
			return 7;
		}
		else {
			cout << "'Fool!' The demon shouts as he dematerializes. \nYou can still hear his laughter echo through the hallway as your \nsoft " << playerChar.CharRace.getRace() << " body flattens between the unstoppable walls. \n";
			system("PAUSE");
			cout << "\n";
			return 1;
		}
		break;
		//case 3: dart trap
	case 3:
		cout << "As you are walking, you activate a trip wire!\n The gate behind you slams down and then you\n see what appear to be darts shooting across\n the hallway in front of you, and systematically making\n their way towards you. You must make your way through it by rolling. \n";
		system("PAUSE");
		cout << "\n";

		randNum = rand() % 100 + 1;
		if (randNum <= 20) {
			cout << "You make it through the volley of darts unscathed... \n";
			system("PAUSE");
			cout << "\n";
			return 5;
		}
		else if (randNum > 20 && randNum <= 35) {
			cout << "You make it through the volley of darts, only getting hit by one... \n";
			system("PAUSE");
			cout << "\n";
			return 2;
		}
		else if (randNum > 35 && randNum <= 75) {
			cout << "You make it through the hallway, with two darts stuck in you... \n";
			system("PAUSE");
			cout << "\n";
			return 3;
		}
		else {
			cout << "You barely make it through, getting hit by 3 darts... \n";
			system("PAUSE");
			cout << "\n";
			return 4;
		}
		break;
		//case 4: 
	case 4:

		break;
		//case 5: 
	case 5:
		break;
	}
	return 0;
}
#pragma warning(default:4244)
#pragma warning(default:4018)


/*
 //-----------Rooms-----------------------
void PrintPrisonPuzzleDesc() {
	cout << "You enter into a large room with a small bonfire at\n its centre. As you look around you see everything is\n in ruins, walls crumbled over, wooden benches\n and chairs scattered and scattered all over.\n You can hear feint cries and moans off in the distance,\n but you are unable to decipher which direction\n they are coming from. You also see a large metal gate\n located on your right, centred in the wall.";
}//end of PrintPrisonPuzzleDesc

 // ----------Bosses -------------
 //prints the Boss Encounter description ---- switch again?
void PrintPrisonBossDesc() {
	cout << "You open the massive iron gates, hearing\n the hinges make loud groaning sound as the rust\n is disturbed after years of being unused.\n You see a great room with two levels to it,\n the top level only being a catwalk around\n the outside with cells all around it.\n The air smells of rotting eggs, and burnt\n flesh, you then feel as if the very warmth\n of you body has gone. You then see a\n great sythe fall from seemingly out of no where,\n and then a hand come through the floor\n and grasp it. Slowly you see more and more\n of the great beast. Snarling and shrouded\n in a great cloak that seemed to be made\n of darkness itself, it raises its great\n sythe and prepares to attack.\n";
}//end of PrintPrisonBossDesc

*/