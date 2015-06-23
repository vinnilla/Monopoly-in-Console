// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player {
private:
	char character;
	int playerNum;
	int currentSpace;
	int previousSpace;
	int money;
	int ownedProperty[40];
	int jail; //0=free 1=in custody
	int jailCounter;
	int jailFree;
	bool dead;

public:
	Player(char, int, int, int, int, int, int, int, int);
	~Player();
	int returnSpace();
	int returnSpace2();
	char returnChar();
	int returnNum();
	bool updateInfo(int);
	bool updateMovement(int);
	void updateProperty(int);
	void updateJail(int);
	void updateJailcounter();
	void updateJailfree(int);
	int retrieveCounter();
	int retrieveWealth();
	int retrieveJail();
	int retrieveProperty(int);
	int retrieveJailfree();
	bool retrieveDead();
	void updateDead();
	void deductMoney(int);
	void addMoney(int);
	void print();
	void realPrint();
};

#endif