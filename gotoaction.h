// gotoaction.h

#ifndef GOTOACTION_H
#define GOTOACTION_H

#include "action.h"
#include "bank.h"
#include "player.h"
#include <string>

using namespace std;

class GoToAction : public Action {
private:
public:
	GoToAction();
	GoToAction(string, string, string, int);
	~GoToAction();
	void executeAction(Player*, Bank*);
};

#endif