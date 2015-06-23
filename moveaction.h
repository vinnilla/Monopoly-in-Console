// moveaction.h

#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "player.h"
#include "bank.h"
#include "action.h"

using namespace std;

class MoveAction : public Action {
private:
public:
	MoveAction();
	MoveAction(string, string, string, int);
	~MoveAction();
	void executeAction(Player*, Bank*);
};

#endif