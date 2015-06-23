//gameboard.h
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "space.h"
#include "player.h"
#include "action.h"
#include "bank.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Game_Board : public Space {
private:
	Space* allSpaces;

public:
	Game_Board();
	Game_Board(int); 
	~Game_Board();
	int counterIncrement(int, int, int);
	string removeSpaces(string);
	void updateUpdate(Player*, Bank*);
	void updatePieces (int, int, int, char);
	void updateSpaces (vector<Player>, int);
	void updateAction(int, int);
	void updateMonopoly();
	void updateBuses();
	void updateMortgage(int, Player*, Bank*);
	void unMortgage(Player*, Bank*);
	void mortgage(Player*, Bank*);
	Action retrieveActionClass(int);
	string retrieveActionLines(int);
	char retrievePurchased(int);
	int retrieveBuy(int);
	int retrieveRent(int);
	int retrieveNumberofUpgrades(Player);
	bool retrieveMonopoly(int);
	int retrieveMortgage(int);
	void modifySpace(int, int);
	void resetSpace(int);
	void printStats(Player);
	void outputRow(int, int);
	void outputColumn(int, int, bool);
	void print_Board();
	
};

#endif