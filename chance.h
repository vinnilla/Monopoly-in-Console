// chance.h
#ifndef CHANCE_H
#define CHANCE_H

#include "card.h"
//#include "player.h"
//#include "bank.h"

using namespace std;

class Chance : public Card {
private:
	Card* deck;
	int numberofcards;
	int counter;

public:
	Chance();
	~Chance();
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