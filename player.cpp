//player.cpp

#include "player.h"
#include <iostream>

using namespace std;

Player::Player(char symbol, int number, int space, int space2, int wealth, int properties, int crime, int crimeCounter, int Free) {
	//fill the player class with the appropriate information
	character = symbol;
	playerNum = number;
	currentSpace = space;
	previousSpace = space2;
	money = wealth;
	for (int i = 0; i < 40; i++){ //this array keeps track of which properties are owned and which aren't. 0 means that the property is not owned 
	//and 1 means that it is.
		ownedProperty[i] = properties;
	}
	jail = crime; //the jail variables help implement the jail action
	jailCounter = crimeCounter;
	jailFree = Free;
	dead = false;
	return;
}

Player::~Player() {
}

int Player::returnSpace() {
	return currentSpace;//private variable is accessed
}

int Player::returnSpace2() {
	return previousSpace;//private variable is accessed
}

char Player::returnChar() {
	return character;//private variable is accessed
}

int Player::returnNum() {
	return playerNum;//private variable is accessed
}

int Player::retrieveWealth() {
	return money;//private variable is accessed
}

int Player::retrieveJail(){
	return jail;//private variable is accessed
}

int Player::retrieveCounter(){
	return jailCounter;//private variable is accessed
}

int Player::retrieveProperty(int counter) {
	return ownedProperty[counter];//private variable is accessed
}

int Player::retrieveJailfree() {
	return jailFree;
}

bool Player::retrieveDead() {
	return dead;
}

void Player::updateDead() {
	character = ' ';
	dead = true;
}

bool Player::updateInfo(int moves) { //replaces previousSpace with currentSpace and updates currentSpace by adding the number of moves
	previousSpace = currentSpace;
	currentSpace = (currentSpace+moves)%40;
	if (previousSpace > currentSpace) {
		return true;
	}
	else {
		return false;
	}

}

bool Player::updateMovement(int position) {
	previousSpace = currentSpace;
	currentSpace = position;
	if (previousSpace > currentSpace) {
		return true;
	}

	return false;
}

void Player::deductMoney(int change) { //substracts change from money
	money -= change;
}

void Player::addMoney(int change) { //add change to money
	money += change;
}

void Player::print() { //useful function to output information to check if changes were made correctly
	cout << character << " " << playerNum << " " << currentSpace << " " << previousSpace << " " << money << " ";
	for (int i = 0; i < 40; i++){
		cout << ownedProperty[i];
	}
	cout << endl;
}

void Player::updateProperty(int space) { //update the ownedProperty array as property is acquired or lost
	if (ownedProperty[space] == 0) {
		ownedProperty[space] = 1;	
	}
	else {
		ownedProperty[space] = 0;
	}
}

void Player::updateJail(int status) { //updates jail variable to reflect whether play is in jail
	jail = status;
	if (status == 0) {
		jailCounter = 0;
	}
}

void Player::updateJailcounter(){ //counts how many rounds the player has been in jail for
	jailCounter++;
}

void Player::updateJailfree(int change) { //updates variable when jail free card is gained or lost
	jailFree = change;
}

void Player::realPrint() { //print statistics for gameplay 
	cout << "\nPlayer " << playerNum << ", your statistics are:" << endl;
	cout << "Token: " << character << "\t";
	cout << "Money: " << money << "\n";
	cout << "Owned Cars: \n";
}