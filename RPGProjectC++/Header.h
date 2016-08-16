#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

/*
Author: Chad Ostler - D'Arcey Taylor - Patrick Ross - Ryan Jameson
Date: August 9, 2016.
Project 2
Professor: Matt Wilson
*/

using namespace std;

//Declare Type Definitions
typedef class Character CharacterType;

//menu prototypes
string SelectClass();
string SelectRace();
void PrintActionMenu();

//misc prototypes
int MoveEvent(struct EventMaps inputMaps);
CharacterType RandomEventAction(CharacterType playerChar);
int RandomEvent(CharacterType playerChar);
CharacterType EndOfActEvent(CharacterType playerChar);
void EndOfGame(CharacterType playerChar);
void PrintWinners();

//description prototypes
void PrintAct1Desc();
void PrintIntroDesc(CharacterType player);
void PrintAct2Desc();
void PrintAct3Desc();
void PrintAct4Desc();
void PrintAct5Desc();

//Declare Classes
class Class {
private:
	string ClassName;

public:
	string getClass() {
		return ClassName;
	}
	void setClass(string input) {
		ClassName = input;
	}
};

class Race {
private:
	string RaceName;

public:
	string getRace() {
		return RaceName;
	}
	void setRace(string input) {
		RaceName = input;
	}
};

//Character class
class Character {

private:
	string Name;
	int MaxHealth;
	int CurrHealth;
	int Humanity;

public:
	vector<int> CurrLocation;
	vector<int> CurrGameMap;
	Class CharClass;
	Race CharRace;
	//default constructor
	Character() {

	}

	Character(string Name) {
		setName(Name);
		setCurrHealth(150);
		setMaxHealth();
		setHumanity(2);
	};
	void health() {
	}//end of health

	 //Getters and setters
	string getName() {
		return Name;
	}//end of getName
	void setName(string Name) {
		this->Name = Name;
	}//end of SetName

	void setHumanity(int input) {
		this->Humanity = input;
	}
	int getHumanity() {
		return Humanity;
	}

	int getHealth() {
		return CurrHealth;
	}//end of getHealth

	void setCurrHealth(int Health) {
		CurrHealth = Health;
	}
	int getMaxHealth() {
		return MaxHealth;
	}
	void setMaxHealth() {
		MaxHealth = CurrHealth;
	}

	//this is hard to make sense of, moves the player basically
	void setLocation(vector<int> currentMap) {
		//if the currentLocation vector hasn't been initialized yet, create it
		if (CurrLocation.size() == 0) {
			for (int count = 0; count < 5; count++) {
				CurrLocation.push_back(0);
			}
		}
		//else everytime a move command is issued, "moves" the player through the map.
		else {
			//tracks current element index
			int element = 0;
			//catches CurrLocation element index up to the GameMap element index
			for (element = 0; CurrLocation.at(element) == currentMap.at(element); element++) {
			}
			//if the current location == the last spot on the GameMap, than it's the boss
			if(CurrLocation.at(4) + 1 == currentMap.at(4)) {
				
			}
			//if the value at the CurrLocation element index != the value of the gameMaps value at the current element index, increases CurrLocation's value
			else if (CurrLocation.at(element) != currentMap.at(element)) {
					CurrLocation.at(element)++;
				}
			
		}
	}//end of SetLocation function

};//end of Character class

//map structure
#pragma warning(disable:4244)
struct Map {
public:
	vector<int> map1;

	void createMap() {
		srand(time(NULL));
		for (int count = 0; count < 5; count++) {
			int randNum = rand() % 6 + 2;
			map1.push_back(randNum);
		}
	}
};//end of Map struct

//structure to hold the gamemap and currlocation map vectors
#pragma warning(default:4244)
struct EventMaps {
public:
	vector<int> LocationMap;
	vector<int> GameMap;

	void setCurrentLocationMap(vector<int> locationMap) {
		LocationMap = locationMap;
	}
	void setGameMap(vector<int> gameMap) {
		GameMap = gameMap;
	}
};//end of EventMaps