// action.h
#ifndef ACTION_H
#define ACTION_H

//#include "player.h"
//#include "bank.h"
#include <string>

using namespace std;

class Action {
protected:
	string text[3];
	int status; //0=purchasable 1=purchased 2=blank 3=community 4=tax 5=gotojail 6=chance 7=taxi utility

public:
	//virtual void executeAction(Player*, Bank*) = 0;
	void populate(string, string, string, int);
	void retrieveAction(string*);
	int retrieveType();
	void ChangeStatus(int);
};

#endif