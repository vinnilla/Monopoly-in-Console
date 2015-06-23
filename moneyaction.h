// moneyaction.h

#ifndef MONEYACTION_H
#define MONEYACTION_H

#include "player.h"
#include "bank.h"
#include "action.h"

using namespace std;

class MoneyAction : public Action {
private:
public:
	MoneyAction();
	MoneyAction(string, string, string, int);
	~MoneyAction();
	void executeAction(Player*, Bank*);
};

#endif