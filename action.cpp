//action.cpp

#include "action.h"
//#include "player.h"
//#include "bank.h"
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//void Action::executeAction(Player* player, Bank* bank) {}

void Action::populate(string text1, string text2, string text3, int type) {
	text[0] = text1;
	text[1] = text2;
	text[2] = text3;
	status = type;
}

void Action::retrieveAction(string Array[]) {
	Array[0] = text[0];
	Array[1] = text[1];
	Array[2] = text[2];
	return;
}

int Action::retrieveType() {
	return status;
}

void Action::ChangeStatus (int change) {
	status = change;
}
