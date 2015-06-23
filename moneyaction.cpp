// moneyaction.cpp

#include "moneyaction.h"
#include <string>

using namespace std;

MoneyAction::MoneyAction() {}

MoneyAction::MoneyAction(string a1, string a2, string a3, int change) {
	text[0] = a1;
	text[1] = a2;
	text[2] = a3;
	status = change;

}

MoneyAction::~MoneyAction() {}

void MoneyAction::executeAction(Player* player, Bank* bank) {
	cout << "Community Chest Card: " << text[0] << ". " << text[1] << "\n" << text[2] << endl;
	player->addMoney(status);
	bank->deductFunds(status);

}