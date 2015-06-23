// community.h
#ifndef COMMUNITY_H
#define COMMUNITY_H

#include "card.h"
//#include "player.h"
//#include "bank.h"

using namespace std;

class Community : public Card {
private:
	Card* deck;
	int numberofcards;
	int counter;

public:
	Community();
	~Community();
	void updateNum(int);
	void shuffle();
	void reArrange();
	int returnType();
	int returnValue();
	void print();
	void printDeck();
	int returnNum();
	//void execaction(Player*, Bank*);
};

#endif