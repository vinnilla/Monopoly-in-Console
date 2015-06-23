//card.h
#ifndef CARD_H
#define CARD_H

#include "action.h"
//#include "player.h"
//#include "bank.h"
#include <string>
#include <iostream>

using namespace std;

class Card {
protected:
	Action action;
	int type; // 1=gain/lose money 2=gain/lose money from all players 3= car repairs 4=gotojail 5=get out of jail free 6=advance to go 7=gotospace 8=advance to utility 9=advance to bus 10=move spaces        
	int position;
	int value;

public:
	void populate(int, int, string, string, string, int, int, string, int);
	void print();
	void printAction();
	void retrieveActionLines(string*);
	int retrievePos();
	int retrieveType();
	int retrieveValue();
	Action retrieveAction();
	void changeAction(Action);
	void changePos(int);
	void changeType(int);
	void changeValue(int);
	//void execaction(Player*, Bank*);
};

#endif