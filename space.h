// space.h
#ifndef SPACE_H
#define SPACE_H

//#include "player.h"
#include "action.h"
#include <string>

using namespace std;

class Space {
private:
	bool color;
	string nameBrand;
	string nameModel;
	int nextSpace;
	string pieces;
	char purchased; // 0=available for purchase 1=player1 2=player2 3=player3 4=player4
	int buyPrice;
	int rentPrice;
	int updatedRent;
	int sellPrice;
	int group; // 0=no group, 1=bus, 2=taxi, 3=mazda, 4=honda, 5=toyota, 6=mercedes, 7=audi, 8=bmw, 9=porsche, 10=maserati
	bool monopoly;
	int upgrade;
	int upgradePrice;
	bool mortgage;
	Action action;

public:
	void populate(bool, string, string, int, string, char, int, int, int, string, string, string, int, int, int);
	string removeSpaces(string);
	bool returnColor();
	string returnBrand();
	string returnModel();
	int returnBuy();
	char returnPurchased();
	int returnRent();
	string returnPieces();
	Action returnActionClass();
	void returnAction(string*);
	int returnGroup();
	int returnActionType();
	bool returnMonopoly();
	int returnUpgrade();
	int returnUpgradePrice();
	bool returnMortgage();
	void updateUpgrade();
	void UpgradetoFull();
	void modify(int);
	void updatePieces (int, char);
	void updateAction(int);
	void updateMonopoly(int);
	void updateMortgage();
	void reset();
	void realPrint(Space*, int);

};

#endif

	