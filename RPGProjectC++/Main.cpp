#include <stdlib.h>
#include "Header.h"

/*
Author: Chad Ostler - D'Arcey Taylor - Patrick Ross - Ryan Jameson
Date: August 9, 2016.
Project 2
Professor: Matt Wilson
*/

int main() {
	//variables
	bool quit = false;
	string input;
	string choice;
	Map gameMap;
	EventMaps maps;
	//creates games map
	gameMap.createMap();
	//sends game map to map collection strut
	maps.setGameMap(gameMap.map1);
	//creates character name
	cout << "Welcome! What shall we call you?\n";
	getline(cin, input);
	Character Player(input);
	//sets characters race
	Player.CharRace.setRace(SelectRace());
	//sets character class
	Player.CharClass.setClass(SelectClass());
	//creates map
	Player.setLocation(gameMap.map1);
		//Buffs stats according to players race choice (these are unknown to the player at the moment)
		if (Player.CharRace.getRace() == "Human") {
			Player.setHumanity(Player.getHumanity() + 1);
		}
		else if (Player.CharRace.getRace() == "Elf") {
			Player.setHumanity(Player.getHumanity() + 2);
		}
		else if (Player.CharRace.getRace() == "Orc") {
			Player.setCurrHealth(Player.getHealth() + 50);
			Player.setMaxHealth();
		}
		else if (Player.CharRace.getRace() == "Dwarf") {
			Player.setCurrHealth(Player.getHealth() + 30);
			Player.setMaxHealth();
		}
		//prints the intro story
		PrintIntroDesc(Player);
		system("PAUSE");

		//loops actionsmenu until the player wins or quits
	while (!quit) {
		int MoveEventReturn = 0;
		//Player selects action from menu
		do {
			PrintActionMenu();
			cin >> choice;

			//checks if user entered a digit
			if (all_of(choice.begin(), choice.end(), isdigit)) {
			}
			else {
				choice = "0";
			}
		} while (stoi(choice) < 1 || stoi(choice) > 5);

		//switch selects player selected menu action
		switch (stoi(choice)) {
			//move player
		case 1:
			//moves player
			Player.setLocation(gameMap.map1);
			//sends updated map to structure
			maps.setCurrentLocationMap(Player.CurrLocation);
			//chooses event base on location and chance
			MoveEventReturn = MoveEvent(maps);

			//triggers function based on where player moved in the map
			switch (MoveEventReturn) {
			//case 0 = first entered the game
				case 0:
					PrintStartDesc();
					system("PAUSE");
					break;
			//1 = continue down the hallway
				case 1:
					//starts random event
					Player = RandomEventAction(Player);
					system("PAUSE");
					break;
			//2 = puzzle room! Fun event time!
				case 2:
					cout << "2 \n";
					system("PAUSE");
					break;
			//3 = boss event
				case 3:
					system("PAUSE");
					break;
			}//end switch
			break;

			//view hp
		case 2:
			cout << "Health: " << Player.getHealth() << "/" << Player.getMaxHealth() << "\n" ;
			break;
		case 3:
			cout << "Humanity left: " << Player.getHumanity() << "\n";
			//save
		case 4:
			break;
			//quit
		case 5:
			quit = true;
			break;
		}//end of switch

	}//end of while
	
	system("PAUSE");
	return 0;

}//end of main

