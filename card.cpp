//card,cpp

#include "card.h"
#include "action.h"
//#include "gotoaction.h"
//#include "moveaction.h"
//#include "moneyaction.h"
#include <iostream>

using namespace std;

void Card::populate(int Type, int pos, string Action1, string Action2, string Action3, int status, int change, string actionType, int actionChange) {
	/*if (actionType == "gotoaction") {
		action = new GoToAction(Action1, Action2, Action3, actionChange);
	}

	else if (actionType == "moveaction") {
		action = new MoveAction(Action1, Action2, Action3, actionChange);
	}

	else if (actionType == "moneyaction") {
		action = new MoneyAction(Action1, Action2, Action3, actionChange);
	}*/

	position = pos;
	type = Type;
	value = change;
	action.populate(Action1, Action2, Action3, status);
	return;
}

void Card::print() {
	string Action[3];
	retrieveActionLines(Action);
	if (action.retrieveType() == 3) {
		cout << "Community Chest Card: " << Action[0] << ". " << Action[1] << endl;
	}
	else if (action.retrieveType() == 6) {
		cout << "Chance Card: " << Action[0] << ". " << Action[1] << endl;	
	}
}

void Card::printAction() {
	string Action[3];
	retrieveActionLines(Action);
	cout << Action[2] << endl;
}

void Card::retrieveActionLines(string* array) {
	action.retrieveAction(array);
}

int Card::retrievePos() {
	return position;
}

int Card::retrieveType() {
	return type;
}

int Card::retrieveValue() {
	return value;
}

Action Card::retrieveAction() {
	return action;
}

void Card::changeAction (Action change) {
	action = change;
}

void Card::changePos(int change) {
	position = change;
}

void Card::changeType(int change) {
	type = change;
}

void Card::changeValue(int change) {
	value = change;
}

/*void Card::execaction(Player* player, Bank* bank) {
	action->executeAction(player, bank);
}*/

