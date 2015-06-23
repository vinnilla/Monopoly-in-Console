//space.cpp

#include "space.h"
#include "action.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void Space::populate(bool Color, string Brand, string Model, int Next, string Pieces, 
	char Purchased, int Buy, int Rent, int Sell, string line1, string line2, string line3, int type, int Group, int upPrice) { //essentially a constructor
	color = Color;
	nameBrand = Brand;
	nameModel = Model;
	nextSpace = Next;
	pieces = Pieces;
	purchased = Purchased;
	buyPrice = Buy;
	rentPrice = Rent;
	sellPrice = Sell;
	updatedRent = Rent;
	group = Group;
	monopoly = false;
	upgrade = 0;
	upgradePrice = upPrice;
	mortgage = false;
	action.populate(line1, line2, line3, type);
}

string Space::removeSpaces(string input) {
	size_t first = input.find_first_not_of(" ");
	size_t last = input.find_last_not_of(" ");
	size_t length = last - first;
	string buffer;
	if (first != 0 && last != 0) {
		buffer = input.substr(first, length+1);
		return buffer;		
	}

	else {
		return " ";
	}

}

bool Space::returnColor () {//access private variable outside of class
	return color;
}

string Space::returnBrand() {//access private variable outside of class
	return nameBrand;
}

string Space::returnModel() {//access private variable outside of class
	return nameModel;
}

int Space::returnBuy() {//access private variable outside of class
	return buyPrice;
}

char Space::returnPurchased() {//access private variable outside of class
	return purchased;
}

int Space::returnRent() {//access private variable outside of class
	return updatedRent;
}

string Space::returnPieces() {//access private variable outside of class
	return pieces;
}

Action Space::returnActionClass() {
	return action;
}

void Space::returnAction(string* Array) {
	action.retrieveAction(Array);
}

int Space::returnActionType() {
	return action.retrieveType();
}

int Space::returnGroup() {
	return group;
}

bool Space::returnMonopoly() {
	return monopoly;
}

int Space::returnUpgradePrice() {
	return upgradePrice;
}

int Space::returnUpgrade() {
	return upgrade;
}

bool Space::returnMortgage() {
	return mortgage;
}

void Space::updateUpgrade() {
	if (upgrade == 0) {
		updatedRent *= 2.5;
		upgrade++;
	}

	else if (upgrade == 1) {
		updatedRent *= 3;
		upgrade++;
	}

	else if (upgrade == 2) {
		updatedRent *= 10;
		upgrade++;
	}

	else if (upgrade == 3) {
		updatedRent *= 1.4;
		upgrade++;
	}

	else if (upgrade == 4) {
		updatedRent *= 1.2;
		upgrade++;
	}
}

void Space::UpgradetoFull() {
	upgrade = 6;
}

void Space::updatePieces(int Num, char Char){//update pieces string for the space the player landed on (or left)
	pieces.replace(Num, 1, 1, Char);
}

void Space::updateAction(int change) {
	action.ChangeStatus(change);
}

void Space::updateMonopoly(int number) {
	//cout << "IN UPDATE MONOPOLY\n";
	int temp = rentPrice;
	for (int i = 0; i < number; i++) {
		rentPrice *= 2;	
	}
	updatedRent = rentPrice;
	rentPrice = temp;
	monopoly = true;
}

void Space::updateMortgage() {
	if (mortgage == false) {
		mortgage = true;
	}

	else if (mortgage == true) {
		mortgage = false;
	}
}


void Space::modify(int change) {
	if (change == 1){
		purchased = '1';
	}

	else if (change == 2) {
		purchased = '2';
	}

	else if (change == 3) {
		purchased = '3';
	}
	
	else if (change == 4) {
		purchased = '4';
	}

} 

void Space::reset(){
	purchased = '0';
	updatedRent = rentPrice;
	monopoly = false;
	upgrade = 0;
	mortgage = false;
}

void Space::realPrint(Space* spaces, int player) {
	char compare;
	int counter = 0;
	stringstream ss;
	ss << player;
	ss >> compare;
	for (int i = 0; i < 40; i++) {
		if (spaces[i].purchased == compare) {
			counter++;
			cout << counter << ". " << left << setw(20) << removeSpaces(spaces[i].nameBrand) + " " + removeSpaces(spaces[i].nameModel) << "  $" << spaces[i].buyPrice << endl;
		}
	}
}